#ifndef MOTOR_ACTION_H
#define MOTOR_ACTION_H

#include "iaction.h"

namespace action {

class MotorAction: public action::IAction {
public:
    uint8_t digitalOutput = 0;

    MotorAction(int digitalOutput);

    void playAtTime(int64_t time);

    uint8_t startAngle = 90;
    uint8_t endAngle = 90;
    uint8_t currentAngle = 90;
};

}

#endif // MOTOR_ACTION_H
