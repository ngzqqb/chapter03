#pragma once

#include <sstd_qt_qml_quick_library.hpp>

namespace sstd {

    class SimpleRectanglesWorld : public QQuickPaintedItem {
        Q_OBJECT
    public:
        SimpleRectanglesWorld();
        void updateViewWidth(int);
        void updateViewHeight(int);
        void updateViewX(int);
        void updateViewY(int);
    protected:
        void  paint(QPainter *painter) override;
    private:
        void updateViewPort(int, int, int, int);
        QRect thisCurrentViewPort;
        QGraphicsScene thisScene;
        std::shared_ptr< QRegion > thisRegionNotReDraw;
        QImage thisLastDraw;
        Q_SLOT void changed(const QList<QRectF> &region);
    private:
        sstd_class(SimpleRectanglesWorld);
    };

}/*namespace sstd*/

