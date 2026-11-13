#include <iostream>
#include "Time.h"

int main()
{
    Time t1(12, 30, 45);
    Time t2(14, 20, 10);

    std::cout << "Time 1: " << t1 << "\n";
    std::cout << "Time 2: " << t2 << "\n";

    if (t1 < t2)
        std::cout << "Time 1 is smaller\n";

    if (t1 > t2)
        std::cout << "Time 1 is bigger\n";

    ++t1;
    std::cout << "After prefix ++: " << t1 << "\n";

    t1++;
    std::cout << "After postfix ++: " << t1 << "\n";

    --t1;
    std::cout << "After prefix --: " << t1 << "\n";

    t1--;
    std::cout << "After postfix --: " << t1 << "\n";
}