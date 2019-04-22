#include "motoraction.h"
#include "logicalmotordevice.h"

void action::MotorAction::playAtTime(unsigned long time)
{
    currentAngle = interpolateValue(startAngle, endAngle, startTime, duration, time);
}

void action::MotorAction::updateLogicalDevice(device::ILogicalDevice* logicalDevice)
{
    device::LogicalMotorDevice* logicalMotorDevice = static_cast<device::LogicalMotorDevice*>(logicalDevice);

    logicalMotorDevice->angle = currentAngle;
}
