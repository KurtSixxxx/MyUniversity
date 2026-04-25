#include <iostream>
#include "lista.h"
using namespace std;

int main()
{
    List<int> lista;

    lista.insertHead(10);
    lista.insertHead(4);
    lista.insertHead(-19);

    lista.insertTail(12);

    cout << lista << endl;
}