#ifndef HW_MOTOR_DEVICE_H
#define HW_MOTOR_DEVICE_H

#include "ihardwaredevice.h"

#ifndef PC_BUILD
#include "Servo.h"
#endif

namespace device {

class HardwareMotorDevice: public IHardwareDevice {
public:
    HardwareMotorDevice(int deviceId);

    void updateOutput() override;
    void initDevice() override;

private:
    Servo* m_servo = nullptr;
};

}

#endif // HW_MOTOR_DEVICE_H
