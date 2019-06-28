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

