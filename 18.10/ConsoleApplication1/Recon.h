#pragma once
#include "Character.h"

class Recon : public Character
{
public:
    Recon(std::string n) : Character(n)
    {
    }

    void scanArea()
    {
        std::cout << name
            << " scans the area: 2 enemies detected!\n";
    }
};