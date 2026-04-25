#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "Costruttore di A" << endl; }
    virtual void stampa() { cout << "Sono la classe A" << endl; }
};

class B : public A
{
public:
    B() : A() { cout << "Costruttore di B" << endl; }
    void stampa() { cout << "Sono la classe B" << endl; }
};

int main()
{
    A a;
    B b;

    cout << "Chiamata ai metodi delle istanze di A e B" << endl;

    a.stampa();
    b.stampa();

    cout << "Creo dei riferimenti di a e b e dichiaro entrambi di classe A&" << endl;

    A &ra = a;
    A &rb = b;

    ra.stampa();
    rb.stampa();

    cout << "Creo dei puntatori ad A ed assegno a ciascuno l'indirizzo di a e b" << endl;
    A *pa = &a;
    A *pb = &b;

    pa->stampa();
    pb->stampa();
}