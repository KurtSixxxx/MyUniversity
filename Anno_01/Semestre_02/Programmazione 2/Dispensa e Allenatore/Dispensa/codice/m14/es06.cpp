// Esercizio 14.6 - Esiste un cammino da s a t? Con la BFS e con una DFS ITERATIVA (pila)
#include <iostream>
using namespace std;

struct Arco { int dest; Arco* succ; };
struct Nodo { int v; Nodo* succ; };             // nodo di pila e coda

const int N = 7;
Arco* adj[N] = {};

bool camminoBFS(int s, int t) {
    bool vis[N] = {};
    Nodo* testa = nullptr; Nodo* fondo = nullptr;          // coda "a mano"
    vis[s] = true; testa = fondo = new Nodo{s, nullptr};
    bool trovato = false;
    while (testa) {
        Nodo* x = testa; int u = x->v; testa = testa->succ; delete x;
        if (u == t) trovato = true;                          // non esco subito: svuoto la coda
        for (Arco* p = adj[u]; p; p = p->succ)
            if (!vis[p->dest]) {
                vis[p->dest] = true;
                Nodo* n = new Nodo{p->dest, nullptr};
                if (!testa) testa = n; else fondo->succ = n;
                fondo = n;
            }
    }
    return trovato;
}

bool camminoDFS(int s, int t) {                 // la pila prende il posto della ricorsione
    bool vis[N] = {};
    Nodo* cima = new Nodo{s, nullptr};
    cout << "  ordine DFS da " << s << ":";
    bool trovato = false;
    while (cima) {
        Nodo* x = cima; int u = x->v; cima = cima->succ; delete x;   // pop
        if (vis[u]) continue;                   // può essere stato messo in pila due volte
        vis[u] = true;
        cout << " " << u;
        if (u == t) trovato = true;
        for (Arco* p = adj[u]; p; p = p->succ)
            if (!vis[p->dest]) cima = new Nodo{p->dest, cima};       // push
    }
    cout << endl;
    return trovato;
}

int main() {
    int archi[][2] = {{0,1}, {0,2}, {1,3}, {2,3}, {3,4}, {5,6}};   // due pezzi: {0..4} e {5,6}
    for (int k = 5; k >= 0; k--) {
        int u = archi[k][0], v = archi[k][1];
        adj[u] = new Arco{v, adj[u]}; adj[v] = new Arco{u, adj[v]};
    }
    int prove[][2] = {{0,4}, {2,1}, {0,6}, {5,6}};
    for (int i = 0; i < 4; i++) {
        int s = prove[i][0], t = prove[i][1];
        cout << "Da " << s << " a " << t << ":" << endl;
        bool b = camminoBFS(s, t);
        bool d = camminoDFS(s, t);
        cout << "  BFS: " << (b ? "si" : "no") << ", DFS: " << (d ? "si" : "no") << endl;
    }
    for (int u = 0; u < N; u++)
        while (adj[u]) { Arco* s = adj[u]->succ; delete adj[u]; adj[u] = s; }
    return 0;
}
