// Esercizio 14.3 - Da matrice a liste e ritorno
#include <iostream>
using namespace std;

const int N = 5;
struct Arco { int dest; Arco* succ; };

// Scorro ogni riga da DESTRA a sinistra e inserisco in testa: le liste escono in ordine crescente
void matriceInListe(bool m[N][N], Arco* adj[N]) {
    for (int i = 0; i < N; i++) {
        adj[i] = nullptr;
        for (int j = N - 1; j >= 0; j--)
            if (m[i][j]) adj[i] = new Arco{j, adj[i]};
    }
}
void listeInMatrice(Arco* adj[N], bool m[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) m[i][j] = false;
    for (int i = 0; i < N; i++)
        for (Arco* p = adj[i]; p; p = p->succ) m[i][p->dest] = true;
}

int main() {
    bool m[N][N] = {
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0}};                   // grafo ORIENTATO (non simmetrica)
    Arco* adj[N];
    matriceInListe(m, adj);
    cout << "Liste:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "  " << i << ":";
        for (Arco* p = adj[i]; p; p = p->succ) cout << " " << p->dest;
        cout << endl;
    }
    bool m2[N][N];
    listeInMatrice(adj, m2);
    bool uguali = true;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (m[i][j] != m2[i][j]) uguali = false;
    cout << "Matrice ricostruita uguale all'originale? " << (uguali ? "si" : "no") << endl;

    for (int i = 0; i < N; i++)
        while (adj[i]) { Arco* s = adj[i]->succ; delete adj[i]; adj[i] = s; }
    return 0;
}
