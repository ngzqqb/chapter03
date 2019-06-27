#include "SimpleRectanglesWorld.hpp"

namespace sstd {

    inline static void updateTestScene(QGraphicsScene * argScene) {
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 12; ++j) {
                auto varRect = argScene->addRect(i * 32, j * 32, 32, 32);
                varRect->setBrush(QColor(std::rand() & 255, 128, 255));
            }
        }
    }

    SimpleRectanglesWorld::SimpleRectanglesWorld() {
        connect(&thisScene, &QGraphicsScene::changed, this, &SimpleRectanglesWorld::changed);
        this->updateViewHeight(1024);
        this->updateViewWidth(1024);
        /*this is only for test ... */
        updateTestScene(&thisScene);
    }

    void SimpleRectanglesWorld::updateViewWidth(int arg) {
        if (thisCurrentViewPort.width() == arg) {
            return;
        }
        this->updateViewPort(thisCurrentViewPort.x(),
            thisCurrentViewPort.y(),
            arg,
            thisCurrentViewPort.height());
    }

    void SimpleRectanglesWorld::updateViewHeight(int arg) {
        if (thisCurrentViewPort.height() == arg) {
            return;
        }
        this->updateViewPort(thisCurrentViewPort.x(),
            thisCurrentViewPort.y(),
            thisCurrentViewPort.width(),
            arg);
    }

    void SimpleRectanglesWorld::updateViewX(int arg) {
        if (thisCurrentViewPort.x() == arg) {
            return;
        }
        this->updateViewPort(arg,
            thisCurrentViewPort.y(),
            thisCurrentViewPort.width(),
            thisCurrentViewPort.height());
    }

    void SimpleRectanglesWorld::updateViewY(int arg) {
        if (thisCurrentViewPort.y() == arg) {
            return;
        }
        this->updateViewPort(thisCurrentViewPort.x(),
            arg,
            thisCurrentViewPort.width(),
            thisCurrentViewPort.height());
    }

    void SimpleRectanglesWorld::updateViewPort(int argX,
        int argY,
        int argWidth,
        int argHeight) {
        QRect varTargetRect{ argX,argY,argWidth,argHeight };
        thisRegionNotReDraw = sstd_make_shared<QRegion>(varTargetRect);
        thisCurrentViewPort = varTargetRect;
    }

    void SimpleRectanglesWorld::paint(QPainter *painter) {
        auto varAboutToDraw = std::move(thisRegionNotReDraw);

        if (thisLastDraw.size() != thisCurrentViewPort.size()) {
            thisLastDraw = QImage(thisCurrentViewPort.size(), QImage::Format_RGBA8888_Premultiplied);
            QPainter varPainter{ &thisLastDraw };
            thisScene.render(&varPainter,
                QRectF(0, 0,
                    thisCurrentViewPort.width(),
                    thisCurrentViewPort.height())/*target*/,
                thisCurrentViewPort/*source*/);
            painter->drawImage(0, 0, thisLastDraw);
            return;
        }

        {
            QPainter varPainter{ &thisLastDraw };
            if (varAboutToDraw) {
                for (const auto & varI : std::as_const(*varAboutToDraw)) {
                    const auto varTarget = QRectF(varI.x() - thisCurrentViewPort.x(),
                        varI.y() - thisCurrentViewPort.y(),
                        varI.width(),
                        varI.height());
                    thisScene.render(&varPainter,
                        varTarget/*target*/,
                        varI/*source*/);
                }
                painter->drawImage(0, 0, thisLastDraw);
            } else {

                painter->drawImage(0, 0, thisLastDraw);
            }
        }

    }

    void SimpleRectanglesWorld::changed(const QList<QRectF> &region) {
        if (!thisRegionNotReDraw) {
            thisRegionNotReDraw = sstd_make_shared<QRegion>();
        }
        for (const auto & varI : region) {
            (*thisRegionNotReDraw) |= varI.toRect();
        }
        this->update();
    }

}/*namespace sstd*/

inline static void registerThis() {
    qmlRegisterType<sstd::SimpleRectanglesWorld>("sstd.simple.scene", 1, 0, "SimpleRectanglesWorld");
    qmlProtectModule("sstd.simple.scene", 1);
}
Q_COREAPP_STARTUP_FUNCTION(registerThis)


