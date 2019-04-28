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
    action::IAction* activeActionAtTime(uint32_t time);
    action::IAction* prevActiveActionAtTime(uint32_t time);
    void playAtTime(uint32_t time);

    device::ILogicalDevice* logicalDevice = nullptr;
    Array<action::IAction*> actions;
};

} // namespace show

#endif // SHOW_TRACK_H
