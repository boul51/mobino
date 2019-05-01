#ifndef DEVICESMANAGER_H
#define DEVICESMANAGER_H

#include <QObject>
#include <QList>
#include <QFile>
#include <QFileSystemWatcher>
#include <QQmlListProperty>

#include <memory>

#include "idevice.h"

class DevicesManager : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QQmlListProperty<IDevice> devices READ qmlDevicesList)
    explicit DevicesManager(QObject *parent = nullptr);
    void init();

public slots:
    void onFileChanged(const QString& path);

signals:
    void devicesChanged();
    void valuesChanged();

private:
    QList<QSharedPointer<QFile>>m_filesList;
    QList<IDevice *>m_devicesList;
    QQmlListProperty<IDevice>qmlDevicesList() { return QQmlListProperty<IDevice>(this, m_devicesList); }
    QFileSystemWatcher m_watcher;

    IDevice* createDevice(QString deviceTypeString, QSharedPointer<QFile> file, int x, int y);
    IDevice* deviceForFile(QFile* file, int deviceIndex);
    void updateDevicesList();
    void updateFilesList();
    void updateDevicesValues(const QString& path);
    QFile* fileForPath(const QString& path);
};

#endif // DEVICESMANAGER_H
