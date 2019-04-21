#ifndef DEVICES_MANAGER_H
#define DEVICES_MANAGER_H

#include "array.h"

namespace device {

struct IHWDevice;
class ILogicalDevice;

class DevicesManager {
public:
    void addLogicalDevice(ILogicalDevice* logicalDevice);

private:
    Array<IHWDevice*>m_hardwareDevices;
};

} // namespace device

#endif // DEVICES_MANAGER_H
