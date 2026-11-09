// Esercizio 13.6 - Visita per livelli (in ampiezza) con una coda
#include <iostream>
using namespace std;

struct Nodo { int val; Nodo* sx = nullptr; Nodo* dx = nullptr; Nodo(int v) : val(v) {} };
Nodo* inserisci(Nodo* r, int v) {
    if (!r) return new Nodo(v);
    if (v < r->val) r->sx = inserisci(r->sx, v); else r->dx = inserisci(r->dx, v);
    return r;
}
void distruggi(Nodo* r) { if (r) { distruggi(r->sx); distruggi(r->dx); delete r; } }

// Coda minima di puntatori a nodo (Modulo 12)
struct Elem { Nodo* n; int livello; Elem* succ; };
class Coda {
    Elem* testa = nullptr; Elem* fondo = nullptr;
public:
    void enqueue(Nodo* n, int l) { Elem* e = new Elem{n, l, nullptr}; if (!testa) testa = e; else fondo->succ = e; fondo = e; }
    Elem dequeue() { Elem* v = testa; Elem x = *v; testa = testa->succ; if (!testa) fondo = nullptr; delete v; return x; }
    bool vuota() const { return testa == nullptr; }
};

void perLivelli(Nodo* radice) {
    if (!radice) return;
    Coda c;
    c.enqueue(radice, 0);
    int livelloCorrente = -1;
    while (!c.vuota()) {
        Elem e = c.dequeue();
        if (e.livello != livelloCorrente) {           // è iniziato un nuovo livello
            if (livelloCorrente >= 0) cout << endl;     // a capo, tranne la prima volta
            livelloCorrente = e.livello;
            cout << "livello " << livelloCorrente << ": ";
        }
        cout << e.n->val << " ";
        if (e.n->sx) c.enqueue(e.n->sx, e.livello + 1);   // i figli in fondo alla coda
        if (e.n->dx) c.enqueue(e.n->dx, e.livello + 1);
    }
    cout << endl;
}

int main() {
    Nodo* t = nullptr;
    int v[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (int i = 0; i < 9; i++) t = inserisci(t, v[i]);
    perLivelli(t);
    distruggi(t);
    return 0;
}
