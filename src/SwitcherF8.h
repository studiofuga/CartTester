//
// Created by happycactus on 07/02/23.
//

#ifndef CARTTESTER_SWITCHERF8_H
#define CARTTESTER_SWITCHERF8_H

#include "BankSwitcher.h"

class DigitalBus;

class SwitcherF8 : public BankSwitcher {
    DigitalBus &bus;
    int current_bank = 0;
public:
    explicit SwitcherF8(DigitalBus &bus);

    int currentBank() const override;
    void switchBank(int bank) override;
};


#endif //CARTTESTER_SWITCHERF8_H
