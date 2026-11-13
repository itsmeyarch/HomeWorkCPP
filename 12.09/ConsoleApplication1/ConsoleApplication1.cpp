#include <iostream>
#include "Fraction.h"

int main() {
    Fraction first;
    Fraction second;

    std::cout << "First fraction:\n";
    first.input();

    std::cout << "\nSecond fraction:\n";
    second.input();

    Fraction result;

    std::cout << "\nAddition: ";
    result = first.add(second);
    result.print();

    std::cout << "Subtraction: ";
    result = first.subtract(second);
    result.print();

    std::cout << "Multiplication: ";
    result = first.multiply(second);
    result.print();

    std::cout << "Division: ";
    result = first.divide(second);
    result.print();
}