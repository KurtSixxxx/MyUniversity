// Esercizio 14.2 - Liste di adiacenza "a mano": array di liste, somma delle lunghezze
#include <iostream>
using namespace std;

struct Arco { int dest; Arco* succ; };

void aggiungi(Arco* adj[], int u, int v) { adj[u] = new Arco{v, adj[u]}; }   // in testa

int lunghezza(Arco* p) { int n = 0; for (; p; p = p->succ) n++; return n; }

void stampa(Arco* adj[], int n) {
    for (int u = 0; u < n; u++) {
        cout << "  " << u << ":";
        for (Arco* p = adj[u]; p; p = p->succ) cout << " -> " << p->dest;
        cout << " -> null" << endl;
    }
}
void libera(Arco* adj[], int n) {
    for (int u = 0; u < n; u++)
        while (adj[u]) { Arco* s = adj[u]->succ; delete adj[u]; adj[u] = s; }
}

int main() {
    const int N = 4;
    int archi[][2] = {{0,1}, {0,2}, {1,2}, {2,3}};      // 4 archi

    Arco* nonOr[N] = {};                    // tutte le teste a nullptr
    Arco* orient[N] = {};
    for (int k = 0; k < 4; k++) {
        int u = archi[k][0], v = archi[k][1];
        aggiungi(nonOr, u, v); aggiungi(nonOr, v, u);  // non orientato: due inserimenti
        aggiungi(orient, u, v);                         // orientato: uno solo
    }
    int s1 = 0, s2 = 0;
    for (int u = 0; u < N; u++) { s1 += lunghezza(nonOr[u]); s2 += lunghezza(orient[u]); }

    cout << "Non orientato:" << endl; stampa(nonOr, N);
    cout << "Somma lunghezze = " << s1 << " = 2 * 4 archi" << endl;
    cout << "Orientato:" << endl; stampa(orient, N);
    cout << "Somma lunghezze = " << s2 << " = 4 archi" << endl;

    libera(nonOr, N); libera(orient, N);
    return 0;
}
