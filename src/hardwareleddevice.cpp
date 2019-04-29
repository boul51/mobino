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

#ifndef PC_BUILD

void HardwareLedDevice::updateOutput()
{
    for (int i = 0; i < m_logicalDevices.length(); i++) {
        LogicalLedDevice* logicalLedDevice = static_cast<LogicalLedDevice*>(m_logicalDevices.at(i));
        m_strip->setPixelColor(logicalLedDevice->ledIndex, logicalLedDevice->redValue, logicalLedDevice->greenValue, logicalLedDevice->blueValue);
    }

    m_strip->show();
}

#else

void HardwareLedDevice::updateOutput()
{
    QString s;

    for (int i = 0; i < m_logicalDevices.length(); i++) {
        LogicalLedDevice* logicalLedDevice = static_cast<LogicalLedDevice*>(m_logicalDevices.at(i));
        s.append(QString().sprintf("%d %d %d %d %d\n",
                                   logicalLedDevice->position.x, logicalLedDevice->position.y,
                                   logicalLedDevice->redValue, logicalLedDevice->greenValue, logicalLedDevice->blueValue));
    }

    m_outputFile.seek(0);
    m_outputFile.write(s.toLatin1());
    m_outputFile.flush();
}

#endif

} // namespace device
