#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

class GuessGame {
private:
    int secretNumber;
    int attempts;

public:
    GuessGame() {
        secretNumber = rand() % 500 + 1;
        attempts = 0;
    }

    void play() {
        int number;

        std::cout << "Guess the number from 1 to 500!\n";

        while (true) {
            std::cout << "Enter your guess: ";
            std::cin >> number;

            attempts++;

            if (number < secretNumber) {
                std::cout << "The number is greater!\n";
            }
            else if (number > secretNumber) {
                std::cout << "The number is smaller!\n";
            }
            else {
                std::cout << "Correct! You guessed the number!\n";
                std::cout << "Attempts: " << attempts << "\n";
                saveResult();
                break;
            }
        }
    }

    void saveResult() {
        std::ofstream file("games.txt", std::ios::app);

        if (file.is_open()) {
            file << "Attempts: " << attempts << "\n";
            file << "Secret number: " << secretNumber << "\n";
            file << "--------------------\n";
            file.close();
        }
    }

    static void showStatistics() {
        std::ifstream file("games.txt");

        if (!file.is_open()) {
            std::cout << "No game history found.\n";
            return;
        }

        std::string line;

        std::cout << "\nGame statistics:\n";

        while (std::getline(file, line)) {
            std::cout << line << "\n";
        }

        file.close();
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int choice;

    do {
        std::cout << "\n1. Play game\n";
        std::cout << "2. Show statistics\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose: ";
        std::cin >> choice;

        if (choice == 1) {
            GuessGame game;
            game.play();
        }
        else if (choice == 2) {
            GuessGame::showStatistics();
        }
        else if (choice == 3) {
            std::cout << "Goodbye!\n";
        }
        else {
            std::cout << "Invalid choice!\n";
        }

    } while (choice != 3);
}