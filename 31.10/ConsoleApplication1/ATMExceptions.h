#ifndef ATMEXCEPTIONS_H
#define ATMEXCEPTIONS_H

#include <stdexcept>

class InvalidAmountException : public std::runtime_error {
public:
    InvalidAmountException(const std::string& message)
        : std::runtime_error(message) {}

    const char* what() const noexcept override {
        return std::runtime_error::what();
    }
};

class InsufficientFundsException : public std::runtime_error {
public:
    InsufficientFundsException(const std::string& message)
        : std::runtime_error(message) {}

    const char* what() const noexcept override {
        return std::runtime_error::what();
    }
};

class LimitExceededException : public std::runtime_error {
public:
    LimitExceededException(const std::string& message)
        : std::runtime_error(message) {}

    const char* what() const noexcept override {
        return std::runtime_error::what();
    }
};

#endif