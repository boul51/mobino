#include "ledaction.h"

action::LedAction::LedAction(uint8_t i2cBus, uint8_t ledIndex):
    i2cBus(i2cBus),
    ledIndex(ledIndex)
{

}

void action::LedAction::playAtTime(int64_t time)
{
    currentColor.r = interpolateValue<uint8_t>(startColor.r, endColor.r, startTime, duration, time);
    currentColor.g = interpolateValue<uint8_t>(startColor.g, endColor.g, startTime, duration, time);
    currentColor.b = interpolateValue<uint8_t>(startColor.b, endColor.b, startTime, duration, time);
}
