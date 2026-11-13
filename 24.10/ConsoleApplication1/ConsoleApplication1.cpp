#include <iostream>
#include <string>
#include "Song.h"
#include "Podcast.h"
#include "Audiobook.h"

int main()
{
    int choice;
    Audio* audio = nullptr;

    std::cout << "Choose audio type:\n";
    std::cout << "1. Song\n";
    std::cout << "2. Podcast\n";
    std::cout << "3. Audiobook\n";
    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1)
    {
        std::string title, artist;

        std::cout << "Enter song title: ";
        std::getline(std::cin, title);

        std::cout << "Enter artist: ";
        std::getline(std::cin, artist);

        audio = new Song(title, artist);
    }
    else if (choice == 2)
    {
        std::string host, topic;

        std::cout << "Enter host: ";
        std::getline(std::cin, host);

        std::cout << "Enter topic: ";
        std::getline(std::cin, topic);

        audio = new Podcast(host, topic);
    }
    else if (choice == 3)
    {
        std::string bookTitle, author, voice;

        std::cout << "Enter book title: ";
        std::getline(std::cin, bookTitle);

        std::cout << "Enter author: ";
        std::getline(std::cin, author);

        std::cout << "Enter voice: ";
        std::getline(std::cin, voice);

        audio = new Audiobook(bookTitle, author, voice);
    }
    else
    {
        std::cout << "Invalid choice\n";
    }

    if (audio != nullptr)
    {
        audio->Play();
        delete audio;
    }
}