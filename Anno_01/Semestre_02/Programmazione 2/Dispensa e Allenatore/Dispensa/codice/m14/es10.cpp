// Esercizio 14.10 - Grafo bipartito: si possono colorare i vertici con 2 colori
// in modo che ogni arco unisca colori diversi? (BFS che alterna i colori)
#include <iostream>
using namespace std;

struct Arco { int dest; Arco* succ; };
class Coda {                                    // coda di interi (Modulo 12)
    struct Nodo { int v; Nodo* succ; };
    Nodo* testa = nullptr; Nodo* fondo = nullptr;
public:
    ~Coda() { while (!vuota()) dequeue(); }     // libera anche se esco a metà
    void enqueue(int x) { Nodo* n = new Nodo{x, nullptr}; if (!testa) testa = n; else fondo->succ = n; fondo = n; }
    int dequeue() { Nodo* t = testa; int x = t->v; testa = t->succ; if (!testa) fondo = nullptr; delete t; return x; }
    bool vuota() const { return testa == nullptr; }
};

const int N = 6;

bool bipartito(Arco* adj[], int colore[]) {
    for (int u = 0; u < N; u++) colore[u] = -1;          // -1 = non colorato
    for (int s = 0; s < N; s++) {                         // una BFS per ogni componente
        if (colore[s] != -1) continue;
        colore[s] = 0;
        Coda q;
        q.enqueue(s);
        while (!q.vuota()) {
            int u = q.dequeue();
            for (Arco* p = adj[u]; p; p = p->succ) {
                int v = p->dest;
                if (colore[v] == -1) {                    // il vicino prende il colore opposto
                    colore[v] = 1 - colore[u];
                    q.enqueue(v);
                } else if (colore[v] == colore[u]) {      // due vicini dello stesso colore
                    cout << "  stesso colore ai due estremi dell'arco " << u << "-" << v << endl;
                    return false;                         // il distruttore di q svuota la coda
                }
            }
        }
    }
    return true;
}

int main() {
    int esagono[][2] = {{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,0}};      // ciclo di 6: pari
    int triangolo[][2] = {{0,1}, {1,2}, {2,0}, {3,4}, {4,5}};             // ciclo di 3: dispari
    const char* nomi[] = {"Esagono", "Triangolo + cammino"};
    int (*grafi[])[2] = {esagono, triangolo};
    int quanti[] = {6, 5};

    for (int g = 0; g < 2; g++) {
        Arco* adj[N] = {};
        for (int k = quanti[g] - 1; k >= 0; k--) {
            int u = grafi[g][k][0], v = grafi[g][k][1];
            adj[u] = new Arco{v, adj[u]}; adj[v] = new Arco{u, adj[v]};
        }
        cout << nomi[g] << ":" << endl;
        int col[N];
        if (bipartito(adj, col)) {
            cout << "  bipartito. Gruppo 0:";
            for (int u = 0; u < N; u++) if (col[u] == 0) cout << " " << u;
            cout << " | Gruppo 1:";
            for (int u = 0; u < N; u++) if (col[u] == 1) cout << " " << u;
            cout << endl;
        } else cout << "  NON bipartito" << endl;
        for (int u = 0; u < N; u++)
            while (adj[u]) { Arco* s = adj[u]->succ; delete adj[u]; adj[u] = s; }
    }
    return 0;
}
