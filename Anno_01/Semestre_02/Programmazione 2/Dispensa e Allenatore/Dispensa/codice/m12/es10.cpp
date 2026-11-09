// Esercizio 12.10 - Coda con priorità: il pronto soccorso
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

struct Paziente {
    string nome;
    int codice;            // 1 = rosso (urgente), 2 = giallo, 3 = verde
};

class ProntoSoccorso {
    struct Nodo { Paziente p; Nodo* succ; };
    Nodo* testa = nullptr;
public:
    ~ProntoSoccorso() { while (testa) { Nodo* t = testa->succ; delete testa; testa = t; } }
    // Inserisco DOPO tutti quelli con codice <= al mio: a parità di codice vale l'ordine di arrivo
    void arriva(const Paziente& p) {
        Nodo* nuovo = new Nodo{p, nullptr};
        if (testa == nullptr || p.codice < testa->p.codice) { nuovo->succ = testa; testa = nuovo; return; }
        Nodo* q = testa;
        while (q->succ != nullptr && q->succ->p.codice <= p.codice) q = q->succ;
        nuovo->succ = q->succ;
        q->succ = nuovo;
    }
    Paziente chiama() {                   // esce sempre la testa: O(1)
        if (testa == nullptr) throw underflow_error("nessun paziente");
        Nodo* v = testa; Paziente p = v->p; testa = testa->succ; delete v; return p;
    }
    bool vuoto() const { return testa == nullptr; }
};

int main() {
    const string colore[] = {"", "ROSSO", "GIALLO", "VERDE"};
    ProntoSoccorso ps;
    Paziente arrivi[] = {{"Anna", 3}, {"Bruno", 2}, {"Carla", 3}, {"Dario", 1}, {"Elena", 2}, {"Franco", 1}};
    for (int i = 0; i < 6; i++) ps.arriva(arrivi[i]);
    int ordine = 1;
    while (!ps.vuoto()) {
        Paziente p = ps.chiama();
        cout << ordine++ << ". " << p.nome << " (" << colore[p.codice] << ")" << endl;
    }
    return 0;
}
