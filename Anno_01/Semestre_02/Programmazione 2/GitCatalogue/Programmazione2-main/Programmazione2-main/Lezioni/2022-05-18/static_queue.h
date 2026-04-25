#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <iostream>
using namespace std;

#define MAX_SIZE 1000

template <typename T>
class StaticQueue
{
private:
    T *array;
    int head = -1;
    int size = 0;
    int maxSize = MAX_SIZE;
    int tail = -1;

public:
    StaticQueue(int _maxSize) : maxSize(_maxSize) { array = new T[maxSize]; };

    void enqueue(T val)
    {
        if (size == maxSize)
        {
            cout << "Queue is full" << endl;
            return;
        }

        if (head == -1)
        {
            head = 0;
        }

        array[++tail % maxSize] = val;
        size++;
    }

    T dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        T val = array[head];
        head = (++head % maxSize);
        size--;
        return val;
    }

    bool isEmpty()
    {
        return head == -1;
    }

    friend ostream &operator<<(ostream &os, const StaticQueue<T> queue)
    {
        if (queue.size == 0)
        {
            return os << "Queue is empty" << endl;
        }
        os << "Stacic Queue\nsize: " << queue.size << ", maxSize: " << queue.maxSize << endl;

        os << "\t" << endl;

        for (int i = queue.head, count = 0; count < queue.size; count++)
        {
            os << "queue [" << i << "] = " << queue.array[i] << endl;

            i = (i + 1) % queue.maxSize;
        }

        return os;
    }
};
#endif