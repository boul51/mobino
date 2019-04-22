#include "ledaction.h"

void action::LedAction::playAtTime(int64_t time)
{
    currentColor.r = interpolateValue<uint8_t>(startColor.r, endColor.r, startTime, duration, time);
    currentColor.g = interpolateValue<uint8_t>(startColor.g, endColor.g, startTime, duration, time);
    currentColor.b = interpolateValue<uint8_t>(startColor.b, endColor.b, startTime, duration, time);
}
