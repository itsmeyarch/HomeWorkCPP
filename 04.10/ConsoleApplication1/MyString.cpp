#include "MyString.h"
#include <cstring>

MyString::MyString(const char* str)
{
    length = strlen(str);
    data = new char[length + 1];
    strcpy(data, str);
}

MyString::MyString(const MyString& other)
{
    length = other.length;
    data = new char[length + 1];
    strcpy(data, other.data);
}

MyString::MyString(MyString&& other) noexcept
{
    std::cout << "[Move Constructor]\n";

    data = other.data;
    length = other.length;

    other.data = nullptr;
    other.length = 0;
}

MyString::~MyString()
{
    delete[] data;
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
    {
        delete[] data;

        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
    std::cout << "[Move Assignment]\n";

    if (this != &other)
    {
        delete[] data;

        data = other.data;
        length = other.length;

        other.data = nullptr;
        other.length = 0;
    }

    return *this;
}

MyString operator+(const MyString& str1, const MyString& str2)
{
    int newLength = str1.length + str2.length;

    char* newData = new char[newLength + 1];

    strcpy(newData, str1.data);
    strcat(newData, str2.data);

    MyString result(newData);

    delete[] newData;

    return result;
}

std::ostream& operator<<(std::ostream& out, const MyString& str)
{
    if (str.data != nullptr)
    {
        out << str.data;
    }

    return out;
}