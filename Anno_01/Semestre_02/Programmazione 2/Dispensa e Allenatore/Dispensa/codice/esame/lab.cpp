// Simulazione d'esame - Prova di laboratorio: "L'officina"
// Compila: g++ -Wall -Wextra -g lab.cpp -o lab.exe
#include <iostream>
#include <string>
#include <cstdlib>
#include <typeinfo>
#include <exception>
using namespace std;

// ===== STEP 1 =====  gerarchia: base astratta, put virtuale, operator<< unico
class Veicolo {
protected:
    string targa;
    int km;
public:
    Veicolo(string t, int k) : targa(t), km(k) {}
    virtual ~Veicolo() {}                              // distruttore virtuale (Modulo 9)
    virtual double costoTagliando() const = 0;         // virtuale pura: classe astratta
    int getKm() const { return km; }
    virtual ostream& put(ostream& os) const {
        os << typeid(*this).name() << " " << targa << ", " << km << " km";
        return os;
    }
};
ostream& operator<<(ostream& os, const Veicolo& v) { return v.put(os); }

class Auto : public Veicolo {
    int posti;
public:
    Auto(string t, int k, int p) : Veicolo(t, k), posti(p) {}
    double costoTagliando() const { return 100 + km * 0.002 + (posti > 5 ? 30 : 0); }
    ostream& put(ostream& os) const {
        Veicolo::put(os);                              // prima la parte comune...
        os << ", " << posti << " posti";               // ...poi la parte specifica
        return os;
    }
};

class Moto : public Veicolo {
    int cilindrata;
public:
    Moto(string t, int k, int c) : Veicolo(t, k), cilindrata(c) {}
    double costoTagliando() const { return 60 + cilindrata / 10.0; }
    int getCilindrata() const { return cilindrata; }
    ostream& put(ostream& os) const {
        Veicolo::put(os);
        os << ", " << cilindrata << " cc";
        return os;
    }
};

// ===== STEP 2 =====  generazione casuale
int casuale(int a, int b) { return a + rand() % (b - a + 1); }
string targaCasuale() {
    string t;
    for (int i = 0; i < 2; i++) t += char('A' + casuale(0, 25));
    for (int i = 0; i < 3; i++) t += char('0' + casuale(0, 9));
    for (int i = 0; i < 2; i++) t += char('A' + casuale(0, 25));
    return t;
}

// ===== STEP 3 =====  Coda<T> su nodi dinamici con eccezione personalizzata
class CodaVuota : public exception {
public:
    const char* what() const noexcept { return "coda vuota: nessun veicolo in attesa"; }
};

template <typename T>
class Coda {
    struct Nodo { T valore; Nodo* succ; };
    Nodo* testa = nullptr;
    Nodo* fondo = nullptr;
    int n = 0;
public:
    Coda() {}
    ~Coda() { while (testa) { Nodo* s = testa->succ; delete testa; testa = s; } }
    Coda(const Coda&) = delete;
    Coda& operator=(const Coda&) = delete;
    void enqueue(const T& x) {
        Nodo* nuovo = new Nodo{x, nullptr};
        if (testa == nullptr) testa = nuovo; else fondo->succ = nuovo;
        fondo = nuovo;
        n++;
    }
    T dequeue() {
        if (testa == nullptr) throw CodaVuota();
        Nodo* vecchio = testa;
        T x = vecchio->valore;
        testa = testa->succ;
        if (testa == nullptr) fondo = nullptr;
        delete vecchio;
        n--;
        return x;
    }
    bool vuota() const { return testa == nullptr; }
    int size() const { return n; }
};

// ===== STEP 4 =====  BST<K, V> ordinato per chiave, con visita in-order e massimo
template <typename K, typename V>
class BST {
    struct Nodo {
        K chiave; V valore;
        Nodo* sx = nullptr; Nodo* dx = nullptr;
        Nodo(K k, V v) : chiave(k), valore(v) {}
    };
    Nodo* root = nullptr;
    Nodo* insert(Nodo* p, K k, V v) {
        if (p == nullptr) return new Nodo(k, v);
        if (k < p->chiave) p->sx = insert(p->sx, k, v);
        else p->dx = insert(p->dx, k, v);
        return p;
    }
    void inOrder(Nodo* p) const {
        if (!p) return;
        inOrder(p->sx);
        cout << "  " << p->chiave << " euro: " << *p->valore << endl;
        inOrder(p->dx);
    }
    void distruggi(Nodo* p) { if (p) { distruggi(p->sx); distruggi(p->dx); delete p; } }
public:
    BST() {}
    ~BST() { distruggi(root); }
    BST(const BST&) = delete;
    BST& operator=(const BST&) = delete;
    void insert(K k, V v) { root = insert(root, k, v); }
    void stampa() const { inOrder(root); }
    V massimo() const {                               // il nodo più a destra
        if (!root) throw CodaVuota();                 // (riuso l'eccezione per semplicità)
        Nodo* p = root;
        while (p->dx) p = p->dx;
        return p->valore;
    }
};

int main() {
    srand(424242);
    const int N = 10;

    // STEP 2: array di puntatori alla base, riempito a caso
    Veicolo* v[N];
    // ATTENZIONE: su Windows RAND_MAX vale 32767, quindi casuale(0, 150000) non supererebbe
    // mai 32767. Per numeri grandi si compongono migliaia + unità.
    for (int i = 0; i < N; i++) {
        int km = casuale(0, 149) * 1000 + casuale(0, 999);
        if (casuale(0, 1) == 0) v[i] = new Auto(targaCasuale(), km, casuale(2, 7));
        else v[i] = new Moto(targaCasuale(), km / 2, 125 * casuale(1, 8));
    }
    cout << "--- Veicoli generati ---" << endl;
    for (int i = 0; i < N; i++) cout << i << ") " << *v[i] << endl;

    // STEP 3: arrivano in officina in ordine e vengono serviti in ordine (FIFO)
    Coda<Veicolo*> attesa;
    for (int i = 0; i < N; i++) attesa.enqueue(v[i]);
    double incasso = 0;
    cout << "--- Servizio (" << attesa.size() << " in attesa) ---" << endl;
    try {
        for (int i = 0; i <= N; i++) {                // UNO in più: provoca l'eccezione
            Veicolo* x = attesa.dequeue();
            incasso += x->costoTagliando();
        }
    } catch (const CodaVuota& e) {
        cout << "Eccezione: " << e.what() << endl;
    }
    cout << "Incasso totale: " << incasso << " euro" << endl;

    // STEP 4: BST ordinato per costo del tagliando
    BST<double, Veicolo*> perCosto;
    for (int i = 0; i < N; i++) perCosto.insert(v[i]->costoTagliando(), v[i]);
    cout << "--- Per costo crescente ---" << endl;
    perCosto.stampa();
    cout << "Tagliando piu' caro: " << *perCosto.massimo() << endl;

    // STEP 5: statistiche con dynamic_cast e typeid
    int nAuto = 0, motoGrandi = 0;
    long kmAuto = 0;
    for (int i = 0; i < N; i++) {
        if (typeid(*v[i]) == typeid(Auto)) { nAuto++; kmAuto += v[i]->getKm(); }
        Moto* m = dynamic_cast<Moto*>(v[i]);          // nullptr se v[i] non è una Moto
        if (m != nullptr && m->getCilindrata() >= 500) motoGrandi++;
    }
    cout << "Auto: " << nAuto << ", km medi " << (nAuto ? kmAuto / nAuto : 0) << endl;
    cout << "Moto da almeno 500 cc: " << motoGrandi << endl;

    // STEP 6: memoria. Coda e BST liberano i LORO nodi; i veicoli li ha creati il main
    for (int i = 0; i < N; i++) delete v[i];
    return 0;
}
