#include "hardwareleddevice.h"
#include "logicalleddevice.h"

namespace device {

HardwareLedDevice::HardwareLedDevice(int deviceId):
    IHardwareDevice(DeviceType::Led, deviceId)
{
}

#ifdef PC_BUILD

void HardwareLedDevice::initDevice()
{
}

void HardwareLedDevice::updateOutput()
{
}

#else

void HardwareLedDevice::initDevice()
{
    m_strip = new Adafruit_NeoPixel(m_logicalDevices.length(), deviceId, NEO_GRB + NEO_KHZ800);
    m_strip->begin();
    m_strip->show();
}

void HardwareLedDevice::updateOutput()
{
    for (int i = 0; i < m_logicalDevices.length(); i++) {
        LogicalLedDevice* logicalLedDevice = static_cast<LogicalLedDevice*>(m_logicalDevices.at(i));
        // Do the job here
        m_strip->setPixelColor(i, logicalLedDevice->redValue, logicalLedDevice->greenValue, logicalLedDevice->blueValue);
    }
    m_strip->show();
}

#endif

} // namespace device
