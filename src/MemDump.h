//
// Created by happycactus on 27/01/23.
//

#ifndef CARTTESTER_MEMDUMP_H
#define CARTTESTER_MEMDUMP_H

class DigitalBus;

class MemDump {
    unsigned int address = 0;
    char fmtBuffer[256];

    DigitalBus &bus;
public:
    explicit MemDump(DigitalBus &bus);

    bool doStep();
};


#endif //CARTTESTER_MEMDUMP_H
