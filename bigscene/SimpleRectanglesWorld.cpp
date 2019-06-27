#include "SimpleRectanglesWorld.hpp"

namespace sstd{

    SimpleRectanglesWorld::SimpleRectanglesWorld(){

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
                thisScene.invalidate (thisCurrentViewPort);
                return;
            }
        }

        {/*部分改变*/
            QRegion varRegin{  varTargetRect   };
            varRegin = varRegin.subtracted (  thisCurrentViewPort ) ;
            for( const auto & varI : varRegin ){
                thisScene.invalidate ( varI );
            }
        }

        thisCurrentViewPort = varTargetRect;
    }

    void SimpleRectanglesWorld::paint(QPainter *painter){

    }

}/*namespace sstd*/

inline static void registerThis(){

}
Q_COREAPP_STARTUP_FUNCTION(registerThis)










