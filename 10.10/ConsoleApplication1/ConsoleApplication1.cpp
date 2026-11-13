#include <iostream>
#include "DynamicArray.h"

int main()
{
    DynamicArray<int> arr;

    arr.insertAt(0, 10);
    arr.insertAt(1, 20);
    arr.insertAt(2, 30);
    arr.insertAt(3, 40);

    std::cout << "Array: " << arr << "\n";

    arr.insertAt(2, 25);

    std::cout << "After insertion: " << arr << "\n";

    arr.removeAt(1);

    std::cout << "After removal: " << arr << "\n";

    arr.insertAt(10, 50);

    arr.clear();

    std::cout << "After clear: " << arr << "\n";

    std::cout << "Is empty: " << arr.empty() << "\n";
    std::cout << "Size: " << arr.getSize() << "\n";
}