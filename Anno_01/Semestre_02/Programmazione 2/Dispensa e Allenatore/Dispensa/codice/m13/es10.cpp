// Esercizio 13.10 - Successore e predecessore con il puntatore al padre (algoritmo delle slide)
#include <iostream>
using namespace std;

struct Nodo { int val; Nodo* sx = nullptr; Nodo* dx = nullptr; Nodo* padre = nullptr; Nodo(int v) : val(v) {} };

Nodo* inserisci(Nodo*& root, int v) {
    Nodo* y = nullptr;
    Nodo* x = root;
    while (x) { y = x; x = (v < x->val) ? x->sx : x->dx; }
    Nodo* n = new Nodo(v);
    n->padre = y;
    if (!y) root = n; else if (v < y->val) y->sx = n; else y->dx = n;
    return n;
}
Nodo* minimo(Nodo* x) { while (x->sx) x = x->sx; return x; }
Nodo* massimo(Nodo* x) { while (x->dx) x = x->dx; return x; }

Nodo* successore(Nodo* x) {
    if (x->dx) return minimo(x->dx);          // caso 1: il più piccolo del sottoalbero destro
    Nodo* y = x->padre;                        // caso 2: risalgo finché arrivo da un figlio SINISTRO
    while (y && x == y->dx) { x = y; y = y->padre; }
    return y;
}
Nodo* predecessore(Nodo* x) {                  // simmetrico
    if (x->sx) return massimo(x->sx);
    Nodo* y = x->padre;
    while (y && x == y->sx) { x = y; y = y->padre; }
    return y;
}
void distruggi(Nodo* r) { if (r) { distruggi(r->sx); distruggi(r->dx); delete r; } }

int main() {
    Nodo* root = nullptr;
    int v[] = {15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};       // l'albero delle figure del libro di Cormen
    Nodo* nodi[11];
    for (int i = 0; i < 11; i++) nodi[i] = inserisci(root, v[i]);
    for (int i = 0; i < 11; i++) {
        Nodo* s = successore(nodi[i]);
        Nodo* p = predecessore(nodi[i]);
        cout << v[i] << ": predecessore " << (p ? to_string(p->val) : "-")
             << ", successore " << (s ? to_string(s->val) : "-") << endl;
    }
    cout << "scorrimento in ordine con i successori: ";
    for (Nodo* x = minimo(root); x; x = successore(x)) cout << x->val << " ";
    cout << endl;
    distruggi(root);
    return 0;
}
