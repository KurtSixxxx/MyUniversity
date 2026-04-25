#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Nodo {
    public:
    T valore;
    Nodo* prossimo;
    Nodo* precedente;

    Nodo(T valore) : valore(valore), prossimo(nullptr), precedente(nullptr) {}
};

template <typename T>
class Lista {
    private:
    Nodo<T>* testa;
    Nodo<T>* coda;

    public:
    Lista() : testa(nullptr), coda(nullptr) {}

    //Inserimento in testa
    void inserisciTesta(T valore) {
        Nodo<T>* nuovo= new Nodo <T> (valore);

        if(testa==nullptr) {
            testa = coda = nuovo;
            return;
        }

        nuovo->prossimo= testa;
        testa->precedente= nuovo;
        testa= nuovo;
    }

    //Inserimento in coda
    void inserisciCoda(T valore) {
        Nodo<T>* nuovo= new Nodo <T> (valore);

        if(coda == nullptr) {
            testa = coda = nuovo;
            return;
        }

        coda->prossimo = nuovo;
        nuovo->precedente= coda;
        coda= nuovo;
    }

    void elimina(T valore) {
        if( testa == nullptr) return;

        Nodo<T>* curr= testa;
        while(curr != nullptr) {
            if(curr->valore == valore) {
                //Caso: testa
                if(curr == testa) {
                    testa= testa->prossimo;
                    testa->precedente = nullptr;
                } /*Caso: coda*/ else if(curr == coda) {
                    coda= coda->precedente;
                    coda->prossimo= nullptr;
                } /*Caso: coda*/ else {
                    curr->precedente->prossimo = curr->prossimo;
                    curr->prossimo->precedente= curr->precedente;
                }
                delete curr;
                return;
            }
            curr= curr->prossimo;
        }
    }

    void stampAvanti() {
        Nodo<T>* curr= testa;

        while(curr != nullptr) {
            cout << curr->valore << " <-> ";
            curr= curr->prossimo;
        }
        cout << "nullptr" << endl;
    }

    void stampaInversa() {
        Nodo<T>* curr = coda;

        while (curr != nullptr) {
            cout << curr->valore << " <-> ";
            curr = curr->precedente;
        }
        cout << "nullptr" << endl;
    }

    ~Lista() {
        while (testa != nullptr) {
            Nodo<T>* tmp = testa;
            testa = testa->prossimo;
            delete tmp;
        }
    }
};

