#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
    T val;
    Node<T> *next;

    template <typename U>
    friend class List;

public:
    Node(T val) : val(val)
    {
        next = nullptr;
    }

    Node<T> *getNext()
    {
        return this->next;
    }

    friend ostream &operator<<(ostream &os, const Node<T> &node)
    {
        os << "Node val: " << node.val << " next = " << node.next;
        return os;
    }
};

#endif