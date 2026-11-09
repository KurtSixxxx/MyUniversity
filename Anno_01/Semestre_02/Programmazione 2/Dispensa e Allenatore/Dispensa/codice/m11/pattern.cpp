// Modulo 11 - Pattern: lista concatenata semplice generica (template), senza STL
// Compila: g++ -g pattern.cpp -o pattern.exe
#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Nodo {
    T valore;
    Nodo<T>* succ;                     // indirizzo del nodo successivo (nullptr = fine)
    Nodo(T v, Nodo<T>* s = nullptr) : valore(v), succ(s) {}
};

template <typename T>
class Lista {
private:
    Nodo<T>* testa;                    // unico accesso alla lista
    int n;

public:
    Lista() : testa(nullptr), n(0) {}

    // --- Regola dei Tre: la lista POSSIEDE i suoi nodi ---
    ~Lista() {
        while (testa != nullptr) {     // stacco un nodo alla volta dalla testa
            Nodo<T>* tmp = testa;
            testa = testa->succ;
            delete tmp;
        }
    }
    Lista(const Lista& altra) : testa(nullptr), n(0) {
        for (Nodo<T>* p = altra.testa; p != nullptr; p = p->succ) inserisciCoda(p->valore);
    }
    Lista& operator=(const Lista& altra) {
        if (this != &altra) {
            Lista copia(altra);                       // copio...
            Nodo<T>* t = testa; testa = copia.testa; copia.testa = t;   // ...e scambio le teste:
            int k = n; n = copia.n; copia.n = k;      // il distruttore di copia libera i MIEI vecchi nodi
        }
        return *this;
    }

    bool vuota() const { return testa == nullptr; }
    int size() const { return n; }

    // INSERIMENTO IN TESTA: O(1)
    void inserisciTesta(T v) {
        testa = new Nodo<T>(v, testa);  // il nuovo nodo punta alla vecchia testa, poi diventa la testa
        n++;
    }

    // INSERIMENTO IN CODA: O(n), bisogna arrivare all'ultimo nodo
    void inserisciCoda(T v) {
        Nodo<T>* nuovo = new Nodo<T>(v);
        if (testa == nullptr) { testa = nuovo; n++; return; }   // lista vuota: caso speciale
        Nodo<T>* p = testa;
        while (p->succ != nullptr) p = p->succ;                 // mi fermo SULL'ultimo
        p->succ = nuovo;
        n++;
    }

    // INSERIMENTO ORDINATO (crescente): richiede l'operatore < su T
    void inserisciOrdinato(T v) {
        if (testa == nullptr || v < testa->valore) { inserisciTesta(v); return; }
        Nodo<T>* p = testa;
        while (p->succ != nullptr && p->succ->valore < v) p = p->succ;   // p = ultimo nodo < v
        p->succ = new Nodo<T>(v, p->succ);                              // aggancio DOPO p
        n++;
    }

    // RICERCA: restituisce il puntatore al nodo, o nullptr
    Nodo<T>* ricerca(T v) const {
        for (Nodo<T>* p = testa; p != nullptr; p = p->succ)
            if (p->valore == v) return p;
        return nullptr;
    }

    // RIMOZIONE della prima occorrenza: serve il nodo PRECEDENTE (ant)
    bool rimuovi(T v) {
        Nodo<T>* ant = nullptr;
        Nodo<T>* pos = testa;
        while (pos != nullptr && !(pos->valore == v)) { ant = pos; pos = pos->succ; }
        if (pos == nullptr) return false;              // non trovato
        if (ant == nullptr) testa = pos->succ;         // era il primo: sposto la testa
        else ant->succ = pos->succ;                    // scavalco pos
        delete pos;
        n--;
        return true;
    }

    // INVERSIONE IN LOCO: giro tutte le frecce, senza creare nodi
    void inverti() {
        Nodo<T>* prec = nullptr;
        Nodo<T>* corr = testa;
        while (corr != nullptr) {
            Nodo<T>* succ = corr->succ;   // 1. ricordo il successivo
            corr->succ = prec;            // 2. giro la freccia all'indietro
            prec = corr;                  // 3. avanzo di un passo
            corr = succ;
        }
        testa = prec;                     // l'ultimo nodo è la nuova testa
    }

    // STAMPA: friend definita dentro la classe (la forma più semplice per i template)
    friend ostream& operator<<(ostream& os, const Lista& l) {
        os << "[";
        for (Nodo<T>* p = l.testa; p != nullptr; p = p->succ)
            os << p->valore << (p->succ ? " -> " : "");
        return os << "]";
    }
};

int main() {
    Lista<int> l;
    l.inserisciTesta(3);
    l.inserisciTesta(1);
    l.inserisciCoda(7);
    l.inserisciCoda(9);
    cout << "lista:            " << l << "  (" << l.size() << " nodi)" << endl;
    cout << "ricerca(7):       " << (l.ricerca(7) ? "trovato" : "assente") << endl;
    l.rimuovi(1);  l.rimuovi(9);  l.rimuovi(42);
    cout << "tolti 1, 9, 42:   " << l << endl;
    l.inserisciOrdinato(5);
    cout << "inserito 5:       " << l << endl;
    Lista<int> copia = l;
    l.inverti();
    cout << "invertita:        " << l << ", la copia: " << copia << endl;

    Lista<string> parole;
    parole.inserisciOrdinato("pera");
    parole.inserisciOrdinato("mela");
    parole.inserisciOrdinato("uva");
    parole.inserisciOrdinato("kiwi");
    cout << "parole ordinate:  " << parole << endl;
    return 0;
}
