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
    void playAtTime(uint32_t time);
    void createTracksForDevices(Array<device::ILogicalDevice *> &devices);
    virtual void generateTracksActions(uint32_t time) = 0;

    Array<Track*> tracks;
};

} // namespace show

#endif // ISHOW_MANAGER_H
