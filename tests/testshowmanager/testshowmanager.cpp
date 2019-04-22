#include <QObject>
#include <QtTest/QtTest>

#include "sleepyshowmanager.h"
#include "logicalleddevice.h"
#include "logicalmotordevice.h"
#include "ilogicaldevice.h"
#include "array.h"
#include "track.h"
#include "ledaction.h"
#include "motoraction.h"

class TestShowManager: public QObject {
    Q_OBJECT
public:

private slots:
    void testTracksCreation();
    void testGenerateTracksActions();
    void testTrackHasActiveActionAtTimeTrue();
};

void TestShowManager::testTracksCreation()
{
    show::SleepyShowManager showManager;
    device::LogicalLedDevice ledDevice10(1, 0);
    device::LogicalLedDevice ledDevice11(1, 1);
    device::LogicalMotorDevice motorDevice1(1);

    Array<device::ILogicalDevice*>logicalDevices;
    logicalDevices.append(&ledDevice10);
    logicalDevices.append(&ledDevice11);
    logicalDevices.append(&motorDevice1);

    showManager.createTracksForDevices(logicalDevices);

    QVERIFY2(showManager.tracks.length() == logicalDevices.length(), "Invalid tracks list length");

    QVERIFY2(showManager.tracks.at(0)->logicalDevice == &ledDevice10, "Wrong device for track");
}

void TestShowManager::testGenerateTracksActions()
{
    show::SleepyShowManager showManager;
    device::LogicalLedDevice ledDevice10(1, 0);

    Array<device::ILogicalDevice*>logicalDevices;
    logicalDevices.append(&ledDevice10);

    showManager.createTracksForDevices(logicalDevices);
    showManager.generateTracksActions(0, logicalDevices);

    show::Track* track = showManager.tracks.at(0);
    QVERIFY2(track->actions.length() > 0, "Track has no action");
}

void TestShowManager::testTrackHasActiveActionAtTimeTrue()
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

    QVERIFY2(!track.hasActiveActionAtTime(500), "hasActiveAction should return false");
    QVERIFY2(track.hasActiveActionAtTime(1000), "hasActiveAction should return true");
    QVERIFY2(track.hasActiveActionAtTime(1500), "hasActiveAction should return true");
    QVERIFY2(track.hasActiveActionAtTime(2000), "hasActiveAction should return true");
    QVERIFY2(track.hasActiveActionAtTime(2500), "hasActiveAction should return true");
    QVERIFY2(track.hasActiveActionAtTime(3000), "hasActiveAction should return true");
    QVERIFY2(!track.hasActiveActionAtTime(3500), "hasActiveAction should return false");
}

QTEST_MAIN(TestShowManager)

#include "testshowmanager.moc"
