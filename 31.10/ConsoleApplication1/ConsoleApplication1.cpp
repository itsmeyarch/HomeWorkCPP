#include <iostream>
#include "ATM.h"

int main() {
    ATM atm(10000, 3000);

    int amount;

    std::cout << "Enter amount to withdraw: ";
    std::cin >> amount;

    try {
        atm.withdraw(amount);
    }
    catch (const InvalidAmountException& e) {
        std::cout << "Invalid amount: " << e.what() << "\n";
    }
    catch (const InsufficientFundsException& e) {
        std::cout << "Insufficient funds: " << e.what() << "\n";
    }
    catch (const LimitExceededException& e) {
        std::cout << "Limit exceeded: " << e.what() << "\n";
    }
}