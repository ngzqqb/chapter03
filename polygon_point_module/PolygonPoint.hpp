#pragma once

#include <sstd_qt_qml_quick_library.hpp>
#include "PolygonPointNode.hpp"

namespace sstd {

    class PolygonPoint : public QQuickItem {
        Q_OBJECT
    private:
        using Super = QQuickItem;
    public:
        Q_PROPERTY(QColor polygonColor READ getPolygonColor WRITE setPolygonColor NOTIFY polygonColorChanged)
    public:
        Q_PROPERTY(QPointF polygonCenter READ getPolygonCenter WRITE setPolygonCenter NOTIFY polygonCenterChanged)
    public:
        Q_PROPERTY(int polygonSize READ getPolygonSize WRITE setPolygonSize NOTIFY polygonSizeChanged)
    public:
        Q_PROPERTY(double polygonRadius READ getPolygonRadius WRITE setPolygonRadius NOTIFY polygonRadiusChanged)
    public:
        PolygonPoint(QQuickItem *p = nullptr);
    public:
        inline int getPolygonSize() const;
        void setPolygonSize(const int &);
    public:
        inline QPointF getPolygonCenter() const;
        void setPolygonCenter(const QPointF &);
    public:
        inline QColor getPolygonColor() const;
        void setPolygonColor(const QColor &);
    public:
        inline double getPolygonRadius() const;
        void setPolygonRadius(const double &);
    public:
        Q_SIGNAL void polygonSizeChanged();
        Q_SIGNAL void polygonCenterChanged();
        Q_SIGNAL void polygonColorChanged();
        Q_SIGNAL void polygonRadiusChanged();
    protected:
        virtual QSGNode * updatePaintNode(QSGNode *, QQuickItem::UpdatePaintNodeData *) override;
    private:
        std::shared_ptr<PolygonPointNodeData> thisData;
    private:
        sstd_class(PolygonPoint);
    };

    inline int PolygonPoint::getPolygonSize() const {
        return thisData->getPolygonSize();
    }

    inline QPointF PolygonPoint::getPolygonCenter() const {
        return thisData->getCenter();
    }

    inline QColor PolygonPoint::getPolygonColor() const {
        return thisData->getColor();
    }

    inline double PolygonPoint::getPolygonRadius() const{
        return thisData->getLogicalRadius();
    }


}/*namespace sstd*/







