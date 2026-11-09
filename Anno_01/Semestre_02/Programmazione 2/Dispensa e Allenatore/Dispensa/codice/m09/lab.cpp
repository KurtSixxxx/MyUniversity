// Modulo 9 - Laboratorio a step: il rifugio per animali (stile esame UNICT)
// Compila: g++ -g lab.cpp -o lab.exe
#include <iostream>
#include <string>
#include <cstdlib>
#include <typeinfo>
#include <exception>
using namespace std;

// ===== STEP 6 =====  Un'eccezione personalizzata che deriva da exception
class EtaNonValida : public exception {
public:
    const char* what() const noexcept override { return "eta' non valida (0-30)"; }
};

// ===== STEP 1 =====  La classe base
// ===== STEP 4 =====  ...che diventa ASTRATTA, con distruttore virtuale
class Animale {
protected:
    string nome;
    int eta;
public:
    Animale(string n, int e) : nome(n), eta(e) {
        if (e < 0 || e > 30) throw EtaNonValida();
    }
    virtual ~Animale() {}
    virtual string verso() const = 0;               // STEP 3: virtual; STEP 4: = 0
    virtual void stampa() const {
        cout << nome << " (" << eta << " anni) fa " << verso();
    }
    int getEta() const { return eta; }
};

// ===== STEP 2 =====  Classi derivate: estensione (nuovi attributi) e ridefinizione
class Cane : public Animale {
    string razza;
public:
    Cane(string n, int e, string r) : Animale(n, e), razza(r) {}
    string verso() const override { return "Bau"; }
    void stampa() const override {
        Animale::stampa();                          // riuso la stampa della base
        cout << ", razza " << razza;
    }
    void riporta() const { cout << nome << " riporta la pallina!" << endl; }   // solo i cani
};

class Gatto : public Animale {
    bool casalingo;
public:
    Gatto(string n, int e, bool c) : Animale(n, e), casalingo(c) {}
    string verso() const override { return "Miao"; }
    void stampa() const override {
        Animale::stampa();
        cout << (casalingo ? ", casalingo" : ", esce di casa");
    }
};

class Pappagallo : public Animale {
    string parola;
public:
    Pappagallo(string n, int e, string p) : Animale(n, e), parola(p) {}
    string verso() const override { return parola + "!"; }
};

// ===== STEP 5 =====  Generazione casuale e statistiche
Animale* creaCasuale(int i) {
    string nomiCani[] = {"Fido", "Rex", "Argo"};
    string nomiGatti[] = {"Micia", "Tom", "Luna"};
    int eta = rand() % 16;
    int tipo = rand() % 3;
    string suffisso = to_string(i);                 // per distinguere omonimi
    switch (tipo) {
        case 0:  return new Cane(nomiCani[rand() % 3] + suffisso, eta, (rand() % 2) ? "meticcio" : "labrador");
        case 1:  return new Gatto(nomiGatti[rand() % 3] + suffisso, eta, rand() % 2);
        default: return new Pappagallo("Polly" + suffisso, eta, "Ciao");
    }
}

int main() {
    srand(111222333);
    const int N = 10;
    Animale* rifugio[N];
    for (int i = 0; i < N; i++) rifugio[i] = creaCasuale(i);

    cout << "=== Ospiti del rifugio ===" << endl;
    for (int i = 0; i < N; i++) {
        rifugio[i]->stampa();                       // dinamico: la stampa giusta per ogni animale
        cout << endl;
    }

    // Conteggio per tipo: due modi
    int cani = 0, gatti = 0, altri = 0;
    double sommaEtaGatti = 0;
    for (int i = 0; i < N; i++) {
        if (typeid(*rifugio[i]) == typeid(Cane)) cani++;                    // modo 1: typeid
        Gatto* g = dynamic_cast<Gatto*>(rifugio[i]);                         // modo 2: dynamic_cast
        if (g != nullptr) { gatti++; sommaEtaGatti += g->getEta(); }
        if (typeid(*rifugio[i]) == typeid(Pappagallo)) altri++;
    }
    cout << "\nCani: " << cani << ", gatti: " << gatti << ", pappagalli: " << altri << endl;
    if (gatti > 0) cout << "Eta' media dei gatti: " << sommaEtaGatti / gatti << endl;

    cout << "\nI cani giocano:" << endl;
    for (int i = 0; i < N; i++) {
        Cane* c = dynamic_cast<Cane*>(rifugio[i]);  // è davvero un Cane? Se no -> nullptr
        if (c) c->riporta();                        // metodo che esiste solo in Cane
    }

    // STEP 6: un'eccezione dal costruttore
    try {
        Animale* sbagliato = new Gatto("Matusalemme", 99, true);
        delete sbagliato;
    } catch (const EtaNonValida& e) {               // prima la più specifica...
        cout << "\nErrore specifico: " << e.what() << endl;
    } catch (const exception& e) {                  // ...poi la più generale
        cout << "Errore generico: " << e.what() << endl;
    }

    for (int i = 0; i < N; i++) delete rifugio[i];
    return 0;
}
