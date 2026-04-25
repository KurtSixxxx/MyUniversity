#include <iostream>
#include "lista.h"
using namespace std;

int main()
{
    List<int> lista;

    lista.insertInOrder(5);
    lista.insertInOrder(3);
    lista.insertInOrder(8);
    lista.insertInOrder(1);
    lista.insertInOrder(9);
    lista.insertInOrder(2);

    cout << lista << endl;

    lista.deleteHead();
    lista.deleteTail();

    cout << lista << endl;

    lista.remove(3);

    cout << lista << endl;
}