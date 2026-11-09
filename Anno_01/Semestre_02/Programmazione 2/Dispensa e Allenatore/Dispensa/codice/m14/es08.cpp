// Esercizio 14.8 - C'è un ciclo in un grafo orientato? DFS con i tre colori
#include <iostream>
using namespace std;

struct Arco { int dest; Arco* succ; };
enum Colore { BIANCO, GRIGIO, NERO };
const int N = 5;

// Restituisce true se dalla visita di u si trova un arco verso un vertice GRIGIO:
// un grigio è un antenato ancora "aperto" sulla pila delle chiamate -> si torna indietro = ciclo.
bool visita(Arco* adj[], Colore col[], int u) {
    col[u] = GRIGIO;
    for (Arco* p = adj[u]; p; p = p->succ) {
        int v = p->dest;
        if (col[v] == GRIGIO) {
            cout << "  arco all'indietro " << u << " -> " << v << endl;
            return true;
        }
        if (col[v] == BIANCO && visita(adj, col, v)) return true;
        // se v è NERO è già stato esplorato tutto: nessun ciclo passa da lì verso u
    }
    col[u] = NERO;
    return false;
}
bool haCiclo(Arco* adj[]) {
    Colore col[N];
    for (int u = 0; u < N; u++) col[u] = BIANCO;
    for (int u = 0; u < N; u++)
        if (col[u] == BIANCO && visita(adj, col, u)) return true;
    return false;
}
void costruisci(Arco* adj[], int archi[][2], int m) {
    for (int u = 0; u < N; u++) adj[u] = nullptr;
    for (int k = m - 1; k >= 0; k--) adj[archi[k][0]] = new Arco{archi[k][1], adj[archi[k][0]]};
}
void libera(Arco* adj[]) {
    for (int u = 0; u < N; u++)
        while (adj[u]) { Arco* s = adj[u]->succ; delete adj[u]; adj[u] = s; }
}

int main() {
    Arco* adj[N];
    int dag[][2] = {{0,1}, {0,2}, {1,3}, {2,3}, {3,4}};          // "rombo": due strade per 3, nessun ciclo
    costruisci(adj, dag, 5);
    cout << "Grafo 1:" << endl;
    bool c = haCiclo(adj);                      // prima la chiamata (che può stampare)...
    cout << "  ciclo? " << (c ? "si" : "no") << endl;   // ...poi il risultato
    libera(adj);

    int ciclico[][2] = {{0,1}, {1,2}, {2,3}, {3,1}, {3,4}};      // 1 -> 2 -> 3 -> 1
    costruisci(adj, ciclico, 5);
    cout << "Grafo 2:" << endl;
    c = haCiclo(adj);
    cout << "  ciclo? " << (c ? "si" : "no") << endl;
    libera(adj);
    return 0;
}
