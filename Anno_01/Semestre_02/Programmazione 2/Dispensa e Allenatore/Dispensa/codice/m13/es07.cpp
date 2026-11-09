// Esercizio 13.7 - Il k-esimo più piccolo e i valori in un intervallo
#include <iostream>
using namespace std;

struct Nodo { int val; Nodo* sx = nullptr; Nodo* dx = nullptr; Nodo(int v) : val(v) {} };
Nodo* inserisci(Nodo* r, int v) {
    if (!r) return new Nodo(v);
    if (v < r->val) r->sx = inserisci(r->sx, v); else r->dx = inserisci(r->dx, v);
    return r;
}
void distruggi(Nodo* r) { if (r) { distruggi(r->sx); distruggi(r->dx); delete r; } }

// In-order "conta" i nodi in ordine crescente: mi fermo al k-esimo
void kEsimo(Nodo* r, int k, int& contati, int& risultato) {
    if (!r || contati >= k) return;
    kEsimo(r->sx, k, contati, risultato);
    if (++contati == k) { risultato = r->val; return; }
    kEsimo(r->dx, k, contati, risultato);
}

// Stampa i valori in [a, b], senza visitare i rami inutili
void intervallo(Nodo* r, int a, int b) {
    if (!r) return;
    if (a < r->val) intervallo(r->sx, a, b);          // a sinistra c'è qualcosa >= a solo se a < val
    if (a <= r->val && r->val <= b) cout << r->val << " ";
    if (r->val < b) intervallo(r->dx, a, b);
}

int main() {
    Nodo* t = nullptr;
    int v[] = {50, 30, 70, 20, 40, 60, 80, 35, 65};
    for (int i = 0; i < 9; i++) t = inserisci(t, v[i]);
    for (int k = 1; k <= 9; k += 4) {
        int contati = 0, ris = -1;
        kEsimo(t, k, contati, ris);
        cout << k << "-esimo piu' piccolo: " << ris << endl;
    }
    cout << "valori in [33, 66]: ";
    intervallo(t, 33, 66);
    cout << endl;
    distruggi(t);
    return 0;
}
