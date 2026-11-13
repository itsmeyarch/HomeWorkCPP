#pragma once
#include "Audio.h"

class Audiobook : public Audio
{
private:
    std::string bookTitle;
    std::string author;
    std::string voice;

public:
    Audiobook(std::string b, std::string a, std::string v)
    {
        bookTitle = b;
        author = a;
        voice = v;
    }

    void Play() override
    {
        std::cout << "Listening to audiobook: " << bookTitle
            << " by " << author << ". Read by " << voice << ".\n";
    }
};