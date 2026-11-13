#ifndef NETRUNNER_H
#define NETRUNNER_H

#include "IHackable.h"

class Netrunner {
private:
    int skillLevel;

public:
    Netrunner(int skillLevel) : skillLevel(skillLevel) {}

    void breachProtocol(IHackable& target) {
        target.applyHack(this->skillLevel);
    }
};

#endif