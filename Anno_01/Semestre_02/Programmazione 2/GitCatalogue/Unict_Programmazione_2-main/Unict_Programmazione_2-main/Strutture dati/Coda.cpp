#include <iostream>
using namespace std;

struct Nodo {
    int valore;
    Nodo* next;
    Nodo(int v) : valore(v), next(NULL) {}
};

class Coda {
private:
    Nodo* head; // Testa (per eliminare)
    Nodo* tail;  // Coda (per inserire)

public:
    Coda() {
        head = NULL;
        tail = NULL;
    }

    // INSERIMENTO (Enqueue)
    void enqueue(int v) {
        Nodo* nuovoNodo = new Nodo(v);
        
        if (head == NULL) {

            tail = head = nuovoNodo;
        } else {
            tail->next = nuovoNodo; // Collega l'attuale ultimo al nuovo
            head = nuovoNodo;      
        }
        cout << "Enqueue: " << v << endl;
    }

    // ELIMINAZIONE (Dequeue)
    void dequeue() {
        if (head == NULL) {
            cout << "Errore: Coda vuota!" << endl;
            return;
        }
        
        Nodo* temp = head;
        head = head->next; 

        // Se dopo la rimozione front diventa NULL, anche rear deve esserlo
        if (head == NULL) {
            tail = NULL;
        }

        cout << "Dequeue: " << temp->valore << endl;
        delete temp;
    }

    void stampa() {
        Nodo* temp = head;
        cout << "Coda (head -> tail): ";
        while (temp != NULL) {
            cout << temp->valore << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    cout << "--- CODA (QUEUE) ---" << endl;
    Coda q;
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.stampa(); // 100 -> 200 -> 300 -> NULL
    
    q.dequeue(); // Rimuove 100
    q.stampa();  // 200 -> 300 -> NULL
    
    return 0;
}