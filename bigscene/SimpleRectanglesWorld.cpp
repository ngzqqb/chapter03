#include "SimpleRectanglesWorld.hpp"

namespace sstd{

    SimpleRectanglesWorld::SimpleRectanglesWorld(){
        connect ( &thisScene,&QGraphicsScene::changed,
                  this,&SimpleRectanglesWorld::changed );
    }

    void SimpleRectanglesWorld::updateViewWidth(int arg){
        if( thisCurrentViewPort.width () == arg){
            return;
        }
        this->updateViewPort( thisCurrentViewPort.x(),
                              thisCurrentViewPort.y(),
                              arg,
                              thisCurrentViewPort.height());
    }

    void SimpleRectanglesWorld::updateViewHeight(int arg){
        if( thisCurrentViewPort.height () == arg){
            return;
        }
        this->updateViewPort( thisCurrentViewPort.x(),
                              thisCurrentViewPort.y(),
                              thisCurrentViewPort.width (),
                              arg);
    }

    void SimpleRectanglesWorld::updateViewX(int arg){
        if( thisCurrentViewPort.x () == arg){
            return;
        }
        this->updateViewPort( arg,
                              thisCurrentViewPort.y(),
                              thisCurrentViewPort.width (),
                              thisCurrentViewPort.height());
    }

    void SimpleRectanglesWorld::updateViewY(int arg){
        if( thisCurrentViewPort.y () == arg){
            return;
        }
        this->updateViewPort( thisCurrentViewPort.x(),
                              arg,
                              thisCurrentViewPort.width (),
                              thisCurrentViewPort.height());
    }

    void SimpleRectanglesWorld::updateViewPort(int argX,
                                               int argY,
                                               int argWidth,
                                               int argHeight){

        QRect varTargetRect{ argX,argY,argWidth,argHeight };

        {
            auto varRectNotUpdate = varTargetRect.intersected( thisCurrentViewPort );
            if(varRectNotUpdate.isEmpty ()){/*全部改变*/
                thisCurrentViewPort = varTargetRect;
                thisRegionNotReDraw.reset ();
                thisScene.invalidate (thisCurrentViewPort);
                return;
            }
        }

        {/*部分改变*/
            QRegion varRegin{  varTargetRect   };
            varRegin -= thisCurrentViewPort ;
            if(thisRegionNotReDraw){
                (*thisRegionNotReDraw) &= varTargetRect;
            }
            for( const auto & varI : varRegin ){
                thisScene.invalidate ( varI );
            }
        }

        thisCurrentViewPort = varTargetRect;
    }

    void SimpleRectanglesWorld::paint(QPainter *painter){
        auto varAboutToDraw = std::move(thisRegionNotReDraw);
        if(thisLastDraw.size () !=  thisCurrentViewPort.size() ){
            thisLastDraw = QImage(thisCurrentViewPort.size(),QImage::Format_RGBA8888_Premultiplied);
            QPainter varPainter{ &thisLastDraw };
            thisScene.render (&varPainter,
                              QRectF(0,0,
                                     thisCurrentViewPort.width (),
                                     thisCurrentViewPort.height ())/*target*/,
                              thisCurrentViewPort/*source*/);
            painter->drawImage (0,0,thisLastDraw);
            return;
        }

        QPainter varPainter{ &thisLastDraw };
        if( varAboutToDraw ) {
            for( const auto & varI : std::as_const(*varAboutToDraw) ){
                thisScene.render (&varPainter,
                                  QRectF(varI.x() - thisCurrentViewPort.x(),
                                         varI.y() - thisCurrentViewPort.y(),
                                         varI.width (),
                                         varI.height ())/*target*/,
                                  varI/*source*/);
            }
            painter->drawImage (0,0,thisLastDraw);
        }else{
            painter->drawImage (0,0,thisLastDraw);
        }

    }

    void SimpleRectanglesWorld::changed(const QList<QRectF> &region){
        if( !thisRegionNotReDraw ){
            thisRegionNotReDraw = sstd_make_shared<QRegion>();
        }
        for( const auto & varI : region ){
            (*thisRegionNotReDraw) |= varI.toRect ();
        }
        this->update (  );
    }


}/*namespace sstd*/

inline static void registerThis(){

}
Q_COREAPP_STARTUP_FUNCTION(registerThis)










