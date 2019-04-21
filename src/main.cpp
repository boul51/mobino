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

    devicesManager.addLogicalDevice(new device::LogicalLedDevice(0, 0));
    devicesManager.addLogicalDevice(new device::LogicalLedDevice(0, 1));
    devicesManager.addLogicalDevice(new device::LogicalLedDevice(1, 0));
    devicesManager.addLogicalDevice(new device::LogicalMotorDevice(10));
    devicesManager.addLogicalDevice(new device::LogicalMotorDevice(11));

    Serial.print("hw devices count: ");
    Serial.println(devicesManager.hardwareDevices().length());

    Serial.flush();
}
