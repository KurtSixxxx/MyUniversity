#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "node.h"
using namespace std;

template <typename T>
class List
{
private:
    Node<T> *head;

public:
    List()
    {
        head = nullptr;
    };

    Node<T> const *getHead()
    {
        return this->head;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void insert(T val)
    {
        if (this->isEmpty())
        {
            head = new Node<T>(val);
        }
    }

    void insertHead(T val)
    {
        if (!this->isEmpty())
        {
            Node<T> *temp = new Node<T>(val);
            temp->next = head;
            this->head = temp;
        }
        else
        {
            insert(val);
            return;
        }
    }

    void insertTail(T val)
    {
        if (this->isEmpty())
        {
            this->insertHead(val);
        }

        Node<T> *ptr = head;
        while (ptr->getNext() != nullptr)
        {
            ptr = ptr->getNext();
        }

        Node<T> *temp = new Node<T>(val);
        ptr->next = temp;
    }

    friend ostream &operator<<(ostream &os, const List<T> list)
    {
        os << "List head = " << list.head << endl;
        Node<T> *ptr = list.head;

        while (ptr != nullptr)
        {
            os << '\t' << *ptr << endl;
            ptr = ptr->getNext();
        }

        return os;
    }
};

#endif