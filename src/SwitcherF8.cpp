//
// Created by happycactus on 07/02/23.
//

#include "SwitcherF8.h"

#include "Arduino.h"
#include "DigitalBus.h"

SwitcherF8::SwitcherF8(DigitalBus &bus) : bus(bus)
{

}

int SwitcherF8::currentBank() const
{
    return current_bank;
}

void SwitcherF8::switchBank(int bank)
{
    if (bank == current_bank) {
        return;
    }

    uint16_t addr;
    if ((bank & 0x01) == 0) {
        addr = 0x1ff8;
    } else {
        addr = 0x1ff9;
    }
    bus.address(addr);
    current_bank = bank;
}
