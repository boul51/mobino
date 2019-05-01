#include "idevice.h"

IDevice::IDevice(QObject *parent, QSharedPointer<QFile> file) :
    QObject(parent),
    m_file(file)
{

}
