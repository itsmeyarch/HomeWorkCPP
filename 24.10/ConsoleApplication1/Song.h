#pragma once
#include "Audio.h"

class Song : public Audio
{
private:
    std::string title;
    std::string artist;

public:
    Song(std::string t, std::string a)
    {
        title = t;
        artist = a;
    }

    void Play() override
    {
        std::cout << "Playing song: " << title << " by " << artist << "\n";
    }
};