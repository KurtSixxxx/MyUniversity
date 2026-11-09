// Esercizio 14.7 - Componenti connesse: numero e dimensione, con la DFS ricorsiva
#include <iostream>
using namespace std;

struct Arco { int dest; Arco* succ; };
const int N = 10;
Arco* adj[N] = {};
int comp[N];                                    // comp[u] = numero della componente di u (-1 = nessuna)

int dfs(int u, int c) {                         // restituisce quanti vertici ha marcato
    comp[u] = c;
    int quanti = 1;
    for (Arco* p = adj[u]; p; p = p->succ)
        if (comp[p->dest] == -1) quanti += dfs(p->dest, c);
    return quanti;
}

int main() {
    int archi[][2] = {{0,1}, {1,2}, {2,0}, {3,4}, {5,6}, {6,7}, {7,8}};   // 9 isolato
    for (int k = 6; k >= 0; k--) {
        int u = archi[k][0], v = archi[k][1];
        adj[u] = new Arco{v, adj[u]}; adj[v] = new Arco{u, adj[v]};
    }
    for (int u = 0; u < N; u++) comp[u] = -1;
    int c = 0;
    for (int u = 0; u < N; u++)
        if (comp[u] == -1) {
            int dim = dfs(u, c);
            cout << "Componente " << c << " (" << dim << " vertici):";
            for (int v = 0; v < N; v++) if (comp[v] == c) cout << " " << v;
            cout << endl;
            c++;
        }
    cout << "Componenti: " << c << " -> il grafo " << (c == 1 ? "e'" : "NON e'") << " connesso" << endl;
    cout << "4 e 3 nella stessa componente? " << (comp[4] == comp[3] ? "si" : "no") << endl;
    cout << "4 e 8 nella stessa componente? " << (comp[4] == comp[8] ? "si" : "no") << endl;

    for (int u = 0; u < N; u++)
        while (adj[u]) { Arco* s = adj[u]->succ; delete adj[u]; adj[u] = s; }
    return 0;
}
