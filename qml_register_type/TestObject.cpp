#include "TestObject.hpp"

namespace sstd{

    void TestObject::setTest(int arg){
        if( arg == thisTest ){
            return;
        }
        thisTest = arg;
        testChanged();
    }

    void TestObject1::setTest1(int arg){
        if( arg == thisTest1 ){
            return;
        }
        thisTest1 = arg;
        test1Changed();
    }

    void TestObject2::setTest2(int arg){
        if( arg == thisTest2 ){
            return;
        }
        thisTest2 = arg;
        test2Changed();
    }

}/*namespace sstd*/

inline static void registerThis(){
    qmlRegisterType<sstd::TestObject >("sstd.register.type",1,0,"RegisterObject");
    qmlRegisterType<sstd::TestObject1 , 1>("sstd.register.type",1,1,"RegisterObject");
    qmlRegisterType<sstd::TestObject2 , 2>("sstd.register.type",1,2,"RegisterObject");
    qmlRegisterRevision<sstd::TestObject2,3>("sstd.register.type",1,3);
    qmlRegisterType<sstd::TestObject >("sstd.register.type",2,0,"RegisterObject");
}

Q_COREAPP_STARTUP_FUNCTION(registerThis)


