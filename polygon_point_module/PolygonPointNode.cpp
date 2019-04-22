#include "PolygonPointNode.hpp"
#include <Static.hpp>

namespace sstd {

    PolygonPointNodeData::PolygonPointNodeData() {
        thisWidth = 1;
        thisHeight = 1;
        thisPolygonSize = 3;
        thisLogicalRadius = 1;
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
            (thisData->testChanged< PolygonPointNodeDataState::RadiusChanged >()) ||
            (thisData->testChanged< PolygonPointNodeDataState::LogicalRadiusChanged >())) {

            auto varRadius = thisData->getRadius();
            auto varCenter = thisData->getCenter();
            auto varLogicalRadius = static_cast<GLfloat>(thisData->getLogicalRadius());
            constexpr const auto varLimit = std::numeric_limits<GLfloat>::epsilon();

            QMatrix4x4 varMatrix;

            if ((varLogicalRadius < varLimit) ||
                (varRadius.first < varLimit) ||
                (varRadius.second < varLimit)) {
                varMatrix.scale(0, 0, 0);
            } else {
                varMatrix.translate(static_cast<GLfloat>(varRadius.first* 0.5), static_cast<GLfloat>(varRadius.second* 0.5));
                varMatrix.scale(static_cast<GLfloat>(varRadius.first*0.5), static_cast<GLfloat>(-0.5*varRadius.second));
                varMatrix.translate(static_cast<GLfloat>(varCenter.x()), static_cast<GLfloat>(varCenter.y()));
                varMatrix.scale(varLogicalRadius, varLogicalRadius);
            }

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

    bool PolygonPointNodeData::setLogicalRadius(const double & arg) {
        if (arg == thisLogicalRadius) {
            return false;
        }
        thisLogicalRadius = arg;
        thisFlags.set< PolygonPointNodeDataState::LogicalRadiusChanged >();
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
