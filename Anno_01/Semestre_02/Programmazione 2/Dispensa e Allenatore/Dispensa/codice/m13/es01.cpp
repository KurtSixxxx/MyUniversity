// Esercizio 13.1 - Costruire un BST e stamparne le tre visite
#include <iostream>
using namespace std;

struct Nodo {
    int val;
    Nodo* sx = nullptr;
    Nodo* dx = nullptr;
    Nodo(int v) : val(v) {}
};

// Inserimento ricorsivo: restituisce la radice (eventualmente nuova) del sottoalbero
Nodo* inserisci(Nodo* r, int v) {
    if (r == nullptr) return new Nodo(v);
    if (v < r->val) r->sx = inserisci(r->sx, v);
    else r->dx = inserisci(r->dx, v);
    return r;
}
void pre(Nodo* r)  { if (r) { cout << r->val << " "; pre(r->sx); pre(r->dx); } }
void in(Nodo* r)   { if (r) { in(r->sx); cout << r->val << " "; in(r->dx); } }
void post(Nodo* r) { if (r) { post(r->sx); post(r->dx); cout << r->val << " "; } }
void distruggi(Nodo* r) { if (r) { distruggi(r->sx); distruggi(r->dx); delete r; } }

int main() {
    Nodo* radice = nullptr;
    int v[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) radice = inserisci(radice, v[i]);
    cout << "pre-order:  "; pre(radice);  cout << endl;   // radice, sinistra, destra
    cout << "in-order:   "; in(radice);   cout << endl;   // sinistra, radice, destra -> ORDINATO
    cout << "post-order: "; post(radice); cout << endl;   // sinistra, destra, radice
    distruggi(radice);
    return 0;
}
