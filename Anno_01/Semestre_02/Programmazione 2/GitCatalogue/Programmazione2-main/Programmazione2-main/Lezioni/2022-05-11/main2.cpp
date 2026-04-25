#include <iostream>
#include "doublelist.h"
using namespace std;

int main()
{
    DLList<int> lista;

    lista.insertHead(5);
    lista.insertHead(8);
    lista.insertHead(4);
    lista.insertHead(9);
    lista.insertHead(2);

    cout << lista << endl;

    lista.removeHead();

    cout << lista << endl;

    lista.removeTail();

    cout << lista << endl;
}