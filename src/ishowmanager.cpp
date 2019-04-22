#include "ishowmanager.h"
#include "track.h"

namespace show {

void IShowManager::createTracksForDevices(Array<device::ILogicalDevice *> &devices)
{
    for (int i = 0; i < devices.length(); i++) {
        Track* track = new Track(devices.at(i));
        tracks.append(track);
    }
}

} // namespace show
