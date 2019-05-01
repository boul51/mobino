#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>

#include "devicesmanager.h"
#include "idevice.h"
#include "leddevice.h"
#include "motordevice.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterUncreatableType<DevicesManager>("bouleane.fr", 1, 0, "DevicesManager", "Cannot create type from qml");
    qmlRegisterUncreatableType<IDevice>("bouleane.fr", 1, 0, "IDevice", "Cannot create type from qml");
    qmlRegisterUncreatableType<LedDevice>("bouleane.fr", 1, 0, "LedDevice", "Cannot create type from qml");
    qmlRegisterUncreatableType<MotorDevice>("bouleane.fr", 1, 0, "MotorDevice", "Cannot create type from qml");

    DevicesManager devicesManager;
    devicesManager.init();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("devicesManager", &devicesManager);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
