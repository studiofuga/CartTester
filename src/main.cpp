#include <Arduino.h>

#include "DigitalBus.h"
#include "MemDump.h"
#include "IoTester.h"
#include "PatternRead.h"

DigitalBus bus;
MemDump memDump(bus);
IoTester ioTester(bus);
PatternRead patternRead(bus);

void setupPinout()
{
/*
    char buf[256];
    for (int i = 0; i < 53; ++i) {
        sprintf(buf, "Pin %d: %d %d", i, digitalPinToPort(i), digitalPinToBitMask(i));
        Serial.println(buf);
    }
*/

    bus.setup();
    delay(1000);
}

void setup() {
    Serial.begin(115200);
    Serial.println("\n\nAtari Cart Tester v1");

    setupPinout();
}

void loop() {
    if(!memDump.doStep()) {
        Serial.println("End of test.");
        while(true) {
            delay(1000);
        }
    }
}
