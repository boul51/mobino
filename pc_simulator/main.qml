import QtQuick 2.6
import QtQuick.Window 2.2
import bouleane.fr 1.0

Window {
    id: root
    visible: true
    width: 255
    height: 255

    //devicesManager.size:

    Connections {
        target: devicesManager
        onDevicesChanged: canvas.requestPaint()
        onValuesChanged: canvas.requestPaint()
    }

    Rectangle {
        anchors.fill: parent

        Canvas {
            id: canvas
            anchors.fill: parent

            function drawBackground(ctx) {
                ctx.fillStyle = Qt.rgba(0, 0, 0, 1);
                ctx.fillRect(0, 0, width, height);
            }

            function drawLedDevice(ctx, device) {
                var radius = 3;
                ctx.beginPath();
                ctx.fillStyle = Qt.rgba(device.r / 255, device.g / 255, device.b / 255, 1)
                ctx.moveTo(device.x, device.y);
                ctx.arc(device.x, device.y, radius, 0, Math.PI * 2, false);
                ctx.fill();
            }

            function drawMotorDevice(ctx, idevice) {
                var motorDevice = idevice;
            }

            onPaint: {
                var ctx = getContext("2d");
                ctx.reset();

                drawBackground(ctx)

                for (var i = 0; i < devicesManager.devices.length; i++) {
                    var device = devicesManager.devices[i]
                    switch (device.deviceType) {
                    case IDevice.Led:
                        drawLedDevice(ctx, device)
                        break
                    case IDevice.Motor:
                        drawMotorDevice(ctx, device)
                        break
                    default:
                        break
                    }
                }
            }
        }
    }
}
