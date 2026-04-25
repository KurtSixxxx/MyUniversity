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
};

#endif