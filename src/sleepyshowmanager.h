#ifndef SLEEPY_SHOW_MANAGER_H
#define SLEEPY_SHOW_MANAGER_H

#include "ishowmanager.h"

namespace show {

class SleepyShowManager: public IShowManager {
public:
    void generateTracksActions(int64_t time, const Array<device::ILogicalDevice *> &devices) override;
};

} // namespace show

#endif // SLEEPY_SHOW_MANAGER_H
