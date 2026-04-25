#ifndef BST_H
#define BST_H

#include <iostream>
#include "Animale.h"


template <class T> 
class BST_Node
{
public:
    BST_Node (T d) : dato(d), left(nullptr), right(nullptr), parent(nullptr) {}

    T getDato() const {return dato;}

    BST_Node <T> * getLeft() const { return left; }
    BST_Node <T> * getRight() const {return right;}
    BST_Node <T> * getParent() const {return parent;}

    void setLeft(BST_Node <T>* node) { left = node;}
    void setRight(BST_Node <T>* node) { right = node;}
    void setParent(BST_Node <T>* node) {parent = node;}

private:
    T dato;
    BST_Node <T> *left;
    BST_Node <T> *right;
    BST_Node <T> *parent;
};


template <class T>
class BST
{   
public:
    BST() : root(nullptr), dim(0) {}

    BST_Node<T>* getRoot() const { return root; }

    int getDim() const {return dim;}
    
    ~ BST() 
    {
        clear(root); 
        root = nullptr;
    }

    void insert(T val)
    {
        BST_Node <T> *x = root;
        BST_Node <T> *y = nullptr;

        while(x!= nullptr)
        {
            y = x;
            if(val->getNome() < x->getDato()->getNome())
                x = x->getLeft();
            else
                x = x->getRight();
            
        }

        BST_Node <T> * node = new BST_Node <T> (val);
        node->setParent(y);

        if(y == nullptr)
            root = node;
        else if(val->getNome() < y->getDato()->getNome())
            y->setLeft(node);
        else    
            y->setRight(node);

        dim++;
        
    }
    

    BST_Node <T> *search(const std:: string& nome)
    {
        return search(nome,root);
    }

    BST_Node <T> *search(const std::string& nome, BST_Node <T>* node)
    {
        if(node == nullptr) return nullptr;

        BST_Node <T> * curr = node;

        while(curr != nullptr)
        {
            if(curr->getDato()->getNome() == nome )
                return curr;
            else if(nome < curr->getDato()->getNome())
                curr = curr->getLeft();                         
            else
               curr = curr->getRight();
        }

        return nullptr;
        
    }


    void clear(BST_Node <T>* node)
    {
        if(node != nullptr)
        {
            clear(node->getLeft());
            clear(node->getRight());
            delete node->getDato();
            delete node;
            dim--;
        }
    }

    void printInorder(std::ostream& os)
    {
        return printInorder(os,root);
    }

    void printInorder(std::ostream& os, BST_Node <T>* node)
    {
        if (node == nullptr) return;

        printInorder(os,node->getLeft());
        node->getDato()->stampa(os);
        os << std::endl;
        printInorder(os,node->getRight());

    }


private:
    BST_Node <T> *root;
    int dim;
};



#endif