//
// Created by happycactus on 30/01/23.
//

#ifndef CARTTESTER_IOTESTER_H
#define CARTTESTER_IOTESTER_H

class DigitalBus;

class IoTester {
    DigitalBus &bus;
public:
    explicit IoTester(DigitalBus &bus);

    void setup();
    bool doStep();
};


#endif //CARTTESTER_IOTESTER_H
