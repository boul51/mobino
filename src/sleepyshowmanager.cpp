#include "sleepyshowmanager.h"

#include "ledaction.h"
#include "motoraction.h"
#include "track.h"
#include "ilogicaldevice.h"
#include "devicetype.h"

namespace show {

void show::SleepyShowManager::generateTracksActions(int64_t time)
{
    for (int i = 0; i < tracks.length(); i++) {
        show::Track* track = tracks.at(i);
        action::IAction* newAction = nullptr;
        action::IAction* prevAction = track->prevActiveActionAtTime(time);
        if (!track->activeActionAtTime(time)) {
            switch (track->logicalDevice->deviceType) {
            case device::DeviceType::Led:
              {
                action::LedAction* prevLedAction = static_cast<action::LedAction*>(prevAction);
                newAction = new action::LedAction();
                break;
              }
            case device::DeviceType::Motor:
                break;
            default:
                break;
            }
            tracks.at(i)->appendAction(newAction);
        }
    }
}

} // namespace show
