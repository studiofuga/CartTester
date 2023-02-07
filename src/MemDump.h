//
// Created by happycactus on 27/01/23.
//

#ifndef CARTTESTER_MEMDUMP_H
#define CARTTESTER_MEMDUMP_H

class DigitalBus;
class BankSwitcher;

class MemDump {
    unsigned int address = 0;
    char fmtBuffer[256];
    uint16_t romLimit = 2*1024;
    uint16_t romBase = 0x1000;

    DigitalBus &bus;
    BankSwitcher &bankSwitcher;
public:
    explicit MemDump(DigitalBus &bus, BankSwitcher &switcher);

    void setRomSize(uint16_t size) { romLimit = size; }
    void setRomBase(uint16_t base) { romBase = base; }

    bool doStep();
};


#endif //CARTTESTER_MEMDUMP_H
