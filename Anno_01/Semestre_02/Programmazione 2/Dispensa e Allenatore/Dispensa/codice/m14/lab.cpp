// Modulo 14 - Laboratorio a step: "Rete di amicizie e piano di studi"
// Compila: g++ -g lab.cpp -o lab.exe
#include <iostream>
#include <string>
using namespace std;

// Coda generica su nodi dinamici (Modulo 12): serve alla BFS dello step 3
template <typename T>
class Coda {
    struct Nodo { T valore; Nodo* succ; };
    Nodo* testa = nullptr;
    Nodo* fondo = nullptr;
public:
    ~Coda() { while (!vuota()) dequeue(); }
    void enqueue(const T& x) {
        Nodo* nuovo = new Nodo{x, nullptr};
        if (vuota()) testa = nuovo; else fondo->succ = nuovo;
        fondo = nuovo;
    }
    T dequeue() {
        Nodo* vecchio = testa;
        T x = vecchio->valore;
        testa = testa->succ;
        if (testa == nullptr) fondo = nullptr;
        delete vecchio;
        return x;
    }
    bool vuota() const { return testa == nullptr; }
};

// ===== STEP 1 =====  Grafo<T> con liste di adiacenza, orientato o no
template <typename T>
class Grafo {
    struct Arco { int dest; Arco* succ; };
    T* chiavi;
    Arco** adj;
    int maxV, nV = 0;
    bool orientato;
    bool* visitato;         // usato dalle visite (step 3, 5, 6)
    int* dist;              // step 3: distanza dalla sorgente
    int* pred;              // step 4: predecessore nel cammino minimo

public:
    Grafo(int max, bool orient) : maxV(max), orientato(orient) {
        chiavi = new T[maxV];
        adj = new Arco*[maxV];
        for (int i = 0; i < maxV; i++) adj[i] = nullptr;
        visitato = new bool[maxV];
        dist = new int[maxV];
        pred = new int[maxV];
    }
    ~Grafo() {
        for (int i = 0; i < maxV; i++)
            while (adj[i] != nullptr) { Arco* s = adj[i]->succ; delete adj[i]; adj[i] = s; }
        delete[] adj; delete[] chiavi; delete[] visitato; delete[] dist; delete[] pred;
    }
    Grafo(const Grafo&) = delete;
    Grafo& operator=(const Grafo&) = delete;

    int indice(const T& k) const {
        for (int i = 0; i < nV; i++) if (chiavi[i] == k) return i;
        return -1;
    }
    bool aggiungiVertice(const T& k) {
        if (nV == maxV || indice(k) != -1) return false;
        chiavi[nV++] = k;
        return true;
    }
    bool aggiungiArco(const T& a, const T& b) {
        int u = indice(a), v = indice(b);
        if (u == -1 || v == -1) return false;
        adj[u] = new Arco{v, adj[u]};                    // inserimento in TESTA: O(1)
        if (!orientato) adj[v] = new Arco{u, adj[v]};
        return true;
    }
    void stampa() const {
        for (int u = 0; u < nV; u++) {
            cout << "  " << chiavi[u] << ":";
            for (Arco* a = adj[u]; a; a = a->succ) cout << " " << chiavi[a->dest];
            cout << endl;
        }
    }

    // ===== STEP 2 =====  grado di un vertice (= lunghezza della sua lista) e grado massimo
    int grado(const T& k) const {
        int u = indice(k), n = 0;
        if (u == -1) return -1;
        for (Arco* a = adj[u]; a; a = a->succ) n++;
        return n;
    }
    T gradoMassimo() const {                             // chiamata su grafo non vuoto
        int migliore = 0;
        for (int u = 1; u < nV; u++)
            if (grado(chiavi[u]) > grado(chiavi[migliore])) migliore = u;
        return chiavi[migliore];
    }

    // ===== STEP 3 =====  BFS: distanza (numero minimo di archi) da una sorgente
    void BFS(const T& sorgente) {
        int s = indice(sorgente);
        for (int u = 0; u < nV; u++) { visitato[u] = false; dist[u] = -1; pred[u] = -1; }
        if (s == -1) return;
        Coda<int> q;
        visitato[s] = true; dist[s] = 0;
        q.enqueue(s);
        while (!q.vuota()) {
            int u = q.dequeue();
            for (Arco* a = adj[u]; a; a = a->succ)
                if (!visitato[a->dest]) {
                    visitato[a->dest] = true;            // marcato QUANDO entra in coda
                    dist[a->dest] = dist[u] + 1;
                    pred[a->dest] = u;
                    q.enqueue(a->dest);
                }
        }
    }
    int distanza(const T& da, const T& a) {
        BFS(da);
        int v = indice(a);
        return v == -1 ? -1 : dist[v];
    }

    // ===== STEP 4 =====  cammino minimo: si risale con pred[], si stampa con la ricorsione
private:
    void stampaCammino(int s, int v) const {
        if (v == s) { cout << chiavi[s]; return; }
        stampaCammino(s, pred[v]);                       // prima il pezzo da s a pred[v]...
        cout << " -> " << chiavi[v];                     // ...poi v
    }
public:
    void cammino(const T& da, const T& a) {
        BFS(da);
        int s = indice(da), v = indice(a);
        cout << "  " << da << " ~> " << a << ": ";
        if (s == -1 || v == -1 || dist[v] == -1) cout << "nessuna catena";
        else { stampaCammino(s, v); cout << "  (" << dist[v] << " passaggi)"; }
        cout << endl;
    }

    // ===== STEP 5 =====  componenti connesse con la DFS ricorsiva
private:
    void dfs(int u) {
        visitato[u] = true;
        cout << " " << chiavi[u];
        for (Arco* a = adj[u]; a; a = a->succ)
            if (!visitato[a->dest]) dfs(a->dest);
    }
public:
    int componenti() {
        for (int u = 0; u < nV; u++) visitato[u] = false;
        int n = 0;
        for (int u = 0; u < nV; u++)
            if (!visitato[u]) {                          // un vertice non ancora raggiunto:
                n++;                                     // inizia una nuova componente
                cout << "  gruppo " << n << ":";
                dfs(u);
                cout << endl;
            }
        return n;
    }

    // ===== STEP 6 =====  ordinamento topologico (grafo orientato e aciclico)
private:
    struct Elem { int v; Elem* succ; };
    void dfsTopo(int u, Elem*& lista) {
        visitato[u] = true;
        for (Arco* a = adj[u]; a; a = a->succ)
            if (!visitato[a->dest]) dfsTopo(a->dest, lista);
        lista = new Elem{u, lista};                      // u è FINITO: lo metto in testa
    }
public:
    void ordinamentoTopologico() {
        for (int u = 0; u < nV; u++) visitato[u] = false;
        Elem* lista = nullptr;
        for (int u = 0; u < nV; u++)
            if (!visitato[u]) dfsTopo(u, lista);
        int k = 1;
        while (lista != nullptr) {                       // stampo e libero la lista
            cout << "  " << k++ << ". " << chiavi[lista->v] << endl;
            Elem* s = lista->succ; delete lista; lista = s;
        }
    }
};

int main() {
    cout << "=== Rete di amicizie (grafo NON orientato) ===" << endl;
    Grafo<string> rete(10, false);
    string nomi[] = {"Anna", "Bruno", "Carla", "Dario", "Elena", "Fabio", "Giulia", "Ivan"};
    for (int i = 0; i < 8; i++) rete.aggiungiVertice(nomi[i]);
    string amici[][2] = {{"Anna","Bruno"}, {"Anna","Carla"}, {"Bruno","Dario"}, {"Carla","Dario"},
                         {"Dario","Elena"}, {"Elena","Fabio"}, {"Giulia","Ivan"}};
    for (int i = 0; i < 7; i++) rete.aggiungiArco(amici[i][0], amici[i][1]);
    if (!rete.aggiungiArco("Anna", "Zeno")) cout << "Zeno non esiste: arco rifiutato" << endl;
    rete.stampa();

    cout << "Amici di Dario: " << rete.grado("Dario") << endl;
    cout << "Il piu' popolare: " << rete.gradoMassimo() << endl;

    cout << "Distanza Anna-Fabio: " << rete.distanza("Anna", "Fabio") << endl;
    cout << "Distanza Anna-Ivan: " << rete.distanza("Anna", "Ivan") << endl;

    cout << "Catene di amicizia:" << endl;
    rete.cammino("Anna", "Fabio");
    rete.cammino("Bruno", "Carla");
    rete.cammino("Anna", "Giulia");

    cout << "Gruppi:" << endl;
    int g = rete.componenti();          // prima la chiamata (che stampa), poi il risultato
    cout << "Numero di gruppi: " << g << endl;

    cout << endl << "=== Esami propedeutici (grafo ORIENTATO) ===" << endl;
    Grafo<string> esami(10, true);
    string e[] = {"Analisi 2", "Fisica", "Algoritmi", "Basi di Dati",
                  "Programmazione 2", "Analisi 1", "Matematica Discreta", "Programmazione 1"};
    for (int i = 0; i < 8; i++) esami.aggiungiVertice(e[i]);
    string prima[][2] = {{"Programmazione 1","Programmazione 2"}, {"Programmazione 2","Algoritmi"},
                         {"Programmazione 2","Basi di Dati"}, {"Matematica Discreta","Algoritmi"},
                         {"Analisi 1","Analisi 2"}, {"Analisi 1","Fisica"}};
    for (int i = 0; i < 6; i++) esami.aggiungiArco(prima[i][0], prima[i][1]);
    esami.stampa();
    cout << "Un ordine valido per sostenerli:" << endl;
    esami.ordinamentoTopologico();
    return 0;
}
