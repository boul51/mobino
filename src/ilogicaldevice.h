#ifndef ILOGICAL_DEVICE_H
#define ILOGICAL_DEVICE_H

#include "devicetype.h"

#include <stdint.h>

namespace device {

class ILogicalDevice {
public:
    ILogicalDevice(DeviceType deviceType, int deviceId):
        deviceId(deviceId),
        deviceType(deviceType) {
    }

    int deviceId = -1;
    DeviceType deviceType = DeviceType::Invalid;

    struct Position {
        int8_t x = 0;
        int8_t y = 0;
    };

    Position position;
};

} // namespace device

#endif // ILOGICAL_DEVICE_H
