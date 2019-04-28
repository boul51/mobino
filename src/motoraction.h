#ifndef MOTOR_ACTION_H
#define MOTOR_ACTION_H

#include "iaction.h"

namespace action {

class MotorAction: public action::IAction {
public:
    void playAtTime(uint32_t time);
    void updateLogicalDevice(device::ILogicalDevice *logicalDevice) override;

    uint8_t startAngle = 90;
    uint8_t endAngle = 90;
    uint8_t currentAngle = 90;
};

}

#endif // MOTOR_ACTION_H
