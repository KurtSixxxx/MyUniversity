#include <iostream>
using namespace std;

struct Nodo {
    int valore;
    Nodo* next;
    Nodo(int v) : valore(v), next(NULL) {}
};

class Pila {
private:
    Nodo* top; // Cima della pila

public:
    Pila() {
        top = NULL;
    }

    // INSERIMENTO (Push)
    void push(int v) {
        Nodo* nuovoNodo = new Nodo(v);
        nuovoNodo->next = top; // Il nuovo punta al vecchio top
        top = nuovoNodo;       // Aggiorniamo il top
        cout << "Push: " << v << endl;
    }

    // ELIMINAZIONE (Pop)
    void pop() {
        if (top == NULL) {
            cout << "Errore: Pila vuota!" << endl;
            return;
        }
        Nodo* temp = top;
        top = top->next; // Il top diventa il secondo elemento
        cout << "Pop: " << temp->valore << endl;
        delete temp;
    }

    void stampa() {
        Nodo* temp = top;
        cout << "Pila (Dall'alto): ";
        while (temp != NULL) {
            cout << temp->valore << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    cout << "--- PILA (STACK) ---" << endl;
    Pila s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.stampa(); // 15 10 5
    
    s.pop();    // Rimuove 15
    s.stampa(); // 10 5
    
    return 0;
}