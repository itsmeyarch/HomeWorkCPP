#ifndef CYBORGGUARD_H
#define CYBORGGUARD_H

#include <iostream>
#include "CyberEnemy.h"
#include "IHackable.h"

class CyborgGuard : public CyberEnemy, public IHackable {
private:
    bool hacked;
    bool frozen;

public:
    CyborgGuard() : CyberEnemy(100), hacked(false), frozen(false) {}

    void applyHack(int techLevel) override {
        if (techLevel >= 7) {
            hacked = true;
            frozen = true;
            std::cout << "Cyborg guard is frozen!\n";
        }
        else {
            health -= 20;
            if (health < 0) {
                health = 0;
            }
            std::cout << "Virus damaged cyborg guard. Health: " << health << "\n";
        }
    }

    bool isHacked() const override {
        return hacked;
    }

    void attack() override {
        if (frozen) {
            std::cout << "Cyborg guard is frozen and cannot attack.\n";
        }
        else {
            std::cout << "Cyborg guard attacks the player!\n";
        }
    }
};

#endif