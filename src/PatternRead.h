//
// Created by happycactus on 01/02/23.
//

#ifndef CARTTESTER_PATTERNREAD_H
#define CARTTESTER_PATTERNREAD_H

class DigitalBus;

class PatternRead {
    bool initialized = false;
    DigitalBus &bus;

    unsigned int address1 = 0;
    unsigned int address2 = 0;
public:
    explicit PatternRead(DigitalBus &bus);

    void setup();
    bool doStep();
};


#endif //CARTTESTER_PATTERNREAD_H
