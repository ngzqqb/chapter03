#include "TestObject.hpp"

namespace sstd{

    QVariant TestObject::getGadgetValue() const{
        return QVariant::fromValue( thisGadgetValue );
    }

    void TestObject::setGadgetValue(QVariant gadgetValue){
        if(!gadgetValue.convert( qMetaTypeId<TestGadget>() )){
            qWarning() << "can not convert to TestGadget";
            return;
        }
        auto var = gadgetValue.value<TestGadget>();
        if(thisGadgetValue == var){
            return;
        }
        thisGadgetValue = var;
        gadgetValueChanged();
    }

}/*namespace sstd*/

inline static void registerThis() {
    qmlRegisterUncreatableMetaObject(sstd::TestNameSpace::staticMetaObject,
                                     "sstd.metaobject.test",
                                     1,0,
                                     "MyNamespace",
                                     "Can not Create Namespace!");
    qmlRegisterUncreatableMetaObject(sstd::TestGadget::staticMetaObject,
                                     "sstd.metaobject.test",
                                     1,0,
                                     "MyGadgetNamespace",
                                     "Can not Create GadgetNamespace!");
    qmlRegisterType<sstd::TestObject>("sstd.metaobject.test",
                                      1,0,
                                      "TestObject");
}

Q_COREAPP_STARTUP_FUNCTION(registerThis)
