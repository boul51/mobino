#include "devicesmanager.h"

#include <QDebug>
#include <QString>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <memory>

#include "leddevice.h"
#include "motordevice.h"

DevicesManager::DevicesManager(QObject *parent) : QObject(parent)
{
    connect(&m_watcher, &QFileSystemWatcher::fileChanged, this, &DevicesManager::onFileChanged);
}

void DevicesManager::init()
{
    updateFilesList();
    updateDevicesList();
}

void DevicesManager::onFileChanged(const QString &path)
{
    updateDevicesValues(path);
}

IDevice* DevicesManager::createDevice(QString deviceTypeString, QSharedPointer<QFile> file, int x, int y)
{
    IDevice* device;
    if (deviceTypeString == "Led")
        device = new LedDevice(this, file);
    else if (deviceTypeString == "Motor")
        device = new MotorDevice(this, file);

    device->setPosition(QPoint(x, y));

    return device;
}

IDevice *DevicesManager::deviceForFile(QFile *file, int deviceIndex)
{
    QList<IDevice*>devicesForFile;
    for (auto device: m_devicesList)
        if (device->filePtr() == file)
            devicesForFile.append(device);

    if (deviceIndex >= devicesForFile.length())
        return nullptr;

    return devicesForFile[deviceIndex];
}

void DevicesManager::updateDevicesList()
{
    for (auto f: m_filesList) {
        QString deviceTypeString;
        QStringList headerFields = QString::fromLatin1(f->readLine()).trimmed().split(" ");
        if (headerFields.length() == 0) {
            qDebug() << "Header is empty";
        }
        else {
            deviceTypeString = headerFields[0];
        }
        headerFields.removeFirst();

        int devicesCount = headerFields.count() / 2;

        for (int i = 0; i < devicesCount; i++) {
            int x = headerFields.first().toInt();
            headerFields.removeFirst();
            int y = headerFields.first().toInt();
            headerFields.removeFirst();
            m_devicesList.append(createDevice(deviceTypeString, f, x, y));
        }
    }

    emit devicesChanged();
}

void DevicesManager::updateFilesList()
{
    const QString dirName = "/tmp";
    const QString fileNameFilter = "mobino-dev*";
    QStringList filesNames;

    QDir d(dirName);
    filesNames = d.entryList(QStringList{fileNameFilter}, QDir::Files);

    for (auto fileName: filesNames) {
        QString fullFileName = dirName + "/" + fileName;
        auto p = QSharedPointer<QFile>(new QFile(dirName + "/" + fileName));
        if (p->open(QIODevice::ReadOnly)) {
            m_watcher.addPath(fullFileName);
            qDebug() << "Appended file" << fullFileName;
            m_filesList << p;
        }
        else {
            qDebug() << "Failed opening file " << p->fileName();
        }
    }
}

void DevicesManager::updateDevicesValues(const QString &path)
{
    QFile* f = fileForPath(path);
    if (!f) {
        qDebug() << "No file found for path" << path;
        return;
    }

    f->seek(0);
    f->readLine(); // Skip header

    int i = 0;
    do {
        QString s = QString::fromLatin1(f->readLine()).simplified();;
        if (s.isEmpty())
            break;
        auto device = deviceForFile(f, i++);
        if (!device) {
            qDebug() << "No device found for file" << path << "at index" << i;
            break;
        }
        device->updateValuesFromTokens(s.split(" "));
    } while (true);

    emit valuesChanged();
}

QFile *DevicesManager::fileForPath(const QString &path)
{
    auto it = std::find_if(m_filesList.begin(), m_filesList.end(), [path](QSharedPointer<QFile> file) {
            return file->fileName() == path;
    });

    return (it != m_filesList.end() ? it->get() : nullptr);

}
