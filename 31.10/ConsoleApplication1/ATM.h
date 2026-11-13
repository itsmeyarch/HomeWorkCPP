#ifndef ATM_H
#define ATM_H

#include <iostream>
#include "ATMExceptions.h"

class ATM {
private:
    int balance;
    int dailyLimit;
    int withdrawnToday;

public:
    ATM(int balance, int dailyLimit)
        : balance(balance), dailyLimit(dailyLimit), withdrawnToday(0) {
    }

    void withdraw(int amount) {
        if (amount % 100 != 0) {
            throw InvalidAmountException("Amount must be a multiple of 100.");
        }

        if (amount > balance) {
            throw InsufficientFundsException("Not enough money on balance.");
        }

        if (withdrawnToday + amount > dailyLimit) {
            throw LimitExceededException("Daily withdrawal limit exceeded.");
        }

        balance -= amount;
        withdrawnToday += amount;

        std::cout << "Withdrawal successful: " << amount << "\n";
        std::cout << "Remaining balance: " << balance << "\n";
    }
};

#endif