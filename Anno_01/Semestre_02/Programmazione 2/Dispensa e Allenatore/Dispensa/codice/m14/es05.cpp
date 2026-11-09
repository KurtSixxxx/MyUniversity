// Esercizio 14.5 - Amici, amici di amici...: la BFS stampata per livelli
#include <iostream>
#include <string>
using namespace std;

struct Arco { int dest; Arco* succ; };
class Coda {                                    // coda di interi (Modulo 12)
    struct Nodo { int v; Nodo* succ; };
    Nodo* testa = nullptr; Nodo* fondo = nullptr;
public:
    ~Coda() { while (!vuota()) dequeue(); }
    void enqueue(int x) { Nodo* n = new Nodo{x, nullptr}; if (!testa) testa = n; else fondo->succ = n; fondo = n; }
    int dequeue() { Nodo* t = testa; int x = t->v; testa = t->succ; if (!testa) fondo = nullptr; delete t; return x; }
    bool vuota() const { return testa == nullptr; }
};

const int N = 9;
string nome[N] = {"Tu", "Ada", "Bea", "Ciro", "Dina", "Ezio", "Fede", "Gino", "Lia"};

int main() {
    Arco* adj[N] = {};
    int archi[][2] = {{0,1}, {0,2}, {1,3}, {1,4}, {2,4}, {3,5}, {4,6}, {6,7}};   // Lia è isolata
    for (int k = 7; k >= 0; k--) {
        int u = archi[k][0], v = archi[k][1];
        adj[u] = new Arco{v, adj[u]}; adj[v] = new Arco{u, adj[v]};
    }
    int dist[N];
    for (int i = 0; i < N; i++) dist[i] = -1;    // -1 = non ancora scoperto
    Coda q;
    dist[0] = 0; q.enqueue(0);
    int livello = -1;
    while (!q.vuota()) {
        int u = q.dequeue();
        if (dist[u] != livello) {                // la coda contiene i vertici in ordine di distanza
            if (livello >= 0) cout << endl;      // a capo, tranne la prima volta
            livello = dist[u];
            cout << "distanza " << livello << ":";
        }
        cout << " " << nome[u];
        for (Arco* p = adj[u]; p; p = p->succ)
            if (dist[p->dest] == -1) { dist[p->dest] = dist[u] + 1; q.enqueue(p->dest); }
    }
    cout << endl << "Non raggiungibili:";
    for (int i = 0; i < N; i++) if (dist[i] == -1) cout << " " << nome[i];
    cout << endl;

    for (int u = 0; u < N; u++)
        while (adj[u]) { Arco* s = adj[u]->succ; delete adj[u]; adj[u] = s; }
    return 0;
}
