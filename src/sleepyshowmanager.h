#ifndef SLEEPY_SHOW_MANAGER_H
#define SLEEPY_SHOW_MANAGER_H

#include "ishowmanager.h"

namespace show {

class SleepyShowManager: public IShowManager {
public:
    void generateTracksActions(uint32_t time) override;
};

} // namespace show

#endif // SLEEPY_SHOW_MANAGER_H
