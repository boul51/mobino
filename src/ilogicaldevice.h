#ifndef ILOGICAL_DEVICE_H
#define ILOGICAL_DEVICE_H

#include "devicetype.h"

namespace device {

class ILogicalDevice {
public:
    ILogicalDevice(DeviceType deviceType, int deviceId):
        deviceId(deviceId),
        deviceType(deviceType) {
    }

    int deviceId = -1;
    DeviceType deviceType = DeviceType::Invalid;
};

} // namespace device

#endif // ILOGICAL_DEVICE_H
