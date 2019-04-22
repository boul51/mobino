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

QTEST_MAIN(TestArray)

#include "testarray.moc"
