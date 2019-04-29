#include "hardwaremotordevice.h"
#include "logicalmotordevice.h"

namespace device {

HardwareMotorDevice::HardwareMotorDevice(int deviceId):
    IHardwareDevice(DeviceType::Motor, deviceId)
{
}

#ifndef PC_BUILD

void HardwareMotorDevice::initDevice()
{
    m_servo = new Servo();
    m_servo->attach(deviceId);
}

void HardwareMotorDevice::updateOutput()
{
    LogicalMotorDevice* logicalMotorDevice = static_cast<LogicalMotorDevice*>(m_logicalDevices.at(0));
    m_servo->write(logicalMotorDevice->angle);
}

#else

void HardwareMotorDevice::initDevice()
{
}

void HardwareMotorDevice::updateOutput()
{
    QString s;
    LogicalMotorDevice* logicalMotorDevice = static_cast<LogicalMotorDevice*>(m_logicalDevices.at(0));

    s.sprintf("%d %d %d\n",
              logicalMotorDevice->position.x, logicalMotorDevice->position.y,
              logicalMotorDevice->angle);

    m_outputFile.seek(0);
    m_outputFile.write(s.toLatin1());
    m_outputFile.flush();
}

#endif

} // namespace device
