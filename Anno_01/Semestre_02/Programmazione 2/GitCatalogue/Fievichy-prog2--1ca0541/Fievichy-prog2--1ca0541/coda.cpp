#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Nodo{
    public:
    T valore;
    Nodo* prossimo;

    Nodo(T v): valore(v), prossimo(nullptr){}
};

template <typename T>
class Coda{
    private:
    Nodo<T>* testa=nullptr;
    Nodo<T>* fondo=nullptr;

    public:
    Coda(): testa(nullptr), fondo(nullptr){}

    void enqueue(T v){
        Nodo<T>* nuovo= new Nodo <T> (v);
        if(!fondo){
            testa=fondo=nuovo;
        }
        fondo->prossimo=nuovo;
        fondo=nuovo;
    }

    void dequeue(){
        if(!testa){
            cout << "Coda vuota\n";
            return;
        } else {
            Nodo<T>* tmp= testa;
            testa= testa->prossimo;
            if(!testa) fondo=nullptr;
            delete tmp;
        }
    }

    void stampa() const {
        Nodo<T>* curr=testa;
        while(curr) {
            curr->valore->stampa();
            cout << endl;
            curr= curr->prossimo;
        }
    }

    ~Coda(){
        while(testa){
            Nodo<T>* tmp=testa;
            testa= testa->prossimo;
            delete tmp->valore;
            delete tmp;
        }
    }
};

