#ifndef IHARDWARE_DEVICE_H
#define IHARDWARE_DEVICE_H

#include "devicetype.h"
#include "array.h"

namespace device {

class ILogicalDevice;

class IHardwareDevice {
public:
    IHardwareDevice(DeviceType deviceType, int deviceId):
        deviceType(deviceType),
        deviceId(deviceId)
    {
    }

    void appendLogicalDevice(ILogicalDevice* logicalDevice)
    {
        m_logicalDevices.append(logicalDevice);
    }

    virtual void initDevice() = 0;
    virtual void updateOutput() = 0;

    DeviceType deviceType = DeviceType::Invalid;
    int deviceId = -1;

protected:
    Array<ILogicalDevice*> m_logicalDevices;
};

} // namespace device

#endif // IHARDWARE_DEVICE_H
