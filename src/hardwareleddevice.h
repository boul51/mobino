#ifndef HW_LED_DEVICE_H
#define HW_LED_DEVICE_H

#include "ihardwaredevice.h"

#ifndef PC_BUILD
#include "Adafruit_NeoPixel.h"
#endif

namespace device {

class HardwareLedDevice: public IHardwareDevice {
public:
    HardwareLedDevice(int deviceId);
    void initDevice() override;
    void updateOutput() override;

private:
#ifndef PC_BUILD
    Adafruit_NeoPixel* m_strip = nullptr;
#endif
};

}

#endif // HW_LED_DEVICE_H
