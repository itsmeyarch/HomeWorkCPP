#include <iostream>
#include <typeinfo>

template <typename T>
void typeName(T value) {
    std::cout << "Type name: " << typeid(value).name() << '\n';
}
int main()
{
    int a = 41;
    double b = 14.15;
    char c = 'A';
    std::string d = "Hello world";

    typeName(a);
    typeName(b);
    typeName(c);
    typeName(d);
}
