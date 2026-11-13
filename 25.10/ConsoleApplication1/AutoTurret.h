#ifndef AUTOTURRET_H
#define AUTOTURRET_H

#include <iostream>
#include "CyberEnemy.h"
#include "IHackable.h"

class AutoTurret : public CyberEnemy, public IHackable {
private:
    bool hacked;

public:
    AutoTurret() : CyberEnemy(80), hacked(false) {}

    void applyHack(int techLevel) override {
        if (techLevel >= 4) {
            hacked = true;
            std::cout << "Auto turret is hacked! It now targets other enemies.\n";
        }
        else {
            std::cout << "Hacking failed. Turret still targets the player.\n";
        }
    }

    bool isHacked() const override {
        return hacked;
    }

    void attack() override {
        if (hacked) {
            std::cout << "Auto turret attacks other enemies!\n";
        }
        else {
            std::cout << "Auto turret attacks the player!\n";
        }
    }
};

#endif