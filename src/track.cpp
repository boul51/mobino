#include "track.h"

namespace show {

Track::Track(device::ILogicalDevice *logicalDevice):
    logicalDevice(logicalDevice)
{
}

void Track::appendAction(action::IAction *action)
{
    actions.append(action);

    if (actions.length() > 2) {
        delete actions.at(0);
        actions.removeAt(0);
    }
}

action::IAction *Track::activeActionAtTime(int64_t time)
{
    action::IAction* activeAction = nullptr;

    for (int i = 0; i < actions.length(); i++) {
        action::IAction* action = actions.at(i);
        if (time >= action->startTime && time <= action->startTime + action->duration) {
            // Don't return, we want to get the last active one if there are several (useful for transitions)
            activeAction = action;
        }
    }

    return activeAction;
}

action::IAction *Track::prevActiveActionAtTime(int64_t time)
{
    action::IAction* activeAction = activeActionAtTime(time);
    if (activeAction) {
        int activeIndex = actions.indexOf(activeAction);
        if (activeIndex > 0)
            return actions.at(activeIndex - 1);
    }
    else if (actions.length() > 0) {
        action::IAction* lastActiveAction = actions.at(actions.length() - 1);
        if (lastActiveAction->startTime < time)
            return lastActiveAction;
    }

    return nullptr;
}

void Track::playAtTime(int64_t time)
{
    action::IAction* activeAction = activeActionAtTime(time);

    if (activeAction) {
        activeAction->playAtTime(time);
        activeAction->updateLogicalDevice(logicalDevice);
    }
}

} // namespace show
