#include <iostream>
using namespace std;

#include "queue.h"
#include "static_queue.h"
int main()
{
    Queue<int> queue;

    queue.enqueue(12);
    queue.enqueue(18);
    queue.enqueue(34);
    queue.enqueue(20);

    queue.dequeue();

    cout << queue << endl;

    StaticQueue<int> static_queue(10);

    static_queue.enqueue(1);
    static_queue.enqueue(2);
    static_queue.enqueue(3);
    static_queue.enqueue(4);
    static_queue.enqueue(5);

    cout << static_queue << endl;

    static_queue.dequeue();

    cout << static_queue << endl;
}