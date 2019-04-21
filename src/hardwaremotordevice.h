#ifndef HW_MOTOR_DEVICE_H
#define HW_MOTOR_DEVICE_H

#include "ihardwaredevice.h"

namespace device {

class HardwareMotorDevice: public IHardwareDevice {
public:
    HardwareMotorDevice(int deviceId);
};

}

#endif // HW_MOTOR_DEVICE_H
