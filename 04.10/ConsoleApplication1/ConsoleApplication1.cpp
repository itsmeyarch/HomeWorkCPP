#include <iostream>
#include "MyString.h"

int main()
{
    MyString str1("Hello ");
    MyString str2("World");

    std::cout << "String 1: " << str1 << "\n";
    std::cout << "String 2: " << str2 << "\n";

    MyString str3 = str1 + str2;

    std::cout << "Concatenation: " << str3 << "\n";

    MyString str4 = std::move(str3);

    std::cout << "After move constructor: " << str4 << "\n";

    MyString str5;

    str5 = std::move(str4);

    std::cout << "After move assignment: " << str5 << "\n";

    std::cout << "Original string: " << str4 << "\n";
}