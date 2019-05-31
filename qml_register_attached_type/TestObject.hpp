#pragma once

#include <sstd_qt_qml_quick_library.hpp>

namespace sstd {

    class TestAttachedType : public QObject {
        Q_OBJECT
    private:
        Q_PROPERTY(QColor valueAttached READ getValueAttached WRITE setValueAttached NOTIFY valueAttachedChanged)
    public:
        inline QColor getValueAttached() const{
            return thisValueAttached;
        }
        TestAttachedType(QObject *);
    public:
        static TestAttachedType *qmlAttachedProperties(QObject *);
    public:
        void setValueAttached(QColor valueAttached);
    signals:
        void valueAttachedChanged();
    private:
        QColor thisValueAttached{128,128,128,255};
    private:
        sstd_class(TestAttachedType);
    };

}/*namespace sstd*/

QML_DECLARE_TYPEINFO(sstd::TestAttachedType, QML_HAS_ATTACHED_PROPERTIES)
