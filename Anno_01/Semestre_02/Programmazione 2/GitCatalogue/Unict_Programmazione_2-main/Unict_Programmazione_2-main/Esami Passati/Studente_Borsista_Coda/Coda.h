#ifndef CODA_H
#define CODA_H
#include <iostream>
#include "Studente.h"

using namespace std;


template <typename T> 
class Node
{
public:
    Node(T d) : dato(d), next(nullptr) {}

    Node <T>* getNext() const {return next;}
    T getDato() const {return dato;}

    void setNext(Node <T> * n) {next = n;} 


private:
    T dato;
    Node <T> * next;
};

template <typename T>
class Queue
{
public:
    Queue() : head(nullptr), tail(nullptr) {}
    ~Queue()
    {
        while(!isEmpty())
        {
            Node <T> *tmp = head;
            head =  head->getNext();
            
            delete tmp;
        }

    }


    bool isEmpty() const; 
    void enqueue(T dato);
    T dequeue();

    void print(ostream& os) const; 


private:
    Node <T> * head;
    Node <T> * tail;
};

template <class T> bool Queue <T>::isEmpty() const
{
    return head == nullptr;
}

template <class T> void Queue <T>:: enqueue(T dato)
{
    Node <T> * node = new Node <T> (dato);

    if(isEmpty())
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->setNext(node);
        tail = node;
    }
} 

template <typename T> T Queue <T>:: dequeue()
{
    if(isEmpty())
    {
        throw runtime_error("Coda vuota!");
    }

    Node <T> * curr = head;
    head = head->getNext();

    T val = curr->getDato();

    delete curr;

    if(isEmpty())
    {
        tail = nullptr;
    }

    return val;
} 

template <typename T> void Queue <T>::print(ostream& os) const
{
    
    Node <T> *curr = head;

    while(curr != nullptr)
    {
        curr->getDato()->stampa(os);
        os << endl;
        curr = curr->getNext();
    }
} 

template <typename T> ostream& operator << (ostream& os, const Queue <T> &q) 
{
    q.print(os);
    return os;
}


#endif 