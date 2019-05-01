/*___________________________________________________________________________________
Exemple de patron de programme BLINK, avec QtCreator

Modifications à apporter au projet (bandeau de gauche):
Dans l'option compiler, Répertoire de compilation: ajouter /src à la fin du chemin
                        Etape de compilation: make upload
                        Etape de nettoyage : make clean
Dans l'option exécuter: make monitor

Si vous utilisez un Nano 328, la définition dans le makefile est:
# Avrdude code for programming
BOARD_TAG               = nano
MCU                     = atmega328p
ARDUINO_PORT            = /dev/ttyUSB0
AVRDUDE_ARD_PROGRAMMER  = arduino
AVRDUDE_ARD_BAUDRATE    = 57600
MONITOR_CMD             = gtkterm
MONITOR_BAUDRATE        = 115200
____________________________________________________________________________________*/

#include "includes.h"
#include "debug.h"
#include "funcs.h"
#include "array.h"
#include "ledaction.h"
#include "logicalleddevice.h"
#include "logicalmotordevice.h"
#include "devicesmanager.h"
#include "sleepyshowmanager.h"

/*
#define     LED_PIN     13
pinMode(LED_PIN, OUTPUT);
digitalWrite(LED_PIN, HIGH);
*/

#define NEOPIXEL_PIN 2
#define MOTOR_PWM_PIN 11

int main()
{
    // Init arduino lib, no op on PC
    initArduinoLib();

    initSerial();

    logmsg("Starting application");

    device::DevicesManager devicesManager;

    // Add devices
    for (int led = 0; led < 11; led++) {
        auto ledDevice = new device::LogicalLedDevice(NEOPIXEL_PIN, led);
#ifdef PC_BUILD
        int ledsPerLine = 11;
        int line = led / ledsPerLine;
        int col = led % ledsPerLine;
        ledDevice->position.x = (col + 1) * 20;
        ledDevice->position.y = (line + 1) * 20;
#endif
        devicesManager.addLogicalDevice(ledDevice);
    }

    devicesManager.addLogicalDevice(new device::LogicalMotorDevice(MOTOR_PWM_PIN));

    devicesManager.initDevices();

    show::SleepyShowManager showManager;

    showManager.createTracksForDevices(devicesManager.logicalDevices());

    while (true) {
        uint32_t time = getMillis();
        showManager.generateTracksActions(time);
        showManager.playAtTime(time);
        devicesManager.updateOutputsFromDevices();
    }

    flushSerial();
}
