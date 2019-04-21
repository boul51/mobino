#include "devicesmanager.h"

#include "hardwaredevicefactory.h"
#include "ilogicaldevice.h"
#include "ihardwaredevice.h"

#include "array.h"

namespace device {

void DevicesManager::addLogicalDevice(ILogicalDevice *logicalDevice)
{
    IHardwareDevice* hardwareDevice = nullptr;

    m_logicalDevices.append(logicalDevice);

    for (int i = 0; i < m_hardwareDevices.length(); i++) {
        if (logicalAndHardwareDevicesMatch(logicalDevice, m_hardwareDevices.at(i))) {
            hardwareDevice = m_hardwareDevices.at(i);
            break;
        }
    }

    if (!hardwareDevice) {
        hardwareDevice = HardwareDeviceFactory::createHardwareDeviceForLogicalDevice(*logicalDevice);
        m_hardwareDevices.append(hardwareDevice);
    }

    hardwareDevice->appendLogicalDevice(logicalDevice);
}

void DevicesManager::initDevices()
{
    for (int i = 0; i < m_hardwareDevices.length(); i++)
        m_hardwareDevices.at(i)->initDevice();
}

void DevicesManager::updateOutputsFromDevices()
{
    for (int i = 0; i < m_hardwareDevices.length(); i++) {
        m_hardwareDevices.at(i)->updateOutput();
    }
}

bool DevicesManager::logicalAndHardwareDevicesMatch(ILogicalDevice *logicalDevice, IHardwareDevice *hardwareDevice)
{
    return logicalDevice->deviceType == hardwareDevice->deviceType
            && logicalDevice->deviceId == hardwareDevice->deviceId;
}

} // namespace device
