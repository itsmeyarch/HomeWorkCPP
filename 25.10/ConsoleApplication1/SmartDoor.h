#ifndef SMARTDOOR_H
#define SMARTDOOR_H

#include <iostream>
#include "IHackable.h"

class SmartDoor : public IHackable {
private:
    bool hacked;
    bool opened;

public:
    SmartDoor() : hacked(false), opened(false) {}

    void applyHack(int techLevel) override {
        if (techLevel >= 5) {
            hacked = true;
            opened = true;
            std::cout << "Smart door is hacked and opened!\n";
        }
        else {
            std::cout << "Hacking failed. Door remains closed.\n";
        }
    }

    bool isHacked() const override {
        return hacked;
    }
};

#endif