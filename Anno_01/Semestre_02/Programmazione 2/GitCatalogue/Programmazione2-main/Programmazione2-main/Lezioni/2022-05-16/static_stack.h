#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <iostream>
using namespace std;

template <typename T>
class StaticStack
{
private:
    T *array;
    int top = -1;
    int size = 0;
    int maxSize = -1;

public:
    StaticStack(int _maxSize) : maxSize(_maxSize) { array = new T[maxSize]; };

    T getTop()
    {
        if (isEmpty())
        {
            return -1;
        }

        return array[top];
    }

    void push(T val)
    {
        if (top == maxSize - 1)
        {
            return;
        }

        array[++top] = val;
    }

    T pop()
    {
        if (isEmpty())
        {
            return -1;
        }

        return array[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    friend ostream &operator<<(ostream &os, const StaticStack<T> stack)
    {
        os << "Stacic Stack: maxSize= " << stack.maxSize << endl;

        os << "\t" << endl;

        for (int i = stack.top; i >= 0; i--)
        {
            os << stack.array[i] << " ";
        }

        return os;
    }
};
#endif