// Esercizio 14.4 - Grafo orientato: grado entrante, grado uscente, grafo trasposto
#include <iostream>
using namespace std;

struct Arco { int dest; Arco* succ; };
const int N = 5;

void stampa(Arco* adj[]) {
    for (int u = 0; u < N; u++) {
        cout << "  " << u << ":";
        for (Arco* p = adj[u]; p; p = p->succ) cout << " " << p->dest;
        cout << endl;
    }
}
void libera(Arco* adj[]) {
    for (int u = 0; u < N; u++)
        while (adj[u]) { Arco* s = adj[u]->succ; delete adj[u]; adj[u] = s; }
}

int main() {
    Arco* adj[N] = {};
    int archi[][2] = {{0,1}, {0,2}, {1,2}, {2,0}, {3,2}, {3,4}};
    for (int k = 5; k >= 0; k--) {                         // al contrario: liste in ordine
        int u = archi[k][0], v = archi[k][1];
        adj[u] = new Arco{v, adj[u]};
    }
    cout << "Grafo G:" << endl; stampa(adj);

    // Uscente = lunghezza della propria lista. Entrante = quante volte compaio nelle liste ALTRUI.
    int uscente[N] = {}, entrante[N] = {};
    for (int u = 0; u < N; u++)
        for (Arco* p = adj[u]; p; p = p->succ) { uscente[u]++; entrante[p->dest]++; }
    for (int u = 0; u < N; u++)
        cout << "  vertice " << u << ": uscente " << uscente[u] << ", entrante " << entrante[u]
             << ", grado " << uscente[u] + entrante[u] << endl;

    // Trasposto: ogni arco (u,v) diventa (v,u). Un solo passaggio su tutte le liste: O(V+E).
    Arco* tr[N] = {};
    for (int u = N - 1; u >= 0; u--)
        for (Arco* p = adj[u]; p; p = p->succ)
            tr[p->dest] = new Arco{u, tr[p->dest]};
    cout << "Grafo trasposto:" << endl; stampa(tr);

    libera(adj); libera(tr);
    return 0;
}
