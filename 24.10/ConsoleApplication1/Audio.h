#pragma once
#include <iostream>
#include <string>

class Audio
{
public:
    virtual void Play() = 0;
    virtual ~Audio() {}
};