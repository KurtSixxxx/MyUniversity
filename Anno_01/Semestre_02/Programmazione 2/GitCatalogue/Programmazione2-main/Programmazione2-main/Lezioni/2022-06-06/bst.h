#ifndef BST_H
#define BST_H

#include <iostream>
#include "bst_node.h"
using namespace std;

template <typename T>
class BST
{
    BSTNode<T> *root;

public:
    BST()
    {
        root = nullptr;
    }

    bool isEmpty()
    {
        return root == nullptr;
    }

    BSTNode<T> *getRoot()
    {
        return this->root;
    }

    void insert(T key)
    {
        if (isEmpty())
        {
            root = new BSTNode<T>(key);
            return;
        }

        insert(root, key);
    }

    void insert(BSTNode<T> *ptr, T key)
    {
        if (ptr->left == nullptr && key <= ptr->key)
        {
            ptr->left = new BSTNode<T>(key);
            ptr->left->setParent(ptr);
            return;
        }

        if (ptr->right == nullptr && key > ptr->key)
        {
            ptr->right = new BSTNode<T>(key);
            ptr->right->setParent(ptr);
            return;
        }

        if (ptr == nullptr)
        {
            ptr = new BSTNode<T>(key);
            return;
        }

        if (key <= ptr->key)
        {
            insert(ptr->left, key);
        }

        else
        {
            insert(ptr->right, key);
        }
    }

    void visit(BSTNode<T> *ptr)
    {
        cout << ptr << endl;
    }

    void inOrder()
    {
        inOrder(root);
    }

    void inOrder(BSTNode<T> *ptr)
    {
        if (ptr == nullptr)
        {
            return;
        }
        inOrder(ptr->left);
        visit(ptr);
        inOrder(ptr->right);
    }

    BSTNode<T> *min()
    {
        return min(getRoot());
    }

    BSTNode<T> *min(BSTNode<T> *from)
    {

        if (isEmpty())
        {
            return NULL;
        }

        BSTNode<T> *ptr = from;

        while (ptr->left)
        {
            ptr = ptr->left;
        }

        return ptr;
    }

    BSTNode<T> *max()
    {
        return max(getRoot());
    }

    BSTNode<T> *max(BSTNode<T> *from)
    {

        if (isEmpty())
        {
            return NULL;
        }

        BSTNode<T> *ptr = from;
        while (ptr->right)
        {
            ptr = ptr->right;
        }

        return ptr;
    }

    BSTNode<T> *successor(BSTNode<T> *x)
    {
        if (this->isEmpty())
        {
            return nullptr;
        }

        if (x->right)
        {
            return this->min(x->right);
        }

        BSTNode<T> *y = x->parent;

        while (x != nullptr && x == y->right)
        {
            x = y;
            y = y->parent;
        }

        return y;
    }

    BSTNode<T> *search(T key)
    {
        return search(root, key);
    }

    BSTNode<T> *search(BSTNode<T> *ptr, T key)
    {
        if (ptr == nullptr)
        {
            return nullptr;
        }

        if (ptr->key == key)
        {
            return nullptr;
        }

        if (key <= ptr->key)
        {
            return search(ptr->left, key);
        }
        else
        {
            return search(ptr->right, key);
        }
    }
};

#endif