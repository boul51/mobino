#ifndef PRINTINT_H
#define PRINTINT_H

#include <stdint.h>

class PrintInt {
public:
    static void printInt(int base, uint64_t num)
    {
        const static char toAscii[] = "0123456789ABCDEF";

        if ((base < 2) || (base>16))
        {
            Serial.print("[DON'T USE THAT BASE!!!]");
            return;
        }

        char buffer[65];            //because you might be doing binary
        char* p = &buffer[64];      //this pointer writes into the buffer, starting at the END

        // zero to terminate a C type string
        *p = 0;

        // do digits until the number reaches zero
        do
        {
            // working on the least significant digit
            //put an ASCII digit at the front of the string
            *(--p) = toAscii[(int)(num % base)];

            //knock the least significant digit off the number
            num = num / base;
        } while (num != 0);

        //print the whole string
        Serial.println(p);
    }
};

#endif // PRINTINT_H
