// Esercizio 11.8 - Fondere due liste ordinate riusando i nodi (nessun new)
#include <iostream>
using namespace std;

struct Nodo { int valore; Nodo* succ; };

Nodo* fondi(Nodo* a, Nodo* b) {
    Nodo finto{0, nullptr};             // nodo "sentinella" sullo stack: evita il caso speciale della testa
    Nodo* ultimo = &finto;
    while (a != nullptr && b != nullptr) {
        if (a->valore <= b->valore) { ultimo->succ = a; a = a->succ; }
        else                        { ultimo->succ = b; b = b->succ; }
        ultimo = ultimo->succ;
    }
    ultimo->succ = (a != nullptr) ? a : b;    // aggancio il resto in un colpo solo
    return finto.succ;
}

Nodo* daArray(const int v[], int n) {
    Nodo* l = nullptr;
    for (int i = n - 1; i >= 0; i--) l = new Nodo{v[i], l};
    return l;
}
void stampa(Nodo* p) { for (; p; p = p->succ) cout << p->valore << " "; cout << endl; }

int main() {
    int va[] = {1, 4, 9, 12}, vb[] = {2, 3, 10, 15, 20};
    Nodo* a = daArray(va, 4);
    Nodo* b = daArray(vb, 5);
    Nodo* f = fondi(a, b);              // a e b non vanno più usati: i loro nodi ora sono in f
    stampa(f);
    while (f) { Nodo* t = f->succ; delete f; f = t; }
    return 0;
}
