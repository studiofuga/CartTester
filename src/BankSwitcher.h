//
// Created by happycactus on 07/02/23.
//

#ifndef CARTTESTER_BANKSWITCHER_H
#define CARTTESTER_BANKSWITCHER_H


class BankSwitcher {
public:
    virtual ~BankSwitcher() = default;

    virtual void switchBank(int bank) = 0;
    virtual int currentBank() const = 0;
};


#endif //CARTTESTER_BANKSWITCHER_H
