#pragma once
#include <compare>
#include <iostream>

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0);

    std::strong_ordering operator<=>(const Time& other) const;

    Time& operator++();
    Time operator++(int);

    Time& operator--();
    Time operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const Time& t);
};