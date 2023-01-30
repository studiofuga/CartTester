//
// Created by happycactus on 27/01/23.
//

#include "MemDump.h"
#include "Arduino.h"
#include "DigitalBus.h"

#define BYTES_PER_LINE 16

MemDump::MemDump(DigitalBus &bus) : bus(bus)
{

}

bool MemDump::doStep()
{
    sprintf(fmtBuffer, "%04x  ", address);
    Serial.print(fmtBuffer);

    unsigned char bt[BYTES_PER_LINE];
    for (unsigned char & i : bt) {
        bus.address(address);
        i = bus.data();
        sprintf(fmtBuffer, "%02x ", i);
        Serial.print(fmtBuffer);
        ++address;

        delay(1);
    }

    Serial.println();

    return (address < 8*1024);
}
