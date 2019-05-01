#include "funcs.h"

#include <stdio.h>
#include <unistd.h>

#include "includes.h"

#ifndef PC_BUILD

// Function that printf and related will use to print
int serial_putchar(char c, FILE* f) {
    if (c == '\n')
        serial_putchar('\r', f);

    return Serial.write(c) == 1? 0 : 1;
}

void initArduinoLib()
{
    init();
}

void initSerial()
{
    static FILE serial_stdout;

    Serial.begin(115200);

    // Set up stdout
    fdev_setup_stream(&serial_stdout, serial_putchar, NULL, _FDEV_SETUP_WRITE);
    stdout = &serial_stdout;
}

void flushSerial()
{
    Serial.flush();
}

uint32_t getMillis()
{
    return millis();
}

#else

void initArduinoLib()
{
}

void initSerial()
{
}

void flushSerial()
{
}

uint32_t getMillis()
{
    constexpr int sleepTimeMs = 10;
    static int loops = 0;

    if (loops > 0)
        usleep(sleepTimeMs * 1000);

    return loops++ * sleepTimeMs;
}

#endif
