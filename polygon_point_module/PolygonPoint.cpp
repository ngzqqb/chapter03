#include "PolygonPoint.hpp"

namespace sstd {

    PolygonPoint::PolygonPoint(QQuickItem * arg) :Super(arg) {
        this->setFlag(QQuickItem::ItemHasContents, true);
        thisData = sstd_make_shared<PolygonPointNodeData>();
    }

    QSGNode * PolygonPoint::updatePaintNode(QSGNode * argNode, QQuickItem::UpdatePaintNodeData *) {
        auto varNode = static_cast<PolygonPointNode *>(argNode);
        if (varNode == nullptr) {
            varNode = sstd_new<PolygonPointNode>(thisData);
        }
        thisData->setRadius(this->width(), this->height());
        varNode->updateTheNode();
        return varNode;
    }

    void PolygonPoint::setPolygonCenter(const QPointF & arg) {
        if (thisData->setCenter(arg)) {
            polygonCenterChanged();
            this->update();
        }
    }

    void PolygonPoint::setPolygonColor(const QColor & arg) {
        if (thisData->setColor(arg)) {
            polygonColorChanged();
            this->update();
        }
    }

    void PolygonPoint::setPolygonRadius(const double & arg){
        if(thisData->setLogicalRadius(arg)){
            polygonRadiusChanged();
            this->update();
        }
    }

    void PolygonPoint::setPolygonSize(const int & arg) {
        if (thisData->setPolygonSize(arg)) {
            polygonSizeChanged();
            this->update();
        }
    }

}/*namespace sstd*/
