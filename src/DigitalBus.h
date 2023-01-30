//
// Created by happycactus on 26/01/23.
//

#ifndef CARTTESTER_DIGITALBUS_H
#define CARTTESTER_DIGITALBUS_H


#include <stdint.h>

// Class that implements a simultaneous change of all output pins of the digital bus
class DigitalBus {
private:
    static const uint8_t AddressPin[13];
    static const uint8_t DataPin[8];

    bool outputPortDirty[16]{};
    uint8_t cachedOutputValues[16]{};

    void setAddressPin (uint8_t pin, uint8_t value);
    void commitAddress();
    uint8_t readDataPin(uint8_t pin);

public:
    DigitalBus();

    void setup();
    void address(uint16_t addr);
    uint8_t data();
};


#endif //CARTTESTER_DIGITALBUS_H
