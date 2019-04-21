#include "hardwaremotordevice.h"
#include "logicalmotordevice.h"

namespace device {

HardwareMotorDevice::HardwareMotorDevice(int deviceId):
    IHardwareDevice(DeviceType::Motor, deviceId)
{
}

#ifdef PC_BUILD

void HardwareMotorDevice::initDevice()
{
}

void HardwareMotorDevice::updateOutput()
{
}

#else

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

#endif

} // namespace device
