#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "lista.h"
using namespace std;

template <typename T>
class Stack : protected List<T>
{
private:
    int size = 0;

public:
    Stack() : List<T>(){};

    Node<T> *top()
    {
        if (List<T>::isEmpty())
        {
            return nullptr;
        }

        return List<T>::getHead();
    }

    void push(T val)
    {
        List<T>::insertHead(val);
        size++;
    }

    Node<T> *pop()
    {
        if (List<T>::isEmpty())
        {
            return nullptr;
        }

        Node<T> *ptr = top();
        List<T>::deleteHead();
        size--;
        return ptr;
    }

    friend ostream &operator<<(ostream &os, const Stack<T> s)
    {
        return os << (List<T>)s;
    }
};

#endif