#include "leddevice.h"

#include <QDebug>

LedDevice::LedDevice(QObject *parent, QSharedPointer<QFile> file) :
    IDevice(parent, file)
{

}

void LedDevice::updateValuesFromTokens(const QStringList &tokens)
{
    if (tokens.length() != 3) {
        qDebug() << Q_FUNC_INFO << "Invalid line" << tokens.join(" ");
        return;
    }
    m_r = tokens[0].toInt();
    m_g = tokens[1].toInt();
    m_b = tokens[2].toInt();

    emit colorChanged();
}
