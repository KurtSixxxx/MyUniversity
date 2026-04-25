#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Nodo{
    public:
    T valore;
    Nodo* prossimo;

    Nodo(T valore) : valore(valore), prossimo(nullptr) {}
};

template <typename T>
class Lista {
private:
    Nodo<T>* testa;

public:
    Lista() : testa(nullptr) {}

    //Inserimento in testa
    void inserisciTesta(T valore) {
        Nodo<T>* nuovo = new Nodo <T> (valore); //5 -> ?
        nuovo->prossimo = testa; // 5 -> 10(h)
        testa = nuovo; // 5(h) -> 10
    }

    //Inserimento in coda
    void inserisciCoda(T valore) {
        Nodo<T>* nuovo = new Nodo <T> (valore); 

        //Controlla se la lista è vuota
        if (testa == nullptr) {
            testa = nuovo;
            return;
        }

        Nodo<T>* curr = testa;
        //Scorre la lista 
        while (curr->prossimo != nullptr){
            curr = curr->prossimo;
        }
        curr->prossimo = nuovo;
    }

    void elimina(T valore) {
        if (testa == nullptr) return;

        //Caso: Eliminare il primo nodo
        if (testa->valore == valore) {
            Nodo<T>* tmp = testa->prossimo;
            delete testa;
            testa = tmp;
            return;
        }

        Nodo<T>* curr = testa;//10(h=curr) -> 20 -> 30 -> ecc

        //scorrimento lista
        while (curr->prossimo != nullptr) { 
            if (curr->prossimo->valore == valore) { //20 == 20
                Nodo<T>* tmp = curr->prossimo->prossimo; // tmp= 30
                delete curr->prossimo;//cancella 20
                curr->prossimo = tmp;//collegamento 10 e 30
                return;
            }
            curr = curr->prossimo;
        }
    }

    void stampa() {
        Nodo<T>* curr = testa;

        while (curr != nullptr) {
            cout << curr->valore << " -> ";
            curr = curr->prossimo;
        }
        cout << "nullptr" << endl;
    }

    //Distruttore
    ~Lista() {
        while (testa != nullptr) {
            Nodo<T>* tmp = testa;
            testa = testa->prossimo;
            delete tmp;
        }
    }
};

int main() {
    Lista<int> lista;

    lista.inserisciTesta(6);
    lista.inserisciTesta(22);
    lista.inserisciCoda(16);
    lista.inserisciCoda(90);

    lista.stampa();

    lista.elimina(90);

    lista.stampa();
}