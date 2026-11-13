#pragma once
#include "Audio.h"

class Podcast : public Audio
{
private:
    std::string host;
    std::string topic;

public:
    Podcast(std::string h, std::string t)
    {
        host = h;
        topic = t;
    }

    void Play() override
    {
        std::cout << "Podcast on " << topic << " hosted by " << host << "\n";
    }
};