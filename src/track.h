#ifndef SHOW_TRACK_H
#define SHOW_TRACK_H

#include <stdint.h>

#include "array.h"
#include "iaction.h"

namespace device {
class ILogicalDevice;
}

namespace show {

class Track {
public:
    Track(device::ILogicalDevice* logicalDevice);
    void appendAction(action::IAction* action);
    bool hasActiveActionAtTime(int64_t time);

    device::ILogicalDevice* logicalDevice = nullptr;
    Array<action::IAction*> actions;
};

} // namespace show

#endif // SHOW_TRACK_H
