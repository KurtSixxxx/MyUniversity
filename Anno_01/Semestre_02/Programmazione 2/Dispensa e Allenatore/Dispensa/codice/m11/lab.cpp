// Modulo 11 - Laboratorio a step: rettangoli in una lista (esercizio delle slide)
// Compila: g++ -g lab.cpp -o lab.exe
#include <iostream>
using namespace std;

// ===== STEP 1 =====  Nodo e lista generica con inserimento in testa, stampa, distruttore
template <typename T>
struct Nodo {
    T valore;
    Nodo<T>* succ;
    Nodo(const T& v, Nodo<T>* s = nullptr) : valore(v), succ(s) {}
};

template <typename T>
class Lista {
    Nodo<T>* testa;
    Nodo<T>* coda;                       // ===== STEP 2 ===== puntatore all'ultimo: coda in O(1)
    int n;
public:
    Lista() : testa(nullptr), coda(nullptr), n(0) {}
    ~Lista() { svuota(); }
    Lista(const Lista&) = delete;        // in questo laboratorio non serve copiare: lo VIETO
    Lista& operator=(const Lista&) = delete;

    void svuota() {
        while (testa) { Nodo<T>* t = testa; testa = testa->succ; delete t; }
        coda = nullptr;
        n = 0;
    }
    void inserisciTesta(const T& v) {
        testa = new Nodo<T>(v, testa);
        if (coda == nullptr) coda = testa;          // era vuota: il nuovo è anche l'ultimo
        n++;
    }
    // ===== STEP 2 =====
    void inserisciCoda(const T& v) {
        Nodo<T>* nuovo = new Nodo<T>(v);
        if (coda == nullptr) testa = coda = nuovo;
        else { coda->succ = nuovo; coda = nuovo; }
        n++;
    }
    int size() const { return n; }

    // ===== STEP 3 =====  Rimuove TUTTI i nodi per cui "condizione" è vera
    int rimuoviSe(bool (*condizione)(const T&, double, double), double a, double b) {
        int tolti = 0;
        Nodo<T>* ant = nullptr;
        Nodo<T>* pos = testa;
        while (pos != nullptr) {
            if (condizione(pos->valore, a, b)) {
                Nodo<T>* daTogliere = pos;
                pos = pos->succ;                       // avanzo PRIMA di cancellare
                if (ant == nullptr) testa = pos; else ant->succ = pos;
                if (daTogliere == coda) coda = ant;    // ho tolto l'ultimo
                delete daTogliere;
                n--; tolti++;
            } else {
                ant = pos;
                pos = pos->succ;
            }
        }
        return tolti;
    }

    // ===== STEP 5 =====  Inserimento ordinato
    void inserisciOrdinato(const T& v) {
        if (testa == nullptr || v < testa->valore) { inserisciTesta(v); return; }
        Nodo<T>* p = testa;
        while (p->succ != nullptr && p->succ->valore < v) p = p->succ;
        p->succ = new Nodo<T>(v, p->succ);
        if (p == coda) coda = p->succ;
        n++;
    }

    // ===== STEP 6 =====  Inversione in loco: la testa diventa la coda
    void inverti() {
        Nodo<T>* prec = nullptr;
        Nodo<T>* corr = testa;
        coda = testa;
        while (corr) {
            Nodo<T>* s = corr->succ;
            corr->succ = prec;
            prec = corr;
            corr = s;
        }
        testa = prec;
    }

    friend ostream& operator<<(ostream& os, const Lista& l) {
        if (l.testa == nullptr) return os << "(lista vuota)";
        for (Nodo<T>* p = l.testa; p; p = p->succ) os << p->valore << (p->succ ? "  " : "");
        return os;
    }
};

// ===== STEP 4 =====  La classe Rettangolo e il "gestore" con metodi statici
class Rettangolo {
    double b, h;
public:
    Rettangolo(double base = 1, double altezza = 1) : b(base), h(altezza) {}
    double area() const { return b * h; }
    bool operator<(const Rettangolo& r) const { return area() < r.area(); }    // per lo STEP 5
    friend ostream& operator<<(ostream& os, const Rettangolo& r) {
        return os << r.b << "x" << r.h << "(" << r.area() << ")";
    }
};

class Gestore {
public:
    // Legge "quanti" e poi le coppie base altezza; li mette in coda
    static void leggi(Lista<Rettangolo>& l) {
        int quanti;
        cin >> quanti;
        for (int i = 0; i < quanti; i++) {
            double b, h;
            cin >> b >> h;
            l.inserisciCoda(Rettangolo(b, h));
        }
    }
    static bool areaTra(const Rettangolo& r, double a, double b) {
        return r.area() >= a && r.area() <= b;
    }
    // Elimina tutti i rettangoli con area in [a, b]
    static int eliminaTra(Lista<Rettangolo>& l, double a, double b) {
        return l.rimuoviSe(areaTra, a, b);
    }
};

int main() {
    Lista<int> numeri;                                   // STEP 1-2 con gli interi
    numeri.inserisciTesta(2); numeri.inserisciTesta(1); numeri.inserisciCoda(3);
    cout << "STEP 1-2: " << numeri << endl;

    Lista<Rettangolo> rett;                              // STEP 4
    Gestore::leggi(rett);
    cout << "STEP 4: letti " << rett.size() << ": " << rett << endl;
    int tolti = Gestore::eliminaTra(rett, 10, 30);       // STEP 3 usato dallo STEP 4
    cout << "        tolti " << tolti << " con area in [10, 30]: " << rett << endl;

    Lista<Rettangolo> ordinati;                          // STEP 5
    Rettangolo prove[] = {Rettangolo(3, 3), Rettangolo(1, 2), Rettangolo(5, 1), Rettangolo(2, 2)};
    for (int i = 0; i < 4; i++) ordinati.inserisciOrdinato(prove[i]);
    cout << "STEP 5: ordinati per area: " << ordinati << endl;

    ordinati.inverti();                                  // STEP 6
    ordinati.inserisciCoda(Rettangolo(0.5, 1));          // la coda è aggiornata correttamente?
    cout << "STEP 6: invertiti (+ uno in coda): " << ordinati << endl;
    return 0;
}
