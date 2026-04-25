#ifndef CODA_H
#define CODa_H


#include <iostream>

using namespace std;


template  <typename T>
class Node
{
public:
    Node(T d) : dato(d), next(nullptr) {}
    
    T getDato() {return dato;}
    Node <T> * getNext() {return next;}

    void setDato(T d) {dato = d;}
    void setNext(Node <T>* n) {next = n;}

private:
    Node <T> *next;
    T dato;
};

template <typename T>
class Queue
{
public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    int getSize() {return size;}
    Node <T> * getHead() {return head;}

    
    ~Queue()
    {
        clear();  
    }

    bool isEmpty()
    {
        return head == nullptr;
    }


    void enqueue(T val)
    {
        Node <T>* node = new Node <T> (val);

        if(isEmpty())
        {
            head = node;
            tail = head;
            size++;
        }
        else
        {
            tail->setNext(node);  // tail->next = node;
            tail = node;
            size++;

        }

        
    }

    T dequeue()
    {
        if(head == nullptr)
        {
            return T();
        }


        Node <T> *curr = head;
        head = curr->getNext();

        if(head == nullptr)
        {
            tail = nullptr;
        }

        
        T val = curr->getDato();

        delete curr;
        size--;
        return val;
    } 

    T front()
    {
       if(head == nullptr)
       {
            return T();
       }

       return head->getDato();
    } 

    void stampa(ostream& os) const
    {
        Node <T> * curr = head;

        while(curr !=nullptr)
        {
            os << *(curr->getDato());
            curr = curr->getNext();
        }

    }

    
private:
    Node <T> *head;
    Node <T> *tail;
    int size;

    void clear()
    {
        while(head != nullptr)
        {
            Node <T> *curr = head;
            head = head->getNext();

            delete curr;
        }

        tail = nullptr;
    }
};

template <typename T>
ostream& operator << (ostream& os, const Queue <T> &Q)
{
    Q.stampa(os);
    return os;
}

#endif