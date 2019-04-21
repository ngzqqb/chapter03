#pragma once

#include <sstd_qt_qml_quick_library.hpp>
#include <sstd/boost/compute/detail/lru_cache.hpp>

namespace sstd{

    class Static : public QObject  {
        Q_OBJECT
    public:
        Static();
    public:
        Q_SLOT int roundPointPolygonSize() const;
    public:
        static QObject * instance(QQmlEngine *, QJSEngine *);
    public:
        std::shared_ptr< QSGGeometry > getRoundPolygon() const ;
        std::shared_ptr< QSGGeometry > getPolygon(int) const ;
    private:
        mutable boost::compute::detail::lru_cache< int , std::shared_ptr<QSGGeometry> > thisCachedQSGGeometry;
        mutable std::shared_ptr< QSGGeometry > thisRoundPolygon;
    private:
        sstd_class(Static);
    };

}/*namespace sstd*/


