// Modulo 14 - Pattern: grafo con MATRICE e con LISTE di adiacenza, visite BFS e DFS
// Compila: g++ -g pattern.cpp -o pattern.exe
#include <iostream>
using namespace std;

// ---------- Coda di interi su nodi dinamici (Modulo 12), serve alla BFS ----------
class Coda {
    struct Nodo { int valore; Nodo* succ; };
    Nodo* testa = nullptr;
    Nodo* fondo = nullptr;
public:
    ~Coda() { while (!vuota()) dequeue(); }
    void enqueue(int x) {
        Nodo* nuovo = new Nodo{x, nullptr};
        if (vuota()) testa = nuovo; else fondo->succ = nuovo;
        fondo = nuovo;
    }
    int dequeue() {                       // chiamata solo su coda non vuota
        Nodo* vecchio = testa;
        int x = vecchio->valore;
        testa = testa->succ;
        if (testa == nullptr) fondo = nullptr;
        delete vecchio;
        return x;
    }
    bool vuota() const { return testa == nullptr; }
};

// ========== 1. GRAFO CON MATRICE DI ADIACENZA (come il codice del prof) ==========
template <typename T>
class GrafoMatrice {
    T* chiavi;          // chiavi[i] = etichetta del vertice di indice i
    bool** adj;         // adj[i][j] == true  <=>  c'è l'arco (i, j)
    int maxV, nV = 0;
    bool orientato;
public:
    GrafoMatrice(int max, bool orient = false) : maxV(max), orientato(orient) {
        chiavi = new T[maxV];
        adj = new bool*[maxV];                       // array di righe...
        for (int i = 0; i < maxV; i++)
            adj[i] = new bool[maxV]{};               // ...ogni riga tutta a false
    }
    ~GrafoMatrice() {
        for (int i = 0; i < maxV; i++) delete[] adj[i];
        delete[] adj;
        delete[] chiavi;
    }
    GrafoMatrice(const GrafoMatrice&) = delete;
    GrafoMatrice& operator=(const GrafoMatrice&) = delete;

    int indice(T k) const {                          // dalla chiave all'indice: O(V)
        for (int i = 0; i < nV; i++) if (chiavi[i] == k) return i;
        return -1;
    }
    void aggiungiVertice(T k) { if (nV < maxV && indice(k) == -1) chiavi[nV++] = k; }
    void aggiungiArco(T a, T b) {
        int i = indice(a), j = indice(b);
        if (i == -1 || j == -1) { cout << "vertice inesistente" << endl; return; }
        adj[i][j] = true;
        if (!orientato) adj[j][i] = true;            // non orientato: simmetrica
    }
    bool adiacenti(T a, T b) const {                 // O(1): basta leggere una cella
        int i = indice(a), j = indice(b);
        return i != -1 && j != -1 && adj[i][j];
    }
    void stampa() const {
        cout << "  ";
        for (int j = 0; j < nV; j++) cout << chiavi[j] << " ";
        cout << endl;
        for (int i = 0; i < nV; i++) {
            cout << chiavi[i] << " ";
            for (int j = 0; j < nV; j++) cout << adj[i][j] << " ";
            cout << endl;
        }
    }
};

// ================= 2. GRAFO CON LISTE DI ADIACENZA + BFS e DFS =================
struct Arco {           // un elemento della lista di adiacenza
    int dest;           // indice del vertice di arrivo
    Arco* succ;
};

template <typename T>
class Grafo {
    enum Colore { BIANCO, GRIGIO, NERO };
    T* chiavi;
    Arco** adj;         // adj[u] = testa della lista dei vicini di u
    int maxV, nV = 0;
    bool orientato;
    // risultati delle visite (uno per vertice)
    Colore* colore;
    int* d;             // BFS: distanza dalla sorgente / DFS: tempo di scoperta
    int* f;             // DFS: tempo di fine
    int* pred;          // predecessore (-1 = nessuno)
    int tempo;

    void aggiungiInCoda(int u, int v) {              // aggiunge v in FONDO alla lista di u
        Arco* nuovo = new Arco{v, nullptr};
        if (adj[u] == nullptr) { adj[u] = nuovo; return; }
        Arco* p = adj[u];
        while (p->succ != nullptr) p = p->succ;
        p->succ = nuovo;
    }
    void dfsVisit(int u) {                           // DFS-Visit(u) delle slide
        colore[u] = GRIGIO;
        d[u] = tempo++;                              // scoperto
        cout << chiavi[u] << " ";
        for (Arco* a = adj[u]; a != nullptr; a = a->succ) {
            int v = a->dest;
            if (colore[v] == BIANCO) {
                pred[v] = u;
                dfsVisit(v);                         // scendo in profondità
            }
        }
        colore[u] = NERO;
        f[u] = tempo++;                              // finito: torno indietro (backtracking)
    }
    void stampaCammino(int s, int v) const {         // Print-Path delle slide (ricorsiva)
        if (v == s) cout << chiavi[s];
        else if (pred[v] == -1) cout << "nessun cammino";
        else { stampaCammino(s, pred[v]); cout << " -> " << chiavi[v]; }
    }

public:
    Grafo(int max, bool orient = false) : maxV(max), orientato(orient) {
        chiavi = new T[maxV];
        adj = new Arco*[maxV];
        for (int i = 0; i < maxV; i++) adj[i] = nullptr;   // tutte le liste vuote
        colore = new Colore[maxV];
        d = new int[maxV]; f = new int[maxV]; pred = new int[maxV];
    }
    ~Grafo() {
        for (int i = 0; i < maxV; i++) {             // prima ogni lista, nodo per nodo
            Arco* p = adj[i];
            while (p != nullptr) { Arco* s = p->succ; delete p; p = s; }
        }
        delete[] adj; delete[] chiavi;
        delete[] colore; delete[] d; delete[] f; delete[] pred;
    }
    Grafo(const Grafo&) = delete;
    Grafo& operator=(const Grafo&) = delete;

    int indice(T k) const {
        for (int i = 0; i < nV; i++) if (chiavi[i] == k) return i;
        return -1;
    }
    void aggiungiVertice(T k) { if (nV < maxV && indice(k) == -1) chiavi[nV++] = k; }
    void aggiungiArco(T a, T b) {
        int u = indice(a), v = indice(b);
        if (u == -1 || v == -1) { cout << "vertice inesistente" << endl; return; }
        aggiungiInCoda(u, v);
        if (!orientato) aggiungiInCoda(v, u);        // non orientato: l'arco va in ENTRAMBE le liste
    }
    void stampa() const {
        for (int u = 0; u < nV; u++) {
            cout << chiavi[u] << ":";
            for (Arco* a = adj[u]; a != nullptr; a = a->succ) cout << " " << chiavi[a->dest];
            cout << endl;
        }
    }

    // ---------- BFS(G, s): visita in AMPIEZZA, calcola le distanze minime da s ----------
    void BFS(T sorgente) {
        int s = indice(sorgente);
        if (s == -1) return;
        for (int u = 0; u < nV; u++) { colore[u] = BIANCO; d[u] = -1; pred[u] = -1; }  // -1 = infinito
        colore[s] = GRIGIO; d[s] = 0;
        Coda q;
        q.enqueue(s);
        cout << "BFS da " << sorgente << ": ";
        while (!q.vuota()) {
            int u = q.dequeue();
            cout << chiavi[u] << " ";
            for (Arco* a = adj[u]; a != nullptr; a = a->succ) {
                int v = a->dest;
                if (colore[v] == BIANCO) {           // scoperto adesso
                    colore[v] = GRIGIO;
                    d[v] = d[u] + 1;
                    pred[v] = u;
                    q.enqueue(v);
                }
            }
            colore[u] = NERO;                        // ho esaminato tutti i suoi vicini
        }
        cout << endl;
        for (int v = 0; v < nV; v++) {
            cout << "  " << chiavi[v] << ": distanza " << d[v] << ", cammino ";
            stampaCammino(s, v);
            cout << endl;
        }
    }

    // ---------- DFS(G): visita in PROFONDITÀ di tutto il grafo, con i tempi d/f ----------
    void DFS() {
        for (int u = 0; u < nV; u++) { colore[u] = BIANCO; pred[u] = -1; }
        tempo = 0;
        cout << "DFS: ";
        for (int u = 0; u < nV; u++)                 // riparte da ogni vertice rimasto bianco
            if (colore[u] == BIANCO) dfsVisit(u);
        cout << endl;
        for (int u = 0; u < nV; u++)
            cout << "  " << chiavi[u] << ": d=" << d[u] << " f=" << f[u]
                 << ", pred=" << (pred[u] == -1 ? '-' : chiavi[pred[u]]) << endl;
    }
};

int main() {
    char v[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    char archi[][2] = {{'A','B'}, {'A','C'}, {'B','D'}, {'C','D'}, {'C','E'}, {'D','F'}, {'E','F'}};

    GrafoMatrice<char> gm(6);
    Grafo<char> gl(6);
    for (int i = 0; i < 6; i++) { gm.aggiungiVertice(v[i]); gl.aggiungiVertice(v[i]); }
    for (int i = 0; i < 7; i++) {
        gm.aggiungiArco(archi[i][0], archi[i][1]);
        gl.aggiungiArco(archi[i][0], archi[i][1]);
    }

    cout << "--- Matrice di adiacenza ---" << endl;
    gm.stampa();
    cout << "A e C adiacenti? " << gm.adiacenti('A', 'C') << endl;
    cout << "A e F adiacenti? " << gm.adiacenti('A', 'F') << endl;

    cout << "--- Liste di adiacenza ---" << endl;
    gl.stampa();

    cout << "--- Visite ---" << endl;
    gl.BFS('A');
    gl.DFS();
    return 0;
}
