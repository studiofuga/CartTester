#include <Arduino.h>

#include "DigitalBus.h"
#include "MemDump.h"
#include "IoTester.h"
#include "PatternRead.h"
#include "SwitcherF8.h"

DigitalBus bus;
SwitcherF8 switcher(bus);
MemDump memDump(bus, switcher);
IoTester ioTester(bus);
PatternRead patternRead(bus);

static const uint16_t ROM_SIZE = 8*1024;
static const uint16_t ROM_BASE = 0x1000;

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

void setupRom()
{
    memDump.setRomSize(ROM_SIZE);
    memDump.setRomBase(ROM_BASE);
}

void setup() {
    Serial.begin(115200);
    Serial.println("\n\nAtari Cart Tester v1");

    setupPinout();
    setupRom();
}

void loop() {
    if(!memDump.doStep()) {
        Serial.println("End of test.");
        while(true) {
            delay(1000);
        }
    }
}
