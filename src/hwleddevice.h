#ifndef HW_LED_DEVICE_H
#define HW_LED_DEVICE_H

#include "ihwdevice.h"

namespace device {

struct HwLedDevice: public IHwDevice {
    int pin;
};

}

#endif // HW_LED_DEVICE_H
