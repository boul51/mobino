#include "devicesmanager.h"

#include "hardwaredevicefactory.h"
#include "ilogicaldevice.h"
#include "ihardwaredevice.h"

namespace device {

void DevicesManager::addLogicalDevice(ILogicalDevice *logicalDevice)
{
    m_logicalDevices.append(logicalDevice);

    for (int i = 0; i < m_hardwareDevices.length(); i++)
        if (logicalAndHardwareDevicesMatch(logicalDevice, m_hardwareDevices.at(i)))
            return;

    m_hardwareDevices.append(HardwareDeviceFactory::createHardwareDeviceForLogicalDevice(*logicalDevice));
}

void DevicesManager::updateOutputsFromDevices()
{

}

bool DevicesManager::logicalAndHardwareDevicesMatch(ILogicalDevice *logicalDevice, IHardwareDevice *hardwareDevice)
{
    return logicalDevice->deviceType == hardwareDevice->deviceType
            && logicalDevice->deviceId == hardwareDevice->deviceId;
}

} // namespace device
