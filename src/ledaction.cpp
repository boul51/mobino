#include "ledaction.h"
#include "logicalleddevice.h"

void action::LedAction::playAtTime(int64_t time)
{
    currentColor.r = interpolateValue<uint8_t>(startColor.r, endColor.r, startTime, duration, time);
    currentColor.g = interpolateValue<uint8_t>(startColor.g, endColor.g, startTime, duration, time);
    currentColor.b = interpolateValue<uint8_t>(startColor.b, endColor.b, startTime, duration, time);
}

void action::LedAction::updateLogicalDevice(device::ILogicalDevice *logicalDevice)
{
    device::LogicalLedDevice* logicalLedDevice = static_cast<device::LogicalLedDevice*>(logicalDevice);

    logicalLedDevice->redValue = currentColor.r;
    logicalLedDevice->greenValue = currentColor.g;
    logicalLedDevice->blueValue = currentColor.b;
}
