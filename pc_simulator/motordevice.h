#ifndef MOTORDEVICE_H
#define MOTORDEVICE_H

#include "idevice.h"

class MotorDevice : public IDevice
{
    Q_OBJECT
public:
    explicit MotorDevice(QObject* parent, QSharedPointer<QFile> file);
    IDevice::DeviceType deviceType() const override { return IDevice::DeviceType::Motor; }
    void updateValuesFromTokens(const QStringList& tokens) override;
};

#endif // MOTORDEVICE_H
