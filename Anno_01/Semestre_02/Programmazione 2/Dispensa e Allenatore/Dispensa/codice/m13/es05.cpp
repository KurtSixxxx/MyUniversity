// Esercizio 13.5 - Albero bilanciato contro albero degenere: O(h) fa la differenza
#include <iostream>
using namespace std;

struct Nodo { int val; Nodo* sx = nullptr; Nodo* dx = nullptr; Nodo(int v) : val(v) {} };

void inserisci(Nodo*& r, int v) {                       // iterativo: niente rischio di stack overflow
    Nodo** p = &r;                                      // puntatore al "posto" dove andrà il nodo
    while (*p) p = (v < (*p)->val) ? &(*p)->sx : &(*p)->dx;
    *p = new Nodo(v);
}
int confronti;
bool cerca(Nodo* r, int v) {
    while (r) {
        confronti++;
        if (v == r->val) return true;
        r = (v < r->val) ? r->sx : r->dx;
    }
    return false;
}
void distruggi(Nodo* r) { while (r) { distruggi(r->sx); Nodo* d = r->dx; delete r; r = d; } }

// Inserisco prima il mediano e poi, ricorsivamente, i mediani delle due metà
void inserisciBilanciato(Nodo*& r, int a, int b) {
    if (a > b) return;
    int m = (a + b) / 2;
    inserisci(r, m);
    inserisciBilanciato(r, a, m - 1);
    inserisciBilanciato(r, m + 1, b);
}

int main() {
    const int N = 1000;
    Nodo* degenere = nullptr;
    for (int i = 1; i <= N; i++) inserisci(degenere, i);   // valori già ordinati: una "lista"
    Nodo* bilanciato = nullptr;
    inserisciBilanciato(bilanciato, 1, N);

    confronti = 0; cerca(degenere, N);
    cout << "degenere:   cercare " << N << " costa " << confronti << " confronti" << endl;
    confronti = 0; cerca(bilanciato, N);
    cout << "bilanciato: cercare " << N << " costa " << confronti << " confronti" << endl;
    distruggi(degenere);
    distruggi(bilanciato);
    return 0;
}
