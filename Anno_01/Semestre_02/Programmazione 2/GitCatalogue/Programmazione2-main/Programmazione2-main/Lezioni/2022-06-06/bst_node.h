#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>
using namespace std;

template <typename T>
class BSTNode
{
protected:
    T key;
    BSTNode<T> *left;
    BSTNode<T> *right;
    BSTNode<T> *parent;

    template <typename U>
    friend class BST;

public:
    BSTNode(T key) : key(key)
    {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    void setLeft(BSTNode *left)
    {
        this->left = left;
    }

    void setRight(BSTNode *right)
    {
        this->right = right;
    }

    BSTNode<T> *getLeft()
    {
        return this->left;
    }

    BSTNode<T> *getRight()
    {
        return this->right;
    }

    void setKey(T key)
    {
        this->key = key;
    }

    T getKey()
    {
        return this->key;
    }

    void setParent(BSTNode<T> *parent)
    {
        this->parent = parent;
    }

    BSTNode<T> *getParent()
    {
        return this->parent;
    }

    friend ostream &operator<<(ostream &os, BSTNode<T> &node)
    {
        os << "BSTNode@ = " << &node << " key = " << node.key << " left = " << node.left << " right = " << node.right << " parent = " << node.parent;

        return os;
    }

    // ~BSTNode()
    // {
    //     delete left;
    //     delete right;
    // }
};

#endif