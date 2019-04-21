#ifndef LOGICAL_LED_DEVICE_H
#define LOGICAL_LED_DEVICE_H

#include "ilogicaldevice.h"

#include <stdint.h>

namespace device {

class LogicalLedDevice: public ILogicalDevice {
public:
    LogicalLedDevice(int deviceId, int ledIndex);

    int ledIndex = 0;

    uint8_t redValue = 0;
    uint8_t greenValue = 0;
    uint8_t blueValue = 0;
};

} // namespace device

#endif // LOGICAL_LED_DEVICE_H
