#pragma once

#include <sstd_qt_qml_quick_library.hpp>

namespace sstd{

    enum class PolygonPointNodeDataState{
        SizeChanged,
        RadiusChanged,
        CenterChanged,
        ColorChanged,
        Size
    };

    class PolygonPointNodeData {
    public:
        PolygonPointNodeData();
    public:
        void clearAllChange();
    public:
        inline int getPolygonSize() const ;
        inline std::pair<double,double> getRadius() const;
        inline QPointF getCenter() const;
        inline QColor getColor() const;
    public:
        bool setPolygonSize(const int &);
        bool setRadius(const double &,const double &);
        bool setCenter(const QPointF &);
        bool setColor(const QColor &);
    public:
        template<PolygonPointNodeDataState>
        inline bool testChanged() const;
    private:
        int thisPolygonSize;
        double thisWidth;
        double thisHeight;
        QPointF thisCenter;
        QColor thisColor;
        sstd::QuickFlags< PolygonPointNodeDataState::Size > thisFlags;
    private:
        sstd_class(PolygonPointNodeData);
    };

    class PolygonPointDrawNode : public QSGGeometryNode {
    public:
        PolygonPointDrawNode(std::shared_ptr<QSGGeometry>);
    public:
        void setColor(const QColor &);
    private:
        std::shared_ptr<QSGGeometry> thisData;
        QSGFlatColorMaterial thisMaterial;
    private:
        sstd_class(PolygonPointDrawNode);
    };

    class PolygonPointNode : public QSGTransformNode {
    public:
        PolygonPointNode(std::shared_ptr<PolygonPointNodeData>);
    public:
        void updateTheNode();
    private:
        std::shared_ptr<PolygonPointNodeData> thisData;
        PolygonPointDrawNode * thisDrawNode{nullptr};
    private:
        sstd_class(PolygonPointNode);
    };

    inline int PolygonPointNodeData::getPolygonSize() const {
        return thisPolygonSize;
    }

    inline std::pair<double, double> PolygonPointNodeData::getRadius() const {
        return { thisWidth,thisHeight };
    }

    inline QPointF PolygonPointNodeData::getCenter() const {
        return thisCenter;
    }

    inline QColor PolygonPointNodeData::getColor() const {
        return thisColor;
    }

    template<PolygonPointNodeDataState I>
    inline bool PolygonPointNodeData::testChanged() const {
        return thisFlags.test<I>();
    }

}/*namespace sstd*/


