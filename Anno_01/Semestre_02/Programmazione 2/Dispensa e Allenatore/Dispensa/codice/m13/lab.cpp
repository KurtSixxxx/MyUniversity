// Modulo 13 - Laboratorio a step: "BST Persone" (traccia d'esame delle slide)
// Compila: g++ -g lab.cpp -o lab.exe
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// ===== STEP 1 =====  BST generico chiave -> valore (la chiave decide la posizione)
template <typename K, typename V>
class BST {
    struct Nodo {
        K chiave;
        V valore;
        Nodo* left = nullptr;
        Nodo* right = nullptr;
        Nodo(K k, V v) : chiave(k), valore(v) {}
    };
    Nodo* root = nullptr;

    // ===== STEP 2 =====  inserimento RICORSIVO (alternativa a quello iterativo delle slide)
    Nodo* insert(Nodo* p, K k, V v) {
        if (p == nullptr) return new Nodo(k, v);             // posto vuoto trovato: nasce qui
        if (k < p->chiave) p->left = insert(p->left, k, v);
        else p->right = insert(p->right, k, v);              // chiavi uguali a destra
        return p;
    }
    // ===== STEP 3 =====  visita in-order con una funzione da applicare a ogni nodo
    void inOrder(Nodo* p, void (*visita)(K, V)) const {
        if (!p) return;
        inOrder(p->left, visita);
        visita(p->chiave, p->valore);
        inOrder(p->right, visita);
    }
    int altezza(Nodo* p) const {
        if (!p) return -1;
        int a = altezza(p->left), b = altezza(p->right);
        return 1 + (a > b ? a : b);
    }
    void distruggi(Nodo* p) { if (p) { distruggi(p->left); distruggi(p->right); delete p; } }

public:
    ~BST() { distruggi(root); }
    void insert(K k, V v) { root = insert(root, k, v); }
    void visitaInOrder(void (*visita)(K, V)) const { inOrder(root, visita); }
    int altezza() const { return altezza(root); }
};

// ===== STEP 4 =====  La gerarchia di Persone (Modulo 9)
class Persona {
protected:
    string nome, cognome;
    int eta;
public:
    Persona(string n, string c, int e) : nome(n), cognome(c), eta(e) {}
    virtual ~Persona() {}
    int getEta() const { return eta; }
    virtual string categoria() const = 0;
    void stampa() const { cout << nome << " " << cognome << " (" << eta << ", " << categoria() << ")"; }
};
class Studente : public Persona {
public:
    Studente(string n, string c, int e) : Persona(n, c, e) {}
    string categoria() const override { return "studente"; }
};
class Lavoratore : public Persona {
public:
    Lavoratore(string n, string c, int e) : Persona(n, c, e) {}
    string categoria() const override { return "lavoratore"; }
};
class Pensionato : public Persona {
public:
    Pensionato(string n, string c, int e) : Persona(n, c, e) {}
    string categoria() const override { return "pensionato"; }
};

int casuale(int a, int b) { return a + rand() % (b - a + 1); }   // intero in [a, b]

// ===== STEP 6 =====  Medie per categoria con UNA sola visita: accumulatori globali
double sommaEta[3];
int conta[3];
void accumula(int eta, Persona* p) {
    int k = (dynamic_cast<Studente*>(p)) ? 0 : (dynamic_cast<Lavoratore*>(p)) ? 1 : 2;
    sommaEta[k] += eta;
    conta[k]++;
}
void stampaNodo(int, Persona* p) { cout << "  "; p->stampa(); cout << endl; }

int main() {
    srand(111222333);
    // ===== STEP 5 =====  6 persone con età negli intervalli della traccia
    string nomi[] = {"Ada", "Bea", "Ciro", "Dora", "Ezio", "Fede"};
    string cognomi[] = {"Rossi", "Russo", "Greco", "Bruno", "Gallo", "Costa"};
    Persona* persone[6] = {
        new Studente(nomi[0], cognomi[0], casuale(5, 30)),
        new Studente(nomi[1], cognomi[1], casuale(5, 30)),
        new Lavoratore(nomi[2], cognomi[2], casuale(20, 70)),
        new Lavoratore(nomi[3], cognomi[3], casuale(20, 70)),
        new Pensionato(nomi[4], cognomi[4], casuale(65, 95)),
        new Pensionato(nomi[5], cognomi[5], casuale(65, 95))
    };

    BST<int, Persona*> albero;                     // chiave = età, valore = puntatore alla persona
    for (int i = 0; i < 6; i++) albero.insert(persone[i]->getEta(), persone[i]);

    cout << "Persone in ordine di eta' (visita in-order):" << endl;
    albero.visitaInOrder(stampaNodo);
    cout << "Altezza dell'albero: " << albero.altezza() << endl;

    albero.visitaInOrder(accumula);                // STEP 6: una sola visita
    string cat[] = {"studenti", "lavoratori", "pensionati"};
    for (int k = 0; k < 3; k++)
        cout << "Eta' media " << cat[k] << ": " << (conta[k] ? sommaEta[k] / conta[k] : 0) << endl;

    for (int i = 0; i < 6; i++) delete persone[i]; // il BST contiene solo PUNTATORI: le persone le libero io
    return 0;
}
