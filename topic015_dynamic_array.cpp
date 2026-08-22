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
    MemoryException()   {message = "Unknown Memory Error";}
    MemoryException(string s) : message(s)  {}

    const char* what() const noexcept override  {return message.c_str();}
};

template <typename T>
class DynamicArray
{
private:
    T* data = nullptr;
    int size=0, capacity=0;

    void resize()
    {
        // Capacity doubling
        if(capacity == 0)
            ++capacity;
        else if(capacity<size)
            capacity *= 2;
        
        // New Memory Allocation
        T* newData = new T[capacity];
        for(int i=0; i<size-1; ++i)
        {
            newData[i] = data[i];
        }

        // Deleting Old Memory and Replacing with new Data field
        delete[] data;
        this->data = newData;
        newData = nullptr;
    }
public:
    // Constructor & Destructor
    DynamicArray(int initialCapacity = 1) : capacity(initialCapacity)   { resize(); }
    ~DynamicArray()
    {
        delete[] data;
        data = nullptr;
    }
    
    // Member Functions
    void push_back(T val)
    {
        ++size;
        if (size>capacity)
            resize();
        data[size-1] = val;
    }
    T pop_back()
    {
        if (size == 0)
            throw MemoryException("Underflow Error!");
        else
            --size;
        return data[size];
    }
    T operator[](int index) const
    {
        if (index<0 || index >= size)
            throw MemoryException("Index Out of Bound!");
        else
            return data[index];
    }
    int getSize() const {return size;}
    int getCapacity() const {return capacity;}
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