#pragma once

#include <sstd_qt_qml_quick_library.hpp>

namespace sstd {

    namespace TestNameSpace {
        Q_NAMESPACE
        enum MyEnum {
            Key1,
            Key2,
        };
        Q_ENUMS(MyEnum)
    }

    class TestGadget{
        Q_GADGET
    public:
        enum MyEnum {
            Key1,
            Key2,
            Key3,
        };
        Q_ENUMS(MyEnum)
    public:
        friend inline bool operator==(const TestGadget & l,const TestGadget & r){
            return l.thisX == r.thisX;
        }
        Q_INVOKABLE int getX() const {
            return thisX;
        }
    private:
        int thisX{ 0 };
    private:
        sstd_class(TestGadget);
    };

    class TestObject : public QObject {
        Q_OBJECT
    private:
        Q_PROPERTY(QVariant gadgetValue READ getGadgetValue WRITE setGadgetValue NOTIFY gadgetValueChanged)
    public:
        enum MyEnum {
            Key1,
            Key2,
            Key3,
            Key4
        };
        Q_ENUMS(MyEnum)
    public:
        QVariant getGadgetValue() const;
        void setGadgetValue(QVariant gadgetValue);
    signals:
        void gadgetValueChanged();
    private:
        sstd_class(TestObject);
        TestGadget thisGadgetValue;
    };


}/*namespace sstd*/













