#include "logicalmotordevice.h"

namespace device {

LogicalMotorDevice::LogicalMotorDevice(int deviceId):
    ILogicalDevice(DeviceType::Motor, deviceId)
{
}

} // namespace device
