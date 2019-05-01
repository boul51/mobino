#ifndef LEDDEVICE_H
#define LEDDEVICE_H

#include "idevice.h"

class LedDevice : public IDevice
{
    Q_OBJECT
public:
    Q_PROPERTY(int r READ r NOTIFY colorChanged)
    Q_PROPERTY(int g READ g NOTIFY colorChanged)
    Q_PROPERTY(int b READ b NOTIFY colorChanged)

    explicit LedDevice(QObject *parent, QSharedPointer<QFile> file);
    IDevice::DeviceType deviceType() const override { return IDevice::DeviceType::Led; }
    void updateValuesFromTokens(const QStringList& tokens) override;

    int r() { return m_r; }
    int g() { return m_g; }
    int b() { return m_b; }

signals:
    void colorChanged();

private:
    int m_r = 100;
    int m_g = 0;
    int m_b = 0;

};

#endif // LEDDEVICE_H
