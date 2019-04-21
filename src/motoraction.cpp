#include "motoraction.h"

action::MotorAction::MotorAction(int digitalOutput):
    digitalOutput(digitalOutput)
{
}

void action::MotorAction::playAtTime(int64_t time)
{
    currentAngle = interpolateValue(startAngle, endAngle, startTime, duration, time);
}
