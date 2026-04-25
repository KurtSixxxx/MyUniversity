#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "doublelist.h"
using namespace std;

template <typename T>
class Queue : protected DLList<T>
{
private:
    int size = 0;

public:
    Queue() : DLList<T>(){};

    void enqueue(T val)
    {
        DLList<T>::insertTail(val);
        size++;
    }

    DLNode<T> *dequeue()
    {
        if (isEmpty())
        {
            return nullptr;
        }
        DLNode<T> *ptr = DLList<T>::head;
        DLList<T>::removeHead();
        size--;
        return ptr;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    friend ostream &operator<<(ostream &os, const Queue<T> &queue)
    {
        os << "Queue head = " << queue.head << endl;
        DLNode<T> *ptr = queue.head;

        while (ptr != nullptr)
        {
            os << '\t' << *ptr << endl;
            ptr = ptr->getNext();
        }

        return os;
    }
};
#endif