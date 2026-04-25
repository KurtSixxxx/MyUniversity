#ifndef DL_NODE
#define DL_NODE

#include <iostream>

using namespace std;

template <typename T>
class DLNode
{
    T val;
    DLNode<T> *next;
    DLNode<T> *prev;

    template <typename U>
    friend class DLList;

public:
    DLNode(T val) : val(val), next(nullptr), prev(nullptr){};

    DLNode<T> *getNext() const { return this->next; };

    DLNode<T> *getPrev() const { return this->prev; };

    friend ostream &operator<<(ostream &os, const DLNode<T> &node)
    {
        os << "Node val: " << node.val << " next = " << node.next;
        return os;
    }
};
#endif