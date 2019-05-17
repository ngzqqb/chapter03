#include "TestObject.hpp"

namespace sstd{

    void TestObject::setTest(int arg){
        if( arg == thisTest ){
            return;
        }
        thisTest = arg;
        testChanged();
    }

    void TestObject::setTest3(int arg){
        if( arg == thisTest3 ){
            return;
        }
        thisTest3 = arg;
        test3Changed();
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

    void TestBasic::setBasicV0(int arg){
        if( thisBasicV0 == arg ){
            return;
        }
        thisBasicV0 = arg;
        basicV0Changed();
    }

    void TestBasic::setBasicV1(int arg){
        if( thisBasicV1 == arg ){
            return;
        }
        thisBasicV1 = arg;
        basicV1Changed();
    }


}/*namespace sstd*/

inline static void registerThis() {
    /*1.0*/
    qmlRegisterType<sstd::TestObject >("sstd.register.type",1,0,"RegisterObject");
    /*1.1*/
    qmlRegisterType<sstd::TestObject1 , 1>("sstd.register.type",1,1,"RegisterObject");
    qmlRegisterRevision<sstd::TestBasic,1>("sstd.register.type",1,1);
    /*1.2*/
    qmlRegisterType<sstd::TestObject2 , 2>("sstd.register.type",1,2,"RegisterObject");
    /*1.3*/
    qmlRegisterType<sstd::TestObject2 , 3>("sstd.register.type",1,3,"RegisterObject");
    qmlRegisterRevision<sstd::TestObject,3 >("sstd.register.type",1,3);
    /*2.0*/
    qmlRegisterType<sstd::NewTest >("sstd.register.type",2,0,"RegisterObject");
}

Q_COREAPP_STARTUP_FUNCTION(registerThis)


