//
// Created by happycactus on 30/01/23.
//

#include "IoTester.h"

#include "Arduino.h"
#include "DigitalBus.h"

IoTester::IoTester(DigitalBus &bus) : bus(bus)
{

}

void IoTester::setup()
{
    Serial.println("Data: 7 6 5 4 3 2 1 0");
    bus.address(0x0000);
}

bool IoTester::doStep()
{
    uint8_t data = bus.data();

    Serial.print("Data: ");

    // print the bits of data in reverse order
    for (int i = 7; i >= 0; i--) {
        Serial.print((data>>i) & 0x01);
        Serial.print(' ');
    }

    // print CR
    Serial.print('\r');
    delay(20);

    return true;
}

