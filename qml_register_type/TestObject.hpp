#pragma once

#include <sstd_qt_qml_quick_library.hpp>

namespace sstd {

    class TestObject : public QObject {
        Q_OBJECT
    private:
        Q_PROPERTY(int test READ test WRITE setTest NOTIFY testChanged)
    signals:
        void testChanged();
    public:
        inline int test() const;
        void setTest(int);
    private:
        int thisTest{ 1 };
    private:
        sstd_class(TestObject);
    };

    class TestObject1 : public TestObject {
        Q_OBJECT
    private:
        Q_PROPERTY(int test1 READ test1 WRITE setTest1 NOTIFY test1Changed REVISION 1)
    signals:
        Q_REVISION(1) void test1Changed();
    public:
        inline int test1() const;
        void setTest1(int);
    private:
        int thisTest1{ 1 };
    private:
        sstd_class(TestObject1);
    };

    class TestObject2 : public TestObject1 {
        Q_OBJECT
    private:
        Q_PROPERTY(int test2 READ test2 WRITE setTest2 NOTIFY test2Changed REVISION 2)
    signals:
        Q_REVISION(2) void test2Changed();
    public:
        inline int test2() const;
        void setTest2(int);
    private:
        int thisTest2{ 1 };
    private:
        sstd_class(TestObject2);
    };

    inline int TestObject::test() const {
        return thisTest;
    }

    inline int TestObject1::test1() const {
        return thisTest1;
    }

    inline int TestObject2::test2() const {
        return thisTest2;
    }

    class NewTest : public QObject {
        Q_OBJECT
    public:
        Q_INVOKABLE inline int test1() const {
            return 1;
        }
        Q_INVOKABLE inline int test2() const {
            return 1;
        }
        Q_INVOKABLE inline int test() const {
            return 1;
        }
    private:
        sstd_class(NewTest);
    };


}/*namespace sstd*/













