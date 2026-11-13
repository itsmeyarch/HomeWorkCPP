#include <iostream>
#include <typeinfo>

template <typename T>
void printType(T value) {
    std::cout << "Type: " << typeid(value).name() << "\n";
}

void printSymbol(int number) {
    char* symbol = reinterpret_cast<char*>(&number);
    std::cout << "Symbol: " << *symbol << "\n";
}

int main() {
    int a = 10;
    double b = 5.5;
    char c = 'A';

    printType(a);
    printType(b);
    printType(c);

    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    printSymbol(number);
}