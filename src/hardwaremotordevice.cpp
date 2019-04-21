#include "hardwaremotordevice.h"

namespace device {

HardwareMotorDevice::HardwareMotorDevice(int deviceId):
    IHardwareDevice(DeviceType::Motor, deviceId)
{
}

} // namespace device
