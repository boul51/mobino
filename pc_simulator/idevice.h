#ifndef IDEVICE_H
#define IDEVICE_H

#include <QObject>
#include <QPoint>
#include <QSharedPointer>
#include <QByteArray>

class  QFile;

class IDevice : public QObject
{
    Q_OBJECT
public:
    Q_ENUMS(DeviceType)

    Q_PROPERTY(DeviceType deviceType READ deviceType CONSTANT)
    Q_PROPERTY(int x READ x NOTIFY positionChanged)
    Q_PROPERTY(int y READ y NOTIFY positionChanged)

    enum class DeviceType {
        Invalid,
        Led,
        Motor
    };
    explicit IDevice(QObject *parent, QSharedPointer<QFile> file);
    void setPosition(const QPoint position) {
        if (m_position != position) {
            m_position = position;
            emit positionChanged();
        }
    }
    virtual DeviceType deviceType() const { return DeviceType::Invalid; }
    virtual void updateValuesFromTokens(const QStringList& tokens) = 0;

    int x() const { return m_position.x(); }
    int y() const { return m_position.y(); }

    QFile* filePtr() { return m_file.get(); }

signals:
    void positionChanged();

public slots:

private:
    QPoint m_position;
    QSharedPointer<QFile> m_file;
};

#endif // IDEVICE_H
