#include "logicalleddevice.h"

namespace device {

LogicalLedDevice::LogicalLedDevice(int deviceId, int ledIndex):
    ILogicalDevice(DeviceType::Led, deviceId),
    ledIndex(ledIndex)
{
}

} // namespace device
