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

    void insertInOrder(T val)
    {
        if (this->isEmpty())
        {
            this->insertHead(val);
            return;
        }

        if (head->val >= val)
        {
            this->insertHead(val);
            return;
        }

        Node<T> *ptr = head;

        while (ptr->getNext() != nullptr && (val >= ptr->val))
        {
            if (val <= ptr->next->val)
            {
                break;
            }

            ptr = ptr->getNext();
        }

        if (ptr->next == nullptr)
        {
            this->insertTail(val);
            return;
        }

        Node<T> *toInsert = new Node<T>(val);
        toInsert->next = ptr->next;
        ptr->next = toInsert;
    }

    void deleteHead()
    {
        if (this->isEmpty())
        {
            cout << "Empty list!" << endl;
            return;
        }

        Node<T> *temp = head;
        head = head->next;

        delete temp;
    }

    void deleteTail()
    {
        if (this->isEmpty())
        {
            cout << "Empty list!" << endl;
            return;
        }

        Node<T> *cur = head;
        Node<T> *prev = nullptr;

        while (cur->next)
        {
            prev = cur;
            cur = cur->next;
        }

        prev->next = nullptr;
        delete cur;
    }

    void remove(T val)
    {
        if (this->isEmpty())
        {
            cout << "Empty list!" << endl;
            return;
        }

        if (val == head->val)
        {
            deleteHead();
            return;
        }

        Node<T> *cur = head;
        Node<T> *prev = nullptr;

        while (cur->next && cur->val != val)
        {
            prev = cur;
            cur = cur->next;
        }

        if (!(cur->next) && cur->val != val)
        {
            cout << "Element with value " << val << " not found!" << endl;
            return;
        }

        prev->next = cur->next;
        delete cur;
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