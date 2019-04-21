#include "hardwaredevicefactory.h"

#include "ihardwaredevice.h"
#include "ilogicaldevice.h"

#include "logicalleddevice.h"
#include "logicalmotordevice.h"

#include "hardwareleddevice.h"
#include "hardwaremotordevice.h"

namespace device {

IHardwareDevice* HardwareDeviceFactory::createHardwareDeviceForLogicalDevice(const ILogicalDevice &logicalDevice)
{
    switch (logicalDevice.deviceType) {
    case DeviceType::Led:
        return new HardwareLedDevice(logicalDevice.deviceId);
    case DeviceType::Motor:
        return new HardwareMotorDevice(logicalDevice.deviceId);
    default:
        return nullptr;
    }
}

} // namespace device
