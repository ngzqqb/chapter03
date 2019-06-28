#pragma once

#include <sstd_qt_qml_quick_library.hpp>
#include "QtImageNode.hpp"

namespace sstd {

    class QtImageItem : public QQuickItem {
        Q_OBJECT
    public:
        QtImageItem();
    public:
        void setImage(const QImage &);
    protected:
        QSGNode * updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *updatePaintNodeData) override;
    private:
        std::shared_ptr<QtImageNodeData> thisImageData;
    private:
        sstd_class(QtImageItem);
    };

}/*namespace sstd*/
