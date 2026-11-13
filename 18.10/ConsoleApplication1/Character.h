#pragma once
#include <iostream>
#include <string>

class Character
{
protected:
    std::string name;
    int health;
    int shield;

public:
    Character(std::string n)
    {
        name = n;
        health = 100;
        shield = 50;
    }

    void takeDamage(int amount)
    {
        if (amount <= shield)
        {
            shield -= amount;
        }
        else
        {
            amount -= shield;
            shield = 0;
            health -= amount;
        }

        if (health < 0)
        {
            health = 0;
        }

        std::cout << name << " Health: " << health
            << ", Shield: " << shield << "\n";
    }
};