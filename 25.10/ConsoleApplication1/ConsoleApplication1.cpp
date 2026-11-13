#include <iostream>
#include "Netrunner.h"
#include "SmartDoor.h"
#include "VendingMachine.h"
#include "CyborgGuard.h"
#include "AutoTurret.h"

int main() {
    Netrunner hacker(5);

    SmartDoor door;
    VendingMachine machine;
    CyborgGuard guard;

    hacker.breachProtocol(door);
    hacker.breachProtocol(machine);
    hacker.breachProtocol(guard);

    std::cout << "\nCyborg attack:\n";
    guard.attack();

    std::cout << "\nHacking results:\n";
    std::cout << "Door hacked: " << door.isHacked() << "\n";
    std::cout << "Machine hacked: " << machine.isHacked() << "\n";
    std::cout << "Cyborg hacked: " << guard.isHacked() << "\n";
}