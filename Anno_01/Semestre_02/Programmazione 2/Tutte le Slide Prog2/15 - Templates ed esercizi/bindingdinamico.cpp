
#include <iostream>
using namespace std;

class ClasseA {
public:
    ClasseA() {}
    int x = 100;
    virtual void dinamica(){
        cout << "Dinamica della ClasseA" << endl;
    }
    void statica(){
        cout << "Statica della ClasseA" << endl;
    }
};

class ClasseB : public ClasseA{
public:
    ClasseB() {}
    void dinamica (){
        cout << "Dinamica della ClasseB" << endl;
    }
    void statica(){
        cout << "Statica della ClasseB" << endl;
    }
};

int main(){
    ClasseA* a;
    ClasseB* b;

    a = new ClasseA();
    b = new ClasseB();

    b->x = 200;
    cout << "Chiamo i metodi di 'a': " << endl;
    a->dinamica();
    a->statica();
    cout << "a->x:\t" << a->x << endl;
    cout << endl;

    cout << "Chiamo i metodi di 'b': " << endl;
    b->dinamica();
    b->statica();
    cout << "b->x:\t" << b->x << endl;

    cout << endl;

    a = b; // Principio di sostituitibilità di Liskov
    cout << "Chiamo i metodi di 'a' dopo avergli assegnato il valore di 'b': "<< endl;
    a->dinamica();
    a->statica();
    cout << "a->x:\t" << a->x << endl;


    return 0;
}

