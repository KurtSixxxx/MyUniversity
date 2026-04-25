#ifndef DLLIST
#define DLLIST

#include <iostream>
#include "doublenode.h"
using namespace std;

template <typename T>
class DLList
{
protected:
    DLNode<T> *head;
    DLNode<T> *tail;

public:
    DLList()
    {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty()
    {
        return (head == nullptr) && (tail == nullptr);
    }

    void insertHead(T val)
    {
        if (this->isEmpty())
        {
            head = new DLNode(val);
            tail = head;
            return;
        }

        DLNode<T> *toInsert = new DLNode(val);
        toInsert->next = head;
        head->prev = toInsert;
        head = toInsert;
    }

    void insertTail(T val)
    {
        if (this->isEmpty())
        {
            this->insertHead(val);
            return;
        }

        DLNode<T> *toInsert = new DLNode<T>(val);
        toInsert->prev = tail;
        tail->next = toInsert;
        tail = toInsert;
    }

    void removeHead()
    {
        if (this->isEmpty())
        {
            cout << "Empty list!" << endl;
            return;
        }

        if (head == tail)
        {
            DLNode<T> *ptr = head;
            head = nullptr;
            tail = nullptr;
            delete ptr;
        }

        DLNode<T> *ptr = head;
        ptr->next->prev = nullptr;
        head = ptr->next;

        delete ptr;
    }

    void removeTail()
    {
        if (this->isEmpty())
        {
            cout << "Empty list!" << endl;
            return;
        }

        if (head == tail)
        {
            DLNode<T> *ptr = head;
            head = nullptr;
            tail = nullptr;
            delete ptr;
        }

        DLNode<T> *ptr = tail;
        ptr->prev->next = nullptr;
        tail = ptr->prev;

        delete ptr;
    }

    friend ostream &operator<<(ostream &os, const DLList<T> list)
    {
        os << "List head = " << list.head << endl;
        DLNode<T> *ptr = list.head;

        while (ptr != nullptr)
        {
            os << '\t' << *ptr << endl;
            ptr = ptr->getNext();
        }

        return os;
    }
};

#endif