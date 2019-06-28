#include "SimpleQGraphicsScene.hpp"

namespace sstd {

    SimpleQGraphicsScene::SimpleQGraphicsScene(){
    }

    SimpleQGraphicsSceneViewPort::SimpleQGraphicsSceneViewPort(SimpleQGraphicsSceneView * arg)
        :thisView{arg}{
    }

    SimpleQGraphicsSceneView::SimpleQGraphicsSceneView(){
        this->setWidth (10);
        this->setHeight (10);
        thisScene.setSceneRect (0,0,width(),height());
        connect (this,&QQuickItem::heightChanged ,[this](){thisScene.setSceneRect (0,0,width(),height());});
        connect (this,&QQuickItem::widthChanged ,[this](){thisScene.setSceneRect (0,0,width(),height());});
        connect ( &thisScene,&QGraphicsScene::changed , this,&SimpleQGraphicsSceneView::updateViewPort );
        thisSceneViewPort = sstd_make_unique<SimpleQGraphicsSceneViewPort>(this);
    }

    void SimpleQGraphicsSceneView::updateViewPort(QList<QRectF> arg){
        auto varImageSize = thisLastPainted.size ();
        auto varTargetViewPort = thisSceneViewPort->getViewPortRect () ;
        const auto varDevicePixelRatio = qGuiApp->devicePixelRatio ();

        {/*检查是否更新画布大小*/
            const QSize varTargetSize  {
                static_cast<int>(varTargetViewPort.width () * varDevicePixelRatio ) ,
                        static_cast<int>(varTargetViewPort.height () * varDevicePixelRatio )
            } ;
            if(varTargetSize!=varImageSize){
                thisLastPainted = QImage{
                        varTargetSize.width () ,
                        varTargetSize.height () ,
                        sstd::opengl_utility::defaultQImageFormat ()};
                thisLastPainted.fill (QColor(0,0,0,0));
                arg = { varTargetViewPort } ;
            }
        }

        {/*绘制更新区域*/
            QPainter varPainter{ &thisLastPainted };
            for( const auto & varI : std::as_const( arg ) ){
                if(varI.isEmpty ()){
                    continue;
                }
                const QSizeF varTargetSize  {
                    varTargetViewPort.width () * varDevicePixelRatio  ,
                            varTargetViewPort.height () * varDevicePixelRatio
                } ;
                auto varTargetX = ( varI.x() - thisSceneViewPort->getX () ) * varDevicePixelRatio;
                auto varTargetY = ( varI.y() - thisSceneViewPort->getY () ) * varDevicePixelRatio;
                thisScene.render (&varPainter,{varTargetX,varTargetY,varTargetSize.width (),varTargetSize.height ()},
                                  varI);
            }
        }

        /*显示结果*/
        this->setImage (thisLastPainted);

    }

    void SimpleQGraphicsSceneView::updateViewPortSize(){
        this->setOffsetX(thisSceneViewPort->getX());
        this->setOffsetY(thisSceneViewPort->getY());
        updateViewPort( { thisSceneViewPort->getViewPortRect () } );
    }

    template<typename T>
    inline constexpr bool isSame(const T & a,const T & b){
        return (std::abs(a-b)<std::numeric_limits<T>::epsilon ());
    }

    void SimpleQGraphicsSceneViewPort::setX(const qreal & arg){
        if(isSame(arg,thisX)){
            return;
        }
        thisX=arg;
        thisView->updateViewPortSize ();
        xChanged ();
    }

    void SimpleQGraphicsSceneViewPort::setY(const qreal & arg){
        if(isSame(arg,thisY)){
            return;
        }
        thisY=arg;
        thisView->updateViewPortSize ();
        yChanged ();
    }

    void SimpleQGraphicsSceneViewPort::setWidth(const qreal & arg){
        if(isSame(arg,thisWidth)){
            return;
        }
        thisWidth=arg;
        thisView->updateViewPortSize ();
        widthChanged ();
    }

    void SimpleQGraphicsSceneViewPort::setHeight(const qreal & arg){
        if(isSame(arg,thisHeight)){
            return;
        }
        thisHeight=arg;
        thisView->updateViewPortSize ();
        heightChanged ();
    }

    QRectF SimpleQGraphicsSceneViewPort::getViewPortRect() const{
        return QRectF( getX(),getY() , 1 + getWidth (), 1 + getHeight () );
    }

}/* namespace sstd */


//逻辑错误 TODO：....
















