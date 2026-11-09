// Esercizio 11.4 - Rimuovere in testa e in coda (puntatore passato per reference)
#include <iostream>
using namespace std;

struct Nodo { int valore; Nodo* succ; };

// La testa può cambiare: la passo per REFERENCE (Nodo*&)
bool rimuoviTesta(Nodo*& testa) {
    if (testa == nullptr) return false;
    Nodo* vecchia = testa;
    testa = testa->succ;
    delete vecchia;
    return true;
}

bool rimuoviCoda(Nodo*& testa) {
    if (testa == nullptr) return false;
    if (testa->succ == nullptr) {                 // un solo nodo: la lista diventa vuota
        delete testa;
        testa = nullptr;
        return true;
    }
    Nodo* p = testa;
    while (p->succ->succ != nullptr) p = p->succ; // mi fermo sul PENULTIMO
    delete p->succ;
    p->succ = nullptr;
    return true;
}

void stampa(Nodo* p) { cout << "[ "; for (; p; p = p->succ) cout << p->valore << " "; cout << "]" << endl; }

int main() {
    Nodo* l = nullptr;
    for (int v = 5; v >= 1; v--) l = new Nodo{v, l};
    stampa(l);
    rimuoviTesta(l); stampa(l);
    rimuoviCoda(l);  stampa(l);
    while (rimuoviCoda(l)) stampa(l);             // svuoto dalla coda
    cout << "rimuoviTesta su lista vuota: " << (rimuoviTesta(l) ? "ok" : "niente da fare") << endl;
    return 0;
}
