#include <QObject>
#include <QtTest/QtTest>

#include "array.h"

class TestArray: public QObject {
    Q_OBJECT
public:

private slots:
    void testSizeIsZeroBeforeAppend();
    void testSizeIsOneAfterAppend();
    void testReadBackFirstElem();
    void testReadBackTenElems();
    void testRemoveAt();
    void testRemoveAll();
    void testIndexOf();
    void testRemoveWithPointers();
};

void TestArray::testSizeIsZeroBeforeAppend()
{
    Array<int> a;

    QVERIFY2(a.length() == 0, "Array is not empty after init");
}

void TestArray::testSizeIsOneAfterAppend()
{
    int i = 0;
    Array<int> a;
    a.append(i);

    Q_ASSERT(a.length() == 1);

}

void TestArray::testReadBackFirstElem()
{
    int i = 51;
    Array<int> a;
    a.append(i);

    int readBack = a.at(0);

    QVERIFY2(readBack == 51, "Read back value at index 0 is not correct");
}

void TestArray::testReadBackTenElems()
{
    Array<int> a;

    for (int i = 0; i < 10; i++) {
        a.append(i + 33);
    }

    for (int i = 0; i < 10; i++) {
        QVERIFY2(a.at(i) == i + 33, "Read back value in array is not correct");
    }
}

void TestArray::testRemoveAt()
{
    Array<int>a;

    a.append(0);
    a.append(1);
    a.append(2);

    a.removeAt(1);

    QVERIFY2(a.at(0) == 0, "Wrong value at index 0");
    QVERIFY2(a.at(1) == 2, "Wrong value at index 1");

    a.removeAt(0);

    QVERIFY2(a.length() == 1, "Wrong length after remove");
    QVERIFY2(a.at(0) == 2, "Wrong value at index 0");

    a.removeAt(0);

    QVERIFY2(a.length() == 0, "Wrong length after remove");
}

void TestArray::testRemoveAll()
{
    Array<int>a;
    for (int i = 0; i < 10; i++) {
        a.append(i);
    }

    for (int i = 0; i < 10; i++) {
        a.removeAt(0);
    }

    QVERIFY2(a.length() == 0, "Array is not empty");
}

void TestArray::testIndexOf()
{
    Array<int>a;

    a.append(2);
    a.append(3);
    a.append(4);

    QVERIFY2(a.indexOf(2) == 0,  "indexOf returned wrong value");
    QVERIFY2(a.indexOf(3) == 1,  "indexOf returned wrong value");
    QVERIFY2(a.indexOf(4) == 2,  "indexOf returned wrong value");
    QVERIFY2(a.indexOf(0) == -1, "indexOf returned wrong value");
}

void TestArray::testRemoveWithPointers()
{
    Array<int*>a;

    int *p0 = new int(0);
    int *p1 = new int(1);
    int *p2 = new int(2);

    a.append(p0);
    a.append(p1);
    a.append(p2);

    int* p0fromA = a.at(0);

    QVERIFY2(p0 == p0fromA, "Read back wrong pointer");

    a.removeAt(0);
    int* p1fromA = a.at(0);

    QVERIFY2(p1 == p1fromA, "Read back wrong pointer");

    a.removeAt(0);
    int* p2fromA = a.at(0);

    QVERIFY2(p2 == p2fromA, "Read back wrong pointer");

    a.removeAt(0);

    delete p0;
    delete p1;
    delete p2;
}

QTEST_MAIN(TestArray)

#include "testarray.moc"
