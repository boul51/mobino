#ifndef HW_MOTOR_DEVICE_H
#define HW_MOTOR_DEVICE_H

#include "ihwdevice.h"

namespace device {

struct HwMotorDevice: public IHwDevice {
    int pin;
};

}

#endif // HW_MOTOR_DEVICE_H
