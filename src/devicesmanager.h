#ifndef DEVICES_MANAGER_H
#define DEVICES_MANAGER_H

#include "array.h"

namespace device {

class IHardwareDevice;
class ILogicalDevice;

class DevicesManager {
public:
    void addLogicalDevice(ILogicalDevice* logicalDevice);
    Array<ILogicalDevice*>& logicalDevices() { return m_logicalDevices; }
    Array<IHardwareDevice*>& hardwareDevices() { return m_hardwareDevices; }
    void updateOutputsFromDevices();
    // public for testing purpose
    bool logicalAndHardwareDevicesMatch(ILogicalDevice* logicalDevice, IHardwareDevice* hardwareDevice);

private:
    Array<ILogicalDevice*> m_logicalDevices;
    Array<IHardwareDevice*> m_hardwareDevices;
};

} // namespace device

#endif // DEVICES_MANAGER_H
