#pragma once
#include <iostream>

template <typename T>
class DynamicArray
{
private:
    T* data;
    int size;
    int capacity;

public:
    DynamicArray(int cap = 5);
    ~DynamicArray();

    void reserve(int newCapacity);
    void insertAt(int index, T value);
    void removeAt(int index);
    void clear();

    bool empty() const;
    int getSize() const;

    friend std::ostream& operator<<(std::ostream& out, const DynamicArray<T>& arr)
    {
        if (arr.empty())
        {
            out << "{}";
            return out;
        }

        out << "{ ";

        for (int i = 0; i < arr.size; i++)
        {
            out << arr.data[i];

            if (i < arr.size - 1)
            {
                out << ", ";
            }
        }

        out << " }";
        return out;
    }
};

template <typename T>
DynamicArray<T>::DynamicArray(int cap)
{
    capacity = cap;
    size = 0;
    data = new T[capacity];
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] data;
}

template <typename T>
void DynamicArray<T>::reserve(int newCapacity)
{
    if (newCapacity <= capacity)
    {
        return;
    }

    T* newData = new T[newCapacity];

    for (int i = 0; i < size; i++)
    {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template <typename T>
void DynamicArray<T>::insertAt(int index, T value)
{
    if (index < 0 || index > size)
    {
        std::cout << "Invalid index\n";
        return;
    }

    if (size == capacity)
    {
        reserve(capacity * 2);
    }

    for (int i = size; i > index; i--)
    {
        data[i] = data[i - 1];
    }

    data[index] = value;
    size++;
}

template <typename T>
void DynamicArray<T>::removeAt(int index)
{
    if (index < 0 || index >= size)
    {
        std::cout << "Invalid index\n";
        return;
    }

    for (int i = index; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }

    size--;
}

template <typename T>
void DynamicArray<T>::clear()
{
    size = 0;
}

template <typename T>
bool DynamicArray<T>::empty() const
{
    return size == 0;
}

template <typename T>
int DynamicArray<T>::getSize() const
{
    return size;
}