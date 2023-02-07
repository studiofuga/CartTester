//
// Created by happycactus on 27/01/23.
//

#include "Arduino.h"

#include "MemDump.h"
#include "DigitalBus.h"
#include "BankSwitcher.h"

#define BYTES_PER_LINE 16

MemDump::MemDump(DigitalBus &bus, BankSwitcher &switcher) : bus(bus),  bankSwitcher(switcher)
{

}

bool MemDump::doStep()
{
    sprintf(fmtBuffer, "%04x  ", address);
    Serial.print(fmtBuffer);

    unsigned char bt[BYTES_PER_LINE];
    for (unsigned char & i : bt) {
        bool enabled = (address >= romBase);
        uint16_t currentbank = bankSwitcher.currentBank();
        uint16_t bank = (address >> 12) - 1;

        if (bank != currentbank) {
            bankSwitcher.switchBank(bank);
        }

        uint16_t mask = 0;
        if (enabled) {
            mask = 1<<12;
        }

        bus.address((address & 0x0fff) | mask);
        i = bus.data();
        sprintf(fmtBuffer, "%02x ", i);
        Serial.print(fmtBuffer);
        ++address;

        delay(1);
    }

    Serial.println();

    return (address < romBase+romLimit);
}
