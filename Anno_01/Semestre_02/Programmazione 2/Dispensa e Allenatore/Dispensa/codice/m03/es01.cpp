// Esercizio 3.1 - Primi passi con i puntatori
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* p = &a;            // p contiene l'indirizzo di a

    cout << "a   = " << a  << "   (il valore)" << endl;
    cout << "&a  = " << &a << "   (l'indirizzo di a)" << endl;
    cout << "p   = " << p  << "   (uguale a &a)" << endl;
    cout << "*p  = " << *p << "   (il valore all'indirizzo p)" << endl;
    cout << "&p  = " << &p << "   (anche p ha un indirizzo suo!)" << endl;

    *p = 20;                // modifico a passando da p
    cout << "dopo *p = 20, a = " << a << endl;

    int b = 99;
    p = &b;                 // ora p punta a b: a non cambia piu'
    *p = 0;
    cout << "dopo p = &b e *p = 0:  a = " << a << ", b = " << b << endl;

    int** pp = &p;          // puntatore a puntatore
    **pp = 7;               // pp -> p -> b
    cout << "dopo **pp = 7, b = " << b << endl;
    return 0;
}
