#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
using namespace std;

template <typename T>
class MyArray
{
private:
    int length;
    T *array;

public:
    MyArray(int l) : length(l)
    {
        array = new T[length];
    }

    void printArray()
    {
        cout << "array = [ ";

        for (int c = 0; c < length; c++)
        {
            cout << array[c] << ", ";
        }

        cout << "]";
    }

    T at(int pos)
    {
        return array[pos % length];
    }

    void at(int pos, T value)
    {
        array[pos % length] = value;
    }

    int size()
    {
        return length;
    }

    T *getPointer()
    {
        return array;
    }

    void copy(MyArray<T> *dat)
    {
        for (int c = 0; c < length; c++)
        {
            dat->at(c, array[c]);
        }
    }
};

int main()
{
    int dst[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    MyArray<int> arr(10);

    arr.printArray();
}