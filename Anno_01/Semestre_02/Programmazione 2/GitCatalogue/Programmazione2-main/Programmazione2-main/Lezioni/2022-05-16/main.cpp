#include <iostream>
#include "stack.h"
#include "static_stack.h"
using namespace std;

int main()
{
    Stack<int> stack;

    stack.push(10);
    stack.push(12);
    stack.push(20);
    stack.push(18);
    stack.push(25);
    stack.push(26);

    cout << stack << endl;

    stack.pop();
    stack.pop();

    cout << stack << endl;

    Node<int> *top = stack.top();
    cout << *top << endl;

    StaticStack<int> staticstack(10);

    staticstack.push(20);
    staticstack.push(18);
    staticstack.push(25);
    staticstack.push(26);

    cout << staticstack << endl;

    staticstack.pop();
    staticstack.pop();

    cout << staticstack << endl;
}