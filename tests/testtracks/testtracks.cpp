#include <QObject>
#include <QtTest/QtTest>

#include "track.h"
#include "logicalleddevice.h"
#include "ledaction.h"

class TestTrack: public QObject {
    Q_OBJECT
public:

private slots:
    void testHasActiveActionAtTime();
    void testPrevActiveActionAtTime();
};

void TestTrack::testHasActiveActionAtTime()
{
    device::LogicalLedDevice ledDevice(0, 0);
    show::Track track(&ledDevice);
    action::LedAction a1;
    action::LedAction a2;

    a1.startTime = 1000;
    a1.duration = 1000;
    a2.startTime = 2000;
    a2.duration = 1000;

    track.appendAction(&a1);
    track.appendAction(&a2);

    QVERIFY2(track.activeActionAtTime(500)  == nullptr, "hasActiveAction should return null");
    QVERIFY2(track.activeActionAtTime(1000) != nullptr, "hasActiveAction should not return null");
    QVERIFY2(track.activeActionAtTime(1500) != nullptr, "hasActiveAction should not return null");
    QVERIFY2(track.activeActionAtTime(2000) != nullptr, "hasActiveAction should not return null");
    QVERIFY2(track.activeActionAtTime(2500) != nullptr, "hasActiveAction should not return null");
    QVERIFY2(track.activeActionAtTime(3000) != nullptr, "hasActiveAction should not return null");
    QVERIFY2(track.activeActionAtTime(3500) == nullptr, "hasActiveAction should return null");
}

void TestTrack::testPrevActiveActionAtTime()
{
    device::LogicalLedDevice ledDevice(0, 0);
    show::Track track(&ledDevice);
    action::LedAction a1;
    action::LedAction a2;

    a1.startTime = 1000;
    a1.duration = 1000;
    a2.startTime = 2000;
    a2.duration = 1000;

    track.appendAction(&a1);
    track.appendAction(&a2);

    QVERIFY2(track.prevActiveActionAtTime(0)    == nullptr, "prevActiveAction should return null");
    QVERIFY2(track.prevActiveActionAtTime(1000) == nullptr, "prevActiveAction should return null");
    QVERIFY2(track.prevActiveActionAtTime(2000) == &a1,     "prevActiveAction should return &a1");
    QVERIFY2(track.prevActiveActionAtTime(2500) == &a1,     "prevActiveAction should return &a1");
    QVERIFY2(track.prevActiveActionAtTime(3000) == &a1,     "prevActiveAction should return &a1");
    QVERIFY2(track.prevActiveActionAtTime(3500) == &a2,     "prevActiveAction should return &a2");
}

QTEST_MAIN(TestTrack)

#include "testtracks.moc"
