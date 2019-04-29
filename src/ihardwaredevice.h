#ifndef IHARDWARE_DEVICE_H
#define IHARDWARE_DEVICE_H

#include "devicetype.h"
#include "array.h"

#ifdef PC_BUILD
#include <QFile>
#include <QString>
#include "debug.h"
#endif


namespace device {

class ILogicalDevice;

class IHardwareDevice {
public:
    IHardwareDevice(DeviceType deviceType, int deviceId):
        deviceType(deviceType),
        deviceId(deviceId)
    {
        createOutputFile();
    }

    void appendLogicalDevice(ILogicalDevice* logicalDevice)
    {
        m_logicalDevices.append(logicalDevice);
    }

#ifdef PC_BUILD
    bool createOutputFile() {
        QString fileName = QString().sprintf("/tmp/mobino-dev-%02d-%02d.txt",static_cast<int>(deviceType), deviceId);
        m_outputFile.setFileName(fileName);
        if (!m_outputFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            logmsg("Failed opening device file\n");
            return false;
        }
        return true;
    }
#endif

    virtual void initDevice() = 0;
    virtual void updateOutput() = 0;

    DeviceType deviceType = DeviceType::Invalid;
    int deviceId = -1;

protected:
    Array<ILogicalDevice*> m_logicalDevices;
#ifdef PC_BUILD
    QFile m_outputFile;
#endif
};

} // namespace device

#endif // IHARDWARE_DEVICE_H
