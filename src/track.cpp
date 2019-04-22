#include "track.h"

namespace show {

Track::Track(device::ILogicalDevice *logicalDevice):
    logicalDevice(logicalDevice)
{
}

void Track::appendAction(action::IAction *action)
{
    actions.append(action);
}

bool Track::hasActiveActionAtTime(int64_t time)
{
    for (int i = 0; i < actions.length(); i++) {
        action::IAction* action = actions.at(i);
        if (time >= action->startTime && time <= action->startTime + action->duration)
            return true;
    }
    return false;
}

} // namespace show
