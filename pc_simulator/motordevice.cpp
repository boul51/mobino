#include "motordevice.h"

MotorDevice::MotorDevice(QObject* parent, QSharedPointer<QFile>file):
    IDevice(parent, file)
{

}

void MotorDevice::updateValuesFromTokens(const QStringList& tokens)
{

}
