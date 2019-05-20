#include "TestObject.hpp"

namespace sstd{


}/*namespace sstd*/

inline static void registerThis() {
    qmlRegisterUncreatableMetaObject(sstd::TestNameSpace::staticMetaObject,
                                     "sstd.metaobject.test",
                                     1,0,
                                     "MyNamespace",
                                     "Can not Create Namespace!");
}

Q_COREAPP_STARTUP_FUNCTION(registerThis)


