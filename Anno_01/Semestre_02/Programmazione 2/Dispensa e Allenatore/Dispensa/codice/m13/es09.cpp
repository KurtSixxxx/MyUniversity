// Esercizio 13.9 - BST bilanciato da un array ordinato
#include <iostream>
using namespace std;

struct Nodo { int val; Nodo* sx = nullptr; Nodo* dx = nullptr; Nodo(int v) : val(v) {} };

// Il mediano diventa la radice, le due metà diventano i sottoalberi (divide et impera)
Nodo* costruisci(const int v[], int a, int b) {
    if (a > b) return nullptr;
    int m = (a + b) / 2;
    Nodo* r = new Nodo(v[m]);
    r->sx = costruisci(v, a, m - 1);
    r->dx = costruisci(v, m + 1, b);
    return r;
}
int altezza(Nodo* r) { if (!r) return -1; int a = altezza(r->sx), b = altezza(r->dx); return 1 + (a > b ? a : b); }
void in(Nodo* r) { if (r) { in(r->sx); cout << r->val << " "; in(r->dx); } }
void pre(Nodo* r) { if (r) { cout << r->val << " "; pre(r->sx); pre(r->dx); } }
void distruggi(Nodo* r) { if (r) { distruggi(r->sx); distruggi(r->dx); delete r; } }

int main() {
    int v[15];
    for (int i = 0; i < 15; i++) v[i] = (i + 1) * 10;
    Nodo* t = costruisci(v, 0, 14);
    cout << "in-order:  "; in(t);  cout << endl;
    cout << "pre-order: "; pre(t); cout << endl;
    cout << "15 nodi, altezza " << altezza(t) << " (il minimo possibile: 15 = 2^4 - 1)" << endl;
    distruggi(t);
    return 0;
}
