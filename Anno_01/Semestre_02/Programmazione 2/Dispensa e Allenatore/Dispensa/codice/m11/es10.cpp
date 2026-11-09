// Esercizio 11.10 - Lista doppia circolare con sentinella (dalle slide)
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class ListaSentinella {
    struct Nodo { T valore; Nodo* succ; Nodo* prec; };
    Nodo* s;                                   // la sentinella: non contiene dati utili
    int n;

    void inserisciDopo(Nodo* p, const T& v) {  // UNICA funzione di inserimento: niente casi speciali
        Nodo* nuovo = new Nodo{v, p->succ, p};
        p->succ->prec = nuovo;
        p->succ = nuovo;
        n++;
    }
public:
    ListaSentinella() : s(new Nodo{T(), nullptr, nullptr}), n(0) {
        s->succ = s->prec = s;                 // lista vuota: la sentinella punta a se stessa
    }
    ~ListaSentinella() {
        while (n > 0) rimuoviPrimo();
        delete s;
    }
    void inserisciTesta(const T& v) { inserisciDopo(s, v); }        // O(1)
    void inserisciCoda(const T& v)  { inserisciDopo(s->prec, v); }  // O(1): l'ultimo è s->prec
    bool rimuoviPrimo() {
        if (n == 0) return false;
        Nodo* p = s->succ;
        p->prec->succ = p->succ;               // anche qui nessun caso speciale
        p->succ->prec = p->prec;
        delete p;
        n--;
        return true;
    }
    bool rimuovi(const T& v) {
        for (Nodo* p = s->succ; p != s; p = p->succ)       // il ciclo finisce quando torno alla sentinella
            if (p->valore == v) {
                p->prec->succ = p->succ;
                p->succ->prec = p->prec;
                delete p;
                n--;
                return true;
            }
        return false;
    }
    friend ostream& operator<<(ostream& os, const ListaSentinella& l) {
        os << "[ ";
        for (Nodo* p = l.s->succ; p != l.s; p = p->succ) os << p->valore << " ";
        os << "] al contrario: [ ";
        for (Nodo* p = l.s->prec; p != l.s; p = p->prec) os << p->valore << " ";
        return os << "]";
    }
};

int main() {
    ListaSentinella<string> l;
    cout << l << endl;
    l.inserisciCoda("b"); l.inserisciCoda("c"); l.inserisciTesta("a"); l.inserisciCoda("d");
    cout << l << endl;
    l.rimuovi("c"); l.rimuovi("a"); l.rimuovi("z");
    cout << l << endl;
    return 0;
}
