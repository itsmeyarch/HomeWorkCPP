#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        int a = numerator;
        int b = denominator;

        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        if (a != 0) {
            numerator /= a;
            denominator /= a;
        }

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator == 0 ? 1 : denominator;
        simplify();
    }

    void input() {
        std::cout << "Enter numerator: ";
        std::cin >> numerator;

        do {
            std::cout << "Enter denominator: ";
            std::cin >> denominator;

            if (denominator == 0) {
                std::cout << "Denominator cannot be zero!\n";
            }
        } while (denominator == 0);

        simplify();
    }

    void print() const {
        std::cout << numerator << "/" << denominator << "\n";
    }

    Fraction add(const Fraction& other) const {
        return Fraction(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator
        );
    }

    Fraction subtract(const Fraction& other) const {
        return Fraction(
            numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator
        );
    }

    Fraction multiply(const Fraction& other) const {
        return Fraction(
            numerator * other.numerator,
            denominator * other.denominator
        );
    }

    Fraction divide(const Fraction& other) const {
        if (other.numerator == 0) {
            std::cout << "Division by zero is not allowed!\n";
            return Fraction();
        }

        return Fraction(
            numerator * other.denominator,
            denominator * other.numerator
        );
    }
};

#endif