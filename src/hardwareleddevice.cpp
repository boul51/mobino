#include "hardwareleddevice.h"
#include "logicalleddevice.h"

#ifdef PC_BUILD
#include <stdio.h>
#endif

namespace device {

HardwareLedDevice::HardwareLedDevice(int deviceId):
    IHardwareDevice(DeviceType::Led, deviceId)
{
}

void HardwareLedDevice::initDevice()
{
#ifndef PC_BUILD
    m_strip = new Adafruit_NeoPixel(m_logicalDevices.length(), deviceId, NEO_GRB + NEO_KHZ800);
    m_strip->begin();
    m_strip->show();
#endif
}

void HardwareLedDevice::updateOutput()
{
    for (int i = 0; i < m_logicalDevices.length(); i++) {
        LogicalLedDevice* logicalLedDevice = static_cast<LogicalLedDevice*>(m_logicalDevices.at(i));
#ifndef PC_BUILD
        m_strip->setPixelColor(logicalLedDevice->ledIndex, logicalLedDevice->redValue, logicalLedDevice->greenValue, logicalLedDevice->blueValue);
#else
        fprintf(stdout, "Setting pixel color, dev id %d, pixel %d, r %d, g %d, b %d\n", logicalLedDevice->deviceId, logicalLedDevice->ledIndex,
                logicalLedDevice->redValue, logicalLedDevice->greenValue, logicalLedDevice->blueValue);
#endif
    }

#ifndef PC_BUILD
    m_strip->show();
#endif
}

} // namespace device
