// Esercizio 11.5 - Lista ordinata senza duplicati (classe template)
#include <iostream>
using namespace std;

template <typename T>
class ListaOrdinata {
    struct Nodo { T valore; Nodo* succ; };      // il nodo è un dettaglio interno della classe
    Nodo* testa = nullptr;
public:
    ~ListaOrdinata() { while (testa) { Nodo* t = testa->succ; delete testa; testa = t; } }

    bool inserisci(const T& v) {                 // false se c'era già
        Nodo* ant = nullptr;
        Nodo* pos = testa;
        while (pos != nullptr && pos->valore < v) { ant = pos; pos = pos->succ; }
        if (pos != nullptr && pos->valore == v) return false;     // duplicato
        Nodo* nuovo = new Nodo{v, pos};
        if (ant == nullptr) testa = nuovo; else ant->succ = nuovo;
        return true;
    }
    bool rimuovi(const T& v) {
        Nodo* ant = nullptr;
        Nodo* pos = testa;
        while (pos != nullptr && pos->valore < v) { ant = pos; pos = pos->succ; }
        if (pos == nullptr || !(pos->valore == v)) return false;  // essendo ordinata, mi fermo prima
        if (ant == nullptr) testa = pos->succ; else ant->succ = pos->succ;
        delete pos;
        return true;
    }
    friend ostream& operator<<(ostream& os, const ListaOrdinata& l) {
        for (Nodo* p = l.testa; p; p = p->succ) os << p->valore << " ";
        return os;
    }
};

int main() {
    ListaOrdinata<int> l;
    int dati[] = {42, 7, 19, 7, 3, 42, 25};
    for (int i = 0; i < 7; i++)
        if (!l.inserisci(dati[i])) cout << dati[i] << " gia' presente" << endl;
    cout << "lista: " << l << endl;
    l.rimuovi(3); l.rimuovi(42); l.rimuovi(20);
    cout << "dopo aver tolto 3, 42 e 20: " << l << endl;
    return 0;
}
