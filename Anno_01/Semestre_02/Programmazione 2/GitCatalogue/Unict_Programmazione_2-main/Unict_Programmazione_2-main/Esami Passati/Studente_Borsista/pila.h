#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <stdexcept>
using namespace std;


template <typename T> 
class Node
{
public:
    Node(T d) : data(d), next(nullptr) {} 

    T getData() const {return data;}
    Node <T> * getNext() const { return next; }

    void setData(T d) { data = d;}
    void setNext(Node <T>* n) {next = n;}
    
private:
    T data;
    Node<T> *next;
};

template <typename T>
class Pila
{
public:
    Pila() : head(nullptr) {}
    ~Pila()
    {
        while(!isEmpty())
        {
            pop();
        }
    }

    bool isEmpty(){ return head == nullptr; }

    void push(T dato);
    T pop();

    void print(ostream& os);

private:
    Node <T> *head;
    
};


template <typename T>
void Pila <T> ::push(T dato)
{
    Node <T> * node = new Node <T> (dato);

    if(isEmpty())
    {
        head = node;
        return;
    }

    /*
    node->next = head;  //La prima versione accede direttamente al membro next (che deve essere pubblico o la classe Pila deve essere friend di Node).
    head = node;
    */

    node->setNext(head);  //La seconda versione usa il metodo pubblico setNext(), che è più sicuro (incapsulamento corretto).
    head = node;
}

template <typename T>
T Pila <T> ::pop()
{
    if(isEmpty()) throw runtime_error("Pila vuota");

    Node <T> *cur = head;
    head = head->getNext();

    T dato = cur->getData();

    delete cur;
    return dato;
}


template <typename T>
void Pila <T>::print(ostream& os)
{
    Node <T> *cur = head;

    while(cur)
    {
        os << cur->getData();
        cur = cur->getNext();
    }
}

template <typename T>
ostream& operator << (ostream& os, Pila <T> &p)
{
    p.print(os);
    return os;
}

#endif
