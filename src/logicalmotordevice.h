#ifndef LOGICAL_MOTOR_DEVICE_H
#define LOGICAL_MOTOR_DEVICE_H

#include "ilogicaldevice.h"

#include <stdint.h>

namespace device {

class LogicalMotorDevice: public ILogicalDevice {
public:
    LogicalMotorDevice(int deviceId);

    uint8_t angle = 120;
};

} // namespace device

#endif // LOGICAL_MOTOR_DEVICE_H
