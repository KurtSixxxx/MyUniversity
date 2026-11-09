// Esercizio 11.2 - Ricerca che restituisce il nodo: modificare un valore "sul posto"
#include <iostream>
using namespace std;

struct Nodo { int valore; Nodo* succ; };

Nodo* ricerca(Nodo* testa, int x) {
    for (Nodo* p = testa; p != nullptr; p = p->succ)
        if (p->valore == x) return p;
    return nullptr;
}

int posizione(Nodo* testa, int x) {              // indice (da 0) della prima occorrenza
    int i = 0;
    for (Nodo* p = testa; p != nullptr; p = p->succ, i++)
        if (p->valore == x) return i;
    return -1;
}

void stampa(Nodo* p) { for (; p; p = p->succ) cout << p->valore << " "; cout << endl; }

int main() {
    Nodo* l = nullptr;
    for (int v = 50; v >= 10; v -= 10) l = new Nodo{v, l};    // 10 20 30 40 50
    stampa(l);
    Nodo* trovato = ricerca(l, 30);
    if (trovato) trovato->valore = 33;                        // modifico il nodo vero della lista
    stampa(l);
    cout << "33 in posizione " << posizione(l, 33) << ", 99 in posizione " << posizione(l, 99) << endl;
    while (l) { Nodo* t = l->succ; delete l; l = t; }
    return 0;
}
