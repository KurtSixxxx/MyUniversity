// Esercizio 11.6 - Invertire una lista: iterativo (3 puntatori) e ricorsivo
#include <iostream>
using namespace std;

struct Nodo { int valore; Nodo* succ; };

Nodo* invertiIter(Nodo* testa) {
    Nodo* prec = nullptr;
    Nodo* corr = testa;
    while (corr != nullptr) {
        Nodo* succ = corr->succ;     // salvo il resto della lista
        corr->succ = prec;           // giro la freccia
        prec = corr;
        corr = succ;
    }
    return prec;                     // nuova testa
}

// Inverto il resto, poi aggancio me stesso in fondo
Nodo* invertiRic(Nodo* testa) {
    if (testa == nullptr || testa->succ == nullptr) return testa;   // 0 o 1 nodi
    Nodo* nuovaTesta = invertiRic(testa->succ);
    testa->succ->succ = testa;       // il mio vecchio successivo ora punta a me
    testa->succ = nullptr;           // io divento l'ultimo
    return nuovaTesta;
}

void stampa(Nodo* p) { for (; p; p = p->succ) cout << p->valore << " "; cout << endl; }

int main() {
    Nodo* l = nullptr;
    for (int v = 6; v >= 1; v--) l = new Nodo{v, l};
    stampa(l);
    l = invertiIter(l); stampa(l);
    l = invertiRic(l);  stampa(l);
    while (l) { Nodo* t = l->succ; delete l; l = t; }
    return 0;
}
