#ifndef HARDWARE_DEVICE_FACTORY_H
#define HARDWARE_DEVICE_FACTORY_H

namespace device {

class IHardwareDevice;
class ILogicalDevice;

class HardwareDeviceFactory {
public:
    static IHardwareDevice* createHardwareDeviceForLogicalDevice(const ILogicalDevice& logicalDevice);
};

} // namespace device

#endif // HARDWARE_DEVICE_FACTORY_H
