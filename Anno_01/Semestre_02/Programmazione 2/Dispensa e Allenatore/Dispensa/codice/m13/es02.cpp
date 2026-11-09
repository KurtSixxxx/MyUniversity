// Esercizio 13.2 - Contare nodi, foglie, nodi interni e sommare i valori
#include <iostream>
using namespace std;

struct Nodo { int val; Nodo* sx = nullptr; Nodo* dx = nullptr; Nodo(int v) : val(v) {} };
Nodo* inserisci(Nodo* r, int v) {
    if (!r) return new Nodo(v);
    if (v < r->val) r->sx = inserisci(r->sx, v); else r->dx = inserisci(r->dx, v);
    return r;
}
void distruggi(Nodo* r) { if (r) { distruggi(r->sx); distruggi(r->dx); delete r; } }

// Lo schema è sempre lo stesso: caso base sull'albero vuoto, poi "io + sinistra + destra"
int nodi(Nodo* r)   { return r ? 1 + nodi(r->sx) + nodi(r->dx) : 0; }
int foglie(Nodo* r) {
    if (!r) return 0;
    if (!r->sx && !r->dx) return 1;                     // nessun figlio: è una foglia
    return foglie(r->sx) + foglie(r->dx);
}
int somma(Nodo* r)  { return r ? r->val + somma(r->sx) + somma(r->dx) : 0; }

int main() {
    Nodo* t = nullptr;
    int v[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (int i = 0; i < 9; i++) t = inserisci(t, v[i]);
    cout << "nodi " << nodi(t) << ", foglie " << foglie(t) << ", interni " << nodi(t) - foglie(t)
         << ", somma " << somma(t) << endl;
    distruggi(t);
    return 0;
}
