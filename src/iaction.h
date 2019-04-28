#ifndef ACTION_IACTION_H
#define ACTION_IACTION_H

#include <stdint.h>

namespace device {
    class ILogicalDevice;
} // namespace device

namespace action {

class IAction {
public:
    virtual ~IAction() {}
    virtual void playAtTime(uint32_t time) = 0;
    virtual void updateLogicalDevice(device::ILogicalDevice* logicalDevice) = 0;
    uint32_t startTime = 0;
    uint32_t duration = 0;

    template <class T>
    T interpolateValue(T startValue, T endValue, uint32_t startTime, uint32_t duration, uint32_t curTime) {
        if (curTime <= startTime)
            return startValue;
        else if (curTime >= startTime + duration)
            return endValue;
        else if (endValue >= startValue)
            return startValue + (endValue - startValue) * (curTime - startTime) / (duration);
        else
            return startValue - (startValue - endValue) * (curTime - startTime) / (duration);
    }
};

} // namespace action

#endif // IACTION_H
