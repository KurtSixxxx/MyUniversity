#include <iostream>
using namespace std;

// Definizione del Nodo
struct Nodo {
    int valore;
    Nodo* next;
    
    // Costruttore del nodo
    Nodo(int v) : valore(v), next(NULL) {}
};

class ListaConcatenata {
private:
    Nodo* testa;

public:
    ListaConcatenata() {
        testa = NULL;
    }

    // INSERIMENTO (in testa)
    void inserisci(int v) {
        Nodo* nuovoNodo = new Nodo(v);
        nuovoNodo->next = testa;
        testa = nuovoNodo;
        cout << "Inserito: " << v << endl;
    }

    // ELIMINAZIONE (di un valore specifico)
    void elimina(int v) {
        if (testa == NULL) {
            cout << "Lista vuota." << endl;
            return;
        }

        // Caso 1: Il valore da eliminare è nella testa
        if (testa->valore == v) {
            Nodo* temp = testa;
            testa = testa->next;
            delete temp;
            cout << "Eliminato: " << v << endl;
            return;
        }

        // Caso 2: Il valore è nel mezzo o alla fine
        Nodo* corrente = testa;
        while (corrente->next != NULL && corrente->next->valore != v) {
            corrente = corrente->next;
        }

        // Se abbiamo trovato il nodo
        if (corrente->next != NULL) {
            Nodo* daEliminare = corrente->next;
            corrente->next = corrente->next->next; // Scavalca il nodo
            delete daEliminare;
            cout << "Eliminato: " << v << endl;
        } else {
            cout << "Valore non trovato." << endl;
        }
    }

    void stampa() {
        Nodo* temp = testa;
        cout << "Lista: ";
        while (temp != NULL) {
            cout << temp->valore << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    cout << "--- LISTA ---" << endl;
    ListaConcatenata lista;
    lista.inserisci(10);
    lista.inserisci(20);
    lista.inserisci(30);
    lista.stampa(); // 30 -> 20 -> 10 -> NULL
    
    lista.elimina(20);
    lista.stampa(); // 30 -> 10 -> NULL
    
    return 0;
}