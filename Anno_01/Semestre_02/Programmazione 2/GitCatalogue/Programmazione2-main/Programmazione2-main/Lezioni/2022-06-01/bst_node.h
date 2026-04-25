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
    BSTMode<T> *right;

    template <typename U>
    friend class BST;

public:
    BSTNode(T key) : key(key)
    {
        left = nullptr;
        right = nullptr;
    }

    void setLeft(BSTNode *left)
    {
        this->left = left;
    }

    void setRight(BSTNode *right)
    {
        this->right = right;
    }

    BSTNode<T> *getLeft(){
        return this->left :
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

    friend ostream &operator<<(ostream &os, BSTNode<T> &node)
    {
        os << "BSTNode@ = " << &node << " key = " << node.key << " left = " << node.left << " right = " << node.right;

        return os;
    }

    // ~BSTNode()
    // {
    //     delete left;
    //     delete right;
    // }
};

#endif