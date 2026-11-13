#include "Time.h"

Time::Time(int h, int m, int s)
{
    hours = h;
    minutes = m;
    seconds = s;
}

std::strong_ordering Time::operator<=>(const Time& other) const
{
    int t1 = hours * 3600 + minutes * 60 + seconds;
    int t2 = other.hours * 3600 + other.minutes * 60 + other.seconds;

    return t1 <=> t2;
}

Time& Time::operator++()
{
    seconds++;

    if (seconds == 60)
    {
        seconds = 0;
        minutes++;
    }

    if (minutes == 60)
    {
        minutes = 0;
        hours++;
    }

    if (hours == 24)
    {
        hours = 0;
    }

    return *this;
}

Time Time::operator++(int)
{
    Time temp = *this;
    ++(*this);
    return temp;
}

Time& Time::operator--()
{
    if (hours == 0 && minutes == 0 && seconds == 0)
    {
        return *this;
    }

    seconds--;

    if (seconds < 0)
    {
        seconds = 59;
        minutes--;
    }

    if (minutes < 0)
    {
        minutes = 59;
        hours--;
    }

    return *this;
}

Time Time::operator--(int)
{
    Time temp = *this;
    --(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Time& t)
{
    out << t.hours << ":" << t.minutes << ":" << t.seconds;
    return out;
}