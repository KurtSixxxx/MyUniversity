#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>

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

    void setLeft(BSTNode<T> *left)
    {
        this->left = left;
    }

    void setRight(BSTNode<T> *right)
    {
        this->right = right;
    }

    void setParent(BSTNode<T> *parent)
    {
        this->parent = parent;
    }

    BSTNode<T> *getLeft()
    {
        return this->left;
    }

    BSTNode<T> *getRight()
    {
        return this->right;
    }

    BSTNode<T> *getParent()
    {
        return this->parent;
    }

    void setKey(T key)
    {
        this->key = key;
    }

    T getKey()
    {
        return this->key;
    }

    friend std::ostream &operator<<(std::ostream &out, BSTNode<T> &node)
    {
        out << node.key;
        return out;
    }
};

#endif