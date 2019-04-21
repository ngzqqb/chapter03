#pragma once

#include <sstd_qt_qml_quick_library.hpp>

namespace sstd {

    class PolygonPoint : public QQuickItem {
        Q_OBJECT
    private:
        using Super = QQuickItem;
    public:
        PolygonPoint(QQuickItem *);
    private:
        sstd_class(PolygonPoint);
    };

}/*namespace sstd*/







