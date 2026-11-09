// Esercizio 11.7 - Lista doppia (il "TODO" del prof): inserisci(valPrec, val) prima di un nodo
#include <iostream>
using namespace std;

template <typename T>
struct Nodo {
    T valore;
    Nodo<T>* succ;
    Nodo<T>* prec;
};

template <typename T>
class ListaDoppia {
    Nodo<T>* testa = nullptr;
    Nodo<T>* coda = nullptr;           // con la coda posso stampare anche all'indietro
public:
    ~ListaDoppia() { while (testa) { Nodo<T>* t = testa->succ; delete testa; testa = t; } }

    void inserisci(T val) {            // in testa, come nel codice del prof
        Nodo<T>* nuovo = new Nodo<T>{val, testa, nullptr};
        if (testa != nullptr) testa->prec = nuovo;
        else coda = nuovo;
        testa = nuovo;
    }
    Nodo<T>* ricerca(T val) const {
        for (Nodo<T>* p = testa; p; p = p->succ) if (p->valore == val) return p;
        return nullptr;
    }
    // Inserisce val come PRECEDENTE del nodo che contiene valPrec (se esiste)
    bool inserisci(T valPrec, T val) {
        Nodo<T>* pos = ricerca(valPrec);
        if (pos == nullptr) return false;
        Nodo<T>* nuovo = new Nodo<T>{val, pos, pos->prec};   // succ = pos, prec = il vecchio prec
        if (pos->prec != nullptr) pos->prec->succ = nuovo;    // il vecchio precedente punta al nuovo
        else testa = nuovo;                                    // pos era la testa
        pos->prec = nuovo;
        return true;
    }
    bool rimuovi(T val) {              // con i due puntatori non serve cercare il precedente
        Nodo<T>* pos = ricerca(val);
        if (pos == nullptr) return false;
        if (pos->prec) pos->prec->succ = pos->succ; else testa = pos->succ;
        if (pos->succ) pos->succ->prec = pos->prec; else coda = pos->prec;
        delete pos;
        return true;
    }
    void stampaAvanti() const { for (Nodo<T>* p = testa; p; p = p->succ) cout << p->valore << " "; cout << endl; }
    void stampaIndietro() const { for (Nodo<T>* p = coda; p; p = p->prec) cout << p->valore << " "; cout << endl; }
};

int main() {
    ListaDoppia<int> l;
    for (int i = 5; i >= 1; i--) l.inserisci(i * 10);       // 10 20 30 40 50
    l.inserisci(30, 25);                                     // prima di 30
    l.inserisci(10, 5);                                      // prima della testa
    if (!l.inserisci(99, 1)) cout << "99 non c'e'" << endl;
    cout << "avanti:   "; l.stampaAvanti();
    cout << "indietro: "; l.stampaIndietro();
    l.rimuovi(50); l.rimuovi(5); l.rimuovi(30);
    cout << "dopo aver tolto 50, 5 e 30: "; l.stampaAvanti();
    cout << "indietro: "; l.stampaIndietro();
    return 0;
}
