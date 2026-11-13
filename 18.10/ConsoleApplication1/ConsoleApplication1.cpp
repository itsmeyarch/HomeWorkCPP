#include <iostream>
#include "Recon.h"
#include "Support.h"

int main()
{
    Recon player1("Recon");
    Support player2("Support");

    std::cout << "Recon takes damage:\n";
    player1.takeDamage(70);

    std::cout << "\nSupport takes damage:\n";
    player2.takeDamage(30);

    std::cout << "\nUnique abilities:\n";

    player1.scanArea();
    player2.dropHeal();
}