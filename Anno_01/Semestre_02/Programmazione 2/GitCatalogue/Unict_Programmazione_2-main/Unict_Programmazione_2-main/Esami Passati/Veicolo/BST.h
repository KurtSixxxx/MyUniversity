#ifndef BST_H
#define BST_H

#include <iostream>
#include "Veicolo.h"
using namespace std;

template <typename T>
class BST_Node
{
public:
    BST_Node(T d) : dato(d), left(nullptr), right(nullptr), parent(nullptr) {}

    BST_Node <T>* getLeft() {return left;}
    BST_Node <T>* getRight() {return right;}
    BST_Node <T>* getParent() {return parent;}

    T getDato() {return dato;}

    void setLeft(BST_Node <T>* l) {left = l;}
    void setRight(BST_Node <T>* r) {right = r;}
    void setParent(BST_Node <T>* p) {parent = p;}

private:
    BST_Node <T> *left;
    BST_Node <T> *right;
    BST_Node <T> *parent;
    T dato;
};

template <typename T>
class BST
{
public:
    BST() : root(nullptr) {}

    ~BST()
    {
        clear(root);
        root = nullptr;
    }

    void Insert(T val)
    {
        BST_Node <T> * x = root;
        BST_Node <T> * y = nullptr;

        while(x!=nullptr)
        {
            y = x;

            if(val < x->getDato())
                x = x->getLeft();
            else
                x = x->getRight();
        }

        BST_Node <T> *node = new BST_Node <T> (val);
        node->setParent(y);  //newnode->parent = y;

        if(y == nullptr)
            root = node;
        else if(val < y->getDato())
            y->setLeft(node);
        else
            y->setRight(node);
    }


    BST_Node <T>* search(T val)
    {
        if(root == nullptr)
            return nullptr;
        
        BST_Node <T> * curr = root;

        while(curr != nullptr)
        {
            if(val == curr->getDato())
                return curr;
            else if(val < curr->getDato())
                curr = curr->getLeft();
            else   
                curr = curr->getRight();
        }

        return nullptr;
    }

   BST_Node <T>* trapianta(BST_Node <T>* u, BST_Node <T>* v)
   {
        if(u == nullptr)
            return nullptr;

        if(u->getParent() == nullptr)
           root = v;

        else if(u == u->getParent()->getLeft())
            u->getParent()->setLeft(v);

        else
            u->getParent()->setRight(v);
        
        if(v != nullptr)
            v->setParent(u->getParent());

        return v;
   }

   BST_Node <T> * min(BST_Node <T>* n)
   {
        if(n == nullptr)
            return nullptr;

        BST_Node <T>* curr = n;
        while(curr->getLeft() != nullptr)
        {
            curr = curr->getLeft();
        }

        return curr;
   }

   BST_Node <T> * next(BST_Node <T>* n)
   {
        if(n->getRight())
            return min(n->getRight());
        
        BST_Node <T> * curr = n->getParent();

        while(curr!= nullptr && n!= curr->getLeft())
        {
            n = curr;
            curr = n->getParent();
        }

        return curr;
   }

   void remove(BST_Node <T> *n)
   {
        if((n->getLeft() == nullptr) && (n->getRight() == nullptr))
        {
            if(n->getParent() == nullptr)
                root = nullptr;
            else if(n->getParent()->getLeft() == n)
                n->getParent()->setLeft(nullptr);
            else
                n->getParent()->setRight( nullptr);
        }
        else if(n->getRight() == nullptr)
            trapianta(n,n->getLeft());

        else if(n->getLeft() == nullptr)
            trapianta(n,n->getRight());
        
        else
        {
            BST_Node <T>* next = min(n->getRight());
            if(n->getRight() != next)
            {
                trapianta(next,next->getRight());
                next->setRight(n->getRight());
                n->getRight()->setParent(next);
            }
            trapianta(n,next);
            next->setLeft(n->getLeft());
            next->getLeft()->setParent(next);
        }
        
        delete n;
   }

   void print_Pre_order(ostream& os)
   {
        if(root == nullptr)
        return;

        return print_Pre_order(os,root);
   }
    
   void print_Pre_order(ostream& os, BST_Node <T>* node)
   {
       if(node==nullptr)
        return;

        node->getDato()->print(os);
        print_Pre_order(os,node->getLeft());
        print_Pre_order(os,node->getRight());
   }

   void clear(BST_Node <T> * node)
   {
        if(node != nullptr)
        {
            clear(node->getLeft());
            clear(node->getRight());
            delete node;
        }
   }

private:
    BST_Node <T> *root;
};

#endif