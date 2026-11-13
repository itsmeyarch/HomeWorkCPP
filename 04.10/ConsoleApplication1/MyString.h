#pragma once
#include <iostream>

class MyString
{
private:
    char* data;
    int length;

public:
    MyString(const char* str = "");
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;
    ~MyString();

    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;

    friend MyString operator+(const MyString& str1, const MyString& str2);
    friend std::ostream& operator<<(std::ostream& out, const MyString& str);
};