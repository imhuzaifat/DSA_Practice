/*
 * Topic 15: Dynamic Arrays & Resizing Mechanics
 * Problem Set 15: Custom Dynamic Vector Implementation
 * 
 * Requirements:
 * 1. Implement template DynamicArray<T> with capacity-doubling resizing strategy.
 * 2. Track size, capacity, and underlying T* data heap pointer.
 * 3. Provide push_back (amortized O(1)), pop_back, and operator[].
 * 4. Demonstrate automatic capacity growth and element access in main().
 */

#include <iostream>
#include <exception>
using namespace std;

class MemoryException : public exception
{
private:
    string message;
public:
    MemoryException() : message("Unknown Memory Error") {}
    MemoryException(string s) : message(s) {}

    const char* what() const noexcept override { return message.c_str(); }
};

template <typename T>
class DynamicArray
{
private:
    T* data;
    int size;
    int capacity;

    void resize()
    {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        
        T* newData = new T[capacity];

        for (int i = 0; i < size; ++i)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }

public:
    DynamicArray(int initialCapacity = 2) : size(0), capacity(initialCapacity)
    {
        if (capacity <= 0) capacity = 2;
        data = new T[capacity];
    }

    ~DynamicArray()
    {
        delete[] data;
        data = nullptr;
    }
    
    void push_back(T val)
    {
        if (size == capacity)
        {
            resize();
        }
        data[size] = val;
        ++size;
    }

    T pop_back()
    {
        if (size == 0)
            throw MemoryException("Underflow Error!");
        
        --size;
        return data[size];
    }

    T operator[](int index) const
    {
        if (index < 0 || index >= size)
            throw MemoryException("Index Out of Bounds!");
        
        return data[index];
    }

    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
};

int main()
{
    try
    {
        //Instantiating Dynamic Array
        DynamicArray<int> arr;

        // Pushing 5 different elements
        arr.push_back(234);
        arr.push_back(586);
        arr.push_back(967);
        arr.push_back(349);
        arr.push_back(672);

        // Printing Size and Capacity
        cout << "Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity() << endl;

        // Poping the updated array
        for(int i=arr.getSize()-1; i>=0; --i)
            cout << "Element " << i << ": " << arr.pop_back() << endl;

        return 0;
    }
    catch (const MemoryException& e)
    {
        cerr << "Memory Error: " << e.what() << endl;
    }
}