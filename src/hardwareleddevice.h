#ifndef HW_LED_DEVICE_H
#define HW_LED_DEVICE_H

#include "ihardwaredevice.h"

namespace device {

class HardwareLedDevice: public IHardwareDevice {
public:
    HardwareLedDevice(int deviceId): IHardwareDevice(DeviceType::Led, deviceId)
    {
    }
};

}

#endif // HW_LED_DEVICE_H
