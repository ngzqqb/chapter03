#include "TestObject.hpp"

namespace sstd{
    void TestAttachedType::setValueAttached(QColor valueAttached){
        if (thisValueAttached == valueAttached){
            return;
         }
        thisValueAttached = valueAttached;
        valueAttachedChanged();
    }

    TestAttachedType *TestAttachedType::qmlAttachedProperties(QObject * arg){
        return sstd_new<TestAttachedType>(arg);
    }

    TestAttachedType::TestAttachedType(QObject * arg) : QObject(arg) {
    }

}/*namespace sstd*/

inline static void registerThis() {
    qmlRegisterUncreatableType<sstd::TestAttachedType>("sstd.attached.test",
        1,0,
        "TestAttached",
        QStringLiteral("This is Attached Type!"));
}

Q_COREAPP_STARTUP_FUNCTION(registerThis)
