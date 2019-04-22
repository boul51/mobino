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
    showManager.generateTracksActions(0);

    show::Track* track = showManager.tracks.at(0);
    QVERIFY2(track->actions.length() > 0, "Track has no action");
}

QTEST_MAIN(TestShowManager)

#include "testshowmanager.moc"
