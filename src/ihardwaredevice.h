#ifndef IHARDWARE_DEVICE_H
#define IHARDWARE_DEVICE_H

#include "devicetype.h"

namespace device {

class IHardwareDevice {
public:
    IHardwareDevice(DeviceType deviceType, int deviceId):
        deviceType(deviceType),
        deviceId(deviceId)
    {
    }

    DeviceType deviceType = DeviceType::Invalid;
    int deviceId = -1;
};

} // namespace device

#endif // IHARDWARE_DEVICE_H
