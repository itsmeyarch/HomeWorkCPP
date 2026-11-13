#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <iostream>
#include "IHackable.h"

class VendingMachine : public IHackable {
private:
    bool hacked;

public:
    VendingMachine() : hacked(false) {}

    void applyHack(int techLevel) override {
        if (techLevel >= 2) {
            hacked = true;
            std::cout << "Vending machine is hacked! All drinks are released.\n";
        }
        else {
            std::cout << "Electric shock! The hacker is damaged.\n";
        }
    }

    bool isHacked() const override {
        return hacked;
    }
};

#endif