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


#include <Arduino.h>

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

int main()
{
    // Init arduino lib
    init();

    Serial.begin(115200);
    Serial.println("Starting application");

    device::DevicesManager devicesManager;

    // Add devices
    for (int led = 0; led < 12; led++)
        devicesManager.addLogicalDevice(new device::LogicalLedDevice(2, led));

    devicesManager.addLogicalDevice(new device::LogicalMotorDevice(11));

    devicesManager.initDevices();

    show::SleepyShowManager showManager;

    showManager.createTracksForDevices(devicesManager.logicalDevices());

    while (true) {
        int64_t time = (int64_t)millis();
        showManager.generateTracksActions(time);
        showManager.playAtTime(time);
        devicesManager.updateOutputsFromDevices();
    }

    Serial.flush();
}
