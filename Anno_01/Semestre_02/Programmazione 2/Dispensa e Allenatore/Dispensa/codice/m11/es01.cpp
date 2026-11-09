// Esercizio 11.1 - Costruire una lista "a mano" e scorrerla
#include <iostream>
using namespace std;

struct Nodo {
    int valore;
    Nodo* succ;
};

int main() {
    // Costruzione come nelle slide: ogni nuovo nodo va in TESTA
    Nodo* primo = nullptr;                       // lista vuota
    primo = new Nodo{5, primo};
    primo = new Nodo{3, primo};
    primo = new Nodo{4, primo};                  // lista: 4 -> 3 -> 5

    // Aggiungo 8 in CODA: devo arrivare all'ultimo nodo
    Nodo* p = primo;
    while (p->succ != nullptr) p = p->succ;
    p->succ = new Nodo{8, nullptr};

    // Scorrimento: il "for" delle liste
    int conta = 0, somma = 0;
    for (Nodo* q = primo; q != nullptr; q = q->succ) {
        cout << q->valore << " ";
        conta++;
        somma += q->valore;
    }
    cout << "\nnodi: " << conta << ", somma: " << somma << endl;

    // Liberare tutto: salvo il successivo PRIMA di cancellare
    while (primo != nullptr) {
        Nodo* tmp = primo->succ;
        delete primo;
        primo = tmp;
    }
    cout << "memoria liberata" << endl;
    return 0;
}
