#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Nodo{
    public:
    T valore;
    Nodo* prossimo;

    Nodo(T _valore) : prossimo(nullptr) {}
};

template <typename T>
class Pila{
    private:
    Nodo <T>* cima = nullptr;

    public:
    Pila() : cima(nullptr) {}

    void push(T valore){
        Nodo <T>* nuovo= new Nodo <T> (valore);
        nuovo->prossimo = cima;
        cima=nuovo;
    }

    void pop() {
        if(!cima) {
            cout << "Pila vuota\n";
            return;
        } else {
            Nodo <T>* tmp= cima;
            cima = cima->prossimo;
            delete tmp;
        }
    }
    
    T top() const {
        if(!cima) {
            cout << "Pila vuota\n";
        } 
        return cima->valore;
    }

    bool empty() const {
        return cima = nullptr;
    }
    
    void stampa() const {
        Nodo <T>* curr = cima;

        while(curr) {
            cout << curr->valore << " ";
            curr = curr->prossimo;
        }
        cout << endl;
    }

    ~Pila() {
        while(cima){
            Nodo <T>* tmp = cima;
            cima = cima->prossimo;
            delete tmp;
        }
    }
};