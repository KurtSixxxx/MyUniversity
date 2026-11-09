// Esercizio 14.9 - Uscire dal labirinto: BFS su una griglia (grafo "implicito")
#include <iostream>
using namespace std;

const int R = 7, C = 10;
char lab[R][C + 1] = {                  // '#' muro, '.' libero, 'S' partenza, 'U' uscita
    "S.#.......",
    ".##.####.#",
    "....#....#",
    "##.##.##.#",
    "...#..#...",
    ".#...##.#.",
    "...#....#U"};

// Ogni cella libera è un vertice; i vicini sono le 4 celle adiacenti libere.
// Numero il vertice (r, c) come r*C + c, così basta un intero per la coda.
struct Nodo { int v; Nodo* succ; };

int main() {
    int dist[R * C], pred[R * C];
    for (int i = 0; i < R * C; i++) { dist[i] = -1; pred[i] = -1; }
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};   // su, giù, sinistra, destra

    int s = 0, u_fine = (R - 1) * C + (C - 1);        // S in alto a sinistra, U in basso a destra
    Nodo* testa = new Nodo{s, nullptr}; Nodo* fondo = testa;
    dist[s] = 0;
    while (testa) {
        Nodo* x = testa; int u = x->v; testa = testa->succ; delete x;
        if (!testa) fondo = nullptr;
        int r = u / C, c = u % C;
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;   // fuori dalla griglia
            if (lab[nr][nc] == '#') continue;                       // muro
            int v = nr * C + nc;
            if (dist[v] != -1) continue;                            // già scoperta
            dist[v] = dist[u] + 1; pred[v] = u;
            Nodo* n = new Nodo{v, nullptr};
            if (!testa) testa = n; else fondo->succ = n;
            fondo = n;
        }
    }
    if (dist[u_fine] == -1) { cout << "Nessuna uscita!" << endl; return 0; }
    cout << "Uscita raggiunta in " << dist[u_fine] << " passi" << endl;
    for (int v = pred[u_fine]; v != s; v = pred[v])   // risalgo con pred e segno il percorso
        lab[v / C][v % C] = 'o';
    for (int r = 0; r < R; r++) cout << "  " << lab[r] << endl;
    return 0;
}
