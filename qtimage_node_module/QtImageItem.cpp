#include "QtImageItem.hpp"

namespace sstd {

    QtImageItem::QtImageItem() {
        thisImageData = sstd_make_shared<QtImageNodeData>();
        this->setFlag(QQuickItem::ItemHasContents, true);
    }

    void QtImageItem::setImage(const QImage & arg) {
        thisImageData->setImage(arg);
        this->update();
    }

    void QtImageItem::setOffsetX(const qreal & arg) {
        if (std::abs(arg - thisOffestX) < std::numeric_limits<qreal>::epsilon()) {
            return;
        }
        thisOffestX = arg;
        this->updateImageMatrix();
        offsetXChanged();
    }

    void QtImageItem::setOffsetY(const qreal & arg) {
        if (std::abs(arg - thisOffestY) < std::numeric_limits<qreal>::epsilon()) {
            return;
        }
        thisOffestY = arg;
        this->updateImageMatrix();
        offsetYChanged();
    }

    void QtImageItem::updateImageMatrix() {
        QMatrix4x4 varMatrix;
        varMatrix.translate(thisOffestX, thisOffestY);
        if (thisImageData->setMatrix(varMatrix)) {
            this->update();
        }
    }

    QSGNode * QtImageItem::updatePaintNode(QSGNode *oldNode,
        QQuickItem::UpdatePaintNodeData *) {
        auto varAns = static_cast<QtImageNode *>(oldNode);
        if (varAns == nullptr) {
            varAns = sstd_new<QtImageNode>(thisImageData);
        }
        thisImageData->setImageSize(QSizeF{ width(),height() });
        varAns->updateTheNode();
        return varAns;
    }

}/*namespace sstd*/

