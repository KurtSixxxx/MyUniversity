// Esercizio 13.3 - Altezza dell'albero e livello (profondità) di un valore
#include <iostream>
using namespace std;

struct Nodo { int val; Nodo* sx = nullptr; Nodo* dx = nullptr; Nodo(int v) : val(v) {} };
Nodo* inserisci(Nodo* r, int v) {
    if (!r) return new Nodo(v);
    if (v < r->val) r->sx = inserisci(r->sx, v); else r->dx = inserisci(r->dx, v);
    return r;
}
void distruggi(Nodo* r) { if (r) { distruggi(r->sx); distruggi(r->dx); delete r; } }

int altezza(Nodo* r) {                       // vuoto: -1, una sola foglia: 0
    if (!r) return -1;
    int a = altezza(r->sx), b = altezza(r->dx);
    return 1 + (a > b ? a : b);
}

int livello(Nodo* r, int x) {                // distanza dalla radice, -1 se assente
    int lv = 0;
    while (r) {
        if (x == r->val) return lv;
        r = (x < r->val) ? r->sx : r->dx;
        lv++;
    }
    return -1;
}

int main() {
    Nodo* t = nullptr;
    int v[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (int i = 0; i < 9; i++) t = inserisci(t, v[i]);
    cout << "altezza: " << altezza(t) << endl;
    int prove[] = {8, 10, 6, 13, 99};
    for (int i = 0; i < 5; i++) cout << prove[i] << " e' al livello " << livello(t, prove[i]) << endl;
    distruggi(t);
    return 0;
}
