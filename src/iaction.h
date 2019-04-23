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
    virtual void playAtTime(int64_t time) = 0;
    virtual void updateLogicalDevice(device::ILogicalDevice* logicalDevice) = 0;
    int64_t startTime = 0;
    int64_t duration = 0;

    template <class T>
    T interpolateValue(T startValue, T endValue, int64_t startTime, int64_t duration, int64_t curTime) {
        if (curTime <= startTime)
            return startValue;
        else if (curTime >= startTime + duration)
            return endValue;
        else
            return startValue + (endValue - startValue) * (curTime - startTime) / (duration);
    }
};

} // namespace action

#endif // IACTION_H
