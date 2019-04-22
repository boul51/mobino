#ifndef ISHOW_MANAGER_H
#define ISHOW_MANAGER_H

#include <stdint.h>

#include "array.h"

namespace device {
class ILogicalDevice;
}

namespace show {

class Track;

class IShowManager {
public:
    void playAtTime(int time);
    void createTracksForDevices(Array<device::ILogicalDevice *> &devices);
    virtual void generateTracksActions(int64_t time, const Array<device::ILogicalDevice*>& devices) = 0;

    Array<Track*> tracks;
};

} // namespace show

#endif // ISHOW_MANAGER_H