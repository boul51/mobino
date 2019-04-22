#include "sleepyshowmanager.h"

#include "ledaction.h"
#include "motoraction.h"
#include "track.h"

namespace show {

void show::SleepyShowManager::generateTracksActions(int64_t time, const Array<device::ILogicalDevice *> &devices)
{
    for (int i = 0; i < tracks.length(); i++) {
        show::Track* track = tracks.at(i);
        if (!track->hasActiveActionAtTime(time)) {
            tracks.at(i)->appendAction(new action::LedAction());
        }
    }
}

} // namespace show
