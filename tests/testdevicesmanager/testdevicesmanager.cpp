#include <QObject>
#include <QtTest/QtTest>

#include "devicesmanager.h"
#include "logicalleddevice.h"
#include "logicalmotordevice.h"
#include "hardwareleddevice.h"
#include "hardwaremotordevice.h"

class TestDevicesManager: public QObject {
    Q_OBJECT
public:

private slots:
    void testAddLogicalDevices();
    void testHwDevicesCount();
    void testHardwareAndLogicalDevicesMatch();
};

void TestDevicesManager::testAddLogicalDevices()
{
    device::DevicesManager devicesManager;

    devicesManager.addLogicalDevice(new device::LogicalLedDevice(0, 0));
    devicesManager.addLogicalDevice(new device::LogicalLedDevice(0, 1));
    devicesManager.addLogicalDevice(new device::LogicalLedDevice(1, 1));
    devicesManager.addLogicalDevice(new device::LogicalMotorDevice(10));

    QVERIFY2(devicesManager.logicalDevices().length() == 4, "Wrong number of logical devices");
}

void TestDevicesManager::testHwDevicesCount()
{
    device::DevicesManager devicesManager;

    devicesManager.addLogicalDevice(new device::LogicalLedDevice(0, 0));
    devicesManager.addLogicalDevice(new device::LogicalLedDevice(0, 1));
    devicesManager.addLogicalDevice(new device::LogicalLedDevice(1, 0));
    devicesManager.addLogicalDevice(new device::LogicalMotorDevice(10));
    devicesManager.addLogicalDevice(new device::LogicalMotorDevice(11));

    QVERIFY2(devicesManager.hardwareDevices().length() == 4, "Wrong number of hardware devices");
    QVERIFY2(devicesManager.hardwareDevices().at(0)->deviceId == 0 && devicesManager.hardwareDevices().at(0)->deviceType == device::DeviceType::Led, "Invalid hardware device");
    QVERIFY2(devicesManager.hardwareDevices().at(1)->deviceId == 1 && devicesManager.hardwareDevices().at(1)->deviceType == device::DeviceType::Led, "Invalid hardware device");
    QVERIFY2(devicesManager.hardwareDevices().at(2)->deviceId == 10 && devicesManager.hardwareDevices().at(2)->deviceType == device::DeviceType::Motor, "Invalid hardware device");
    QVERIFY2(devicesManager.hardwareDevices().at(3)->deviceId == 11 && devicesManager.hardwareDevices().at(3)->deviceType == device::DeviceType::Motor, "Invalid hardware device");
}

void TestDevicesManager::testHardwareAndLogicalDevicesMatch()
{
    device::LogicalLedDevice ledDevice10(1, 0);
    device::LogicalLedDevice ledDevice11(1, 0);
    device::LogicalLedDevice ledDevice20(2, 0);

    device::HardwareLedDevice hardwareLedDevice1(1);
    device::HardwareMotorDevice hardwareMotorDevice1(1);

    device::DevicesManager devicesManager;

    QVERIFY2(devicesManager.logicalAndHardwareDevicesMatch(&ledDevice10, &hardwareLedDevice1) == true, "Devices should match");
    QVERIFY2(devicesManager.logicalAndHardwareDevicesMatch(&ledDevice20, &hardwareLedDevice1) == false, "Devices should not match");
    QVERIFY2(devicesManager.logicalAndHardwareDevicesMatch(&ledDevice10, &hardwareMotorDevice1) == false, "Devices should not match");
}

QTEST_MAIN(TestDevicesManager)

#include "testdevicesmanager.moc"
