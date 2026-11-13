#pragma once
#include "Character.h"

class Support : public Character
{
public:
    Support(std::string n) : Character(n)
    {
    }

    void dropHeal()
    {
        std::cout << name << " drops a healing pack for allies!\n";
    }
};