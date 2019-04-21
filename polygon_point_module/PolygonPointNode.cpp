#include "PolygonPointNode.hpp"
#include <Static.hpp>

namespace sstd {

    PolygonPointNodeData::PolygonPointNodeData() {
        thisWidth = 1;
        thisHeight = 1;
        thisPolygonSize = 3;
        thisFlags.setAll();
    }

    PolygonPointNode::PolygonPointNode(std::shared_ptr<PolygonPointNodeData> arg)
        :thisData(arg) {
    }

    PolygonPointDrawNode::PolygonPointDrawNode(std::shared_ptr<QSGGeometry> arg) :
        thisData(std::move(arg)) {
        this->setGeometry(thisData.get());
        this->setMaterial(&thisMaterial);
    }

    void PolygonPointDrawNode::setColor(const QColor & arg) {
        thisMaterial.setColor(arg);
        this->markDirty(DirtyMaterial);
    }

    void PolygonPointNode::updateTheNode() {

        if (thisData->testChanged< PolygonPointNodeDataState::SizeChanged >()) {
            auto varStatic = static_cast<Static*>(Static::instance(nullptr, nullptr));
            auto varNode =
                sstd_new<PolygonPointDrawNode>(varStatic->getPolygon(thisData->getPolygonSize()));
            if (thisDrawNode) {
                delete thisDrawNode;
            }
            thisDrawNode = varNode;
            this->appendChildNode(thisDrawNode);
            varNode->setColor(thisData->getColor());
        }

        if (thisData->testChanged< PolygonPointNodeDataState::ColorChanged >()) {
            thisDrawNode->setColor(thisData->getColor());
        }

        if ((thisData->testChanged< PolygonPointNodeDataState::CenterChanged >()) ||
            (thisData->testChanged< PolygonPointNodeDataState::RadiusChanged >())) {

            auto varRadius = thisData->getRadius();
            auto varCenter = thisData->getCenter();

            QMatrix4x4 varMatrix;
            varMatrix.translate(
                varRadius.first*0.5  ,
                varRadius.second*0.5  );
            varMatrix.scale(varRadius.first*0.5, -varRadius.second*0.5);

            this->setMatrix(varMatrix);
            this->markDirty(DirtyMatrix);
        }

        thisData->clearAllChange();

    }

    void PolygonPointNodeData::clearAllChange() {
        thisFlags.clearAll();
    }

    bool PolygonPointNodeData::setPolygonSize(const int &arg) {
        if (arg == thisPolygonSize) {
            return false;
        }
        thisPolygonSize = arg;
        thisFlags.set< PolygonPointNodeDataState::SizeChanged >();
        return true;
    }

    bool PolygonPointNodeData::setRadius(const double &argWidth, const double &argHeight) {
        if ((argWidth == thisWidth) && (argHeight == thisHeight)) {
            return false;
        }
        thisWidth = argWidth;
        thisHeight = argHeight;
        thisFlags.set< PolygonPointNodeDataState::RadiusChanged >();
        return true;
    }

    bool PolygonPointNodeData::setCenter(const QPointF &arg) {
        if (arg == thisCenter) {
            return false;
        }
        thisCenter = arg;
        thisFlags.set< PolygonPointNodeDataState::CenterChanged >();
        return true;
    }

    bool PolygonPointNodeData::setColor(const QColor & arg) {
        if (arg == thisColor) {
            return false;
        }
        thisColor = arg;
        thisFlags.set< PolygonPointNodeDataState::ColorChanged >();
        return true;
    }

}/*namespace sstd*/
