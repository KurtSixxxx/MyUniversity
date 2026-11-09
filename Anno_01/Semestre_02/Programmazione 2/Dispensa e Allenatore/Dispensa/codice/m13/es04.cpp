// Esercizio 13.4 - Minimo e massimo di un BST, iterativi e ricorsivi
#include <iostream>
using namespace std;

struct Nodo { int val; Nodo* sx = nullptr; Nodo* dx = nullptr; Nodo(int v) : val(v) {} };
Nodo* inserisci(Nodo* r, int v) {
    if (!r) return new Nodo(v);
    if (v < r->val) r->sx = inserisci(r->sx, v); else r->dx = inserisci(r->dx, v);
    return r;
}
void distruggi(Nodo* r) { if (r) { distruggi(r->sx); distruggi(r->dx); delete r; } }

int minimoIter(Nodo* r) { while (r->sx) r = r->sx; return r->val; }   // sempre a sinistra
int massimoIter(Nodo* r) { while (r->dx) r = r->dx; return r->val; }  // sempre a destra
int minimoRic(Nodo* r) { return r->sx ? minimoRic(r->sx) : r->val; }
int massimoRic(Nodo* r) { return r->dx ? massimoRic(r->dx) : r->val; }

int main() {
    Nodo* t = nullptr;
    int v[] = {42, 17, 88, 5, 23, 61, 99, 2};
    for (int i = 0; i < 8; i++) t = inserisci(t, v[i]);
    cout << "minimo: " << minimoIter(t) << " / " << minimoRic(t) << endl;
    cout << "massimo: " << massimoIter(t) << " / " << massimoRic(t) << endl;
    distruggi(t);
    return 0;
}
