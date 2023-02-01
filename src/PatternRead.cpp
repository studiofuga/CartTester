//
// Created by happycactus on 01/02/23.
//

#include "PatternRead.h"
#include "Arduino.h"
#include "DigitalBus.h"

PatternRead::PatternRead(DigitalBus &bus) : bus(bus)
{

}

void PatternRead::setup()
{
    initialized = true;
    address1 = 01;
    address2 = address1 | (1<<12);
}

bool PatternRead::doStep()
{
    if (!initialized) {
        setup();
    }

    bus.address(address1 |1);
    address1 = (address1 << 1);
    if (address1 == 0) {
        address1 = 1;
    }



    uint8_t data1 = bus.data();
//    bus.address(address2);
    uint8_t data2 = bus.data();

    char fmtBuffer[32];
    sprintf(fmtBuffer, "%04x %02x: %04x %02x\r", address1, data1, address2, data2);
    Serial.println(fmtBuffer);

    delay(1);

    return true;
}