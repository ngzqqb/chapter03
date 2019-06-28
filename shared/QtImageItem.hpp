#pragma once

#include <sstd_qt_qml_quick_library.hpp>
#include "QtImageNode.hpp"

namespace sstd {

    class QtImageItem : public QQuickItem {
        Q_OBJECT
    private:
        Q_PROPERTY(qreal offsetX READ getOffsetX WRITE setOffsetX NOTIFY offsetXChanged)
    private:
        Q_PROPERTY(qreal offsetY READ getOffsetY WRITE setOffsetY NOTIFY offsetYChanged)
    public:
        QtImageItem();
    public:
        Q_INVOKABLE void setImage(const QImage &);
    public:
        inline qreal getOffsetX();
        inline qreal getOffsetY();
        Q_SIGNAL void offsetXChanged();
        Q_SIGNAL void offsetYChanged();
        void setOffsetX(const qreal &);
        void setOffsetY(const qreal &);
    private:
        void updateImageMatrix();
    protected:
        QSGNode * updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *updatePaintNodeData) override;
    private:
        qreal thisOffestY{0};
        qreal thisOffestX{0};
        std::shared_ptr<QtImageNodeData> thisImageData;
    private:
        sstd_class(QtImageItem);
    };

    inline qreal QtImageItem::getOffsetX(){
        return thisOffestX;
    }

    inline qreal QtImageItem::getOffsetY(){
        return thisOffestY;
    }

}/*namespace sstd*/
