//
// Created by happycactus on 26/01/23.
//

#include "DigitalBus.h"
#include "Arduino.h"

const uint8_t DigitalBus::AddressPin[13] = {
    45, 43, 41, 39, 37, 35, 33, 31, 34, 36, 38, 40, 42
};

const uint8_t DigitalBus::DataPin[8] = {
    47, 49, 51, 52, 50, 48, 46, 44
};

DigitalBus::DigitalBus() = default;

void DigitalBus::setup()
{
    memset(outputPortDirty, 0, sizeof(outputPortDirty));
    memset(cachedOutputValues, 0, sizeof(cachedOutputValues));

    for (unsigned char i : AddressPin) {
        pinMode(i, OUTPUT);
    }
    for (unsigned char i : DataPin) {
        pinMode(i, INPUT_PULLUP);
    }
}

void DigitalBus::address(uint16_t addr)
{
    for (uint8_t i = 0; i < 13; ++i) {
        setAddressPin(i, (addr >> i) & 1);
    }
    commitAddress();
}

uint8_t DigitalBus::data()
{
    uint8_t  v = 0;
    for (int i = 0; i < 8; ++i) {
        v = v | (readDataPin(i) << i);
    }
    return v;
}

void DigitalBus::setAddressPin(uint8_t pin, uint8_t value)
{
    uint8_t bit = digitalPinToBitMask(AddressPin[pin]);
    uint8_t port = digitalPinToPort(AddressPin[pin]);

    if (port == NOT_A_PIN) {
        char b[200];
        sprintf(b, "Fatal: Not an ADDRESS pin: %d -> A%d -> %d %d", pin, AddressPin[pin], port, bit);
        Serial.println(b);
        while(true) {}
    };

    cachedOutputValues[port] = (cachedOutputValues[port] & ~bit) | (value ? bit : 0);
    outputPortDirty[port] = true;
}

// Read a single pin from the data bus
uint8_t DigitalBus::readDataPin(uint8_t pin)
{
    uint8_t bit = digitalPinToBitMask(DataPin[pin]);
    uint8_t port = digitalPinToPort(DataPin[pin]);

    if (port == NOT_A_PIN) {
        char b[200];
        sprintf(b, "Fatal: Not DATA a pin: %d -> D%d -> %d %d", pin, DataPin[pin], port, bit);
        Serial.println(b);
        while(true) {}
    }

    volatile uint8_t *in = portInputRegister(port);
    if (*in & bit) {
        return 1;
    }

    return 0;
}

// Updates all pins at once by picking values from the cached array
void DigitalBus::commitAddress()
{
    for (int i = 0; i < 16; ++i) {
        if (outputPortDirty[i]) {
            volatile uint8_t *out = portOutputRegister(i);
            *out = cachedOutputValues[i];
            outputPortDirty[i] = false;
        }
    }
}
