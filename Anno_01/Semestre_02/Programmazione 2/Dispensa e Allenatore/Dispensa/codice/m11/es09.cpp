// Esercizio 11.9 - Lista circolare: il problema di Giuseppe (Josephus)
#include <iostream>
using namespace std;

struct Nodo { int valore; Nodo* succ; };

// n persone in cerchio; si conta fino a k e si elimina chi viene contato; chi resta?
int giuseppe(int n, int k) {
    // costruisco il cerchio 1 -> 2 -> ... -> n -> 1
    Nodo* primo = new Nodo{1, nullptr};
    Nodo* ultimo = primo;
    for (int i = 2; i <= n; i++) {
        ultimo->succ = new Nodo{i, nullptr};
        ultimo = ultimo->succ;
    }
    ultimo->succ = primo;                     // chiudo il cerchio: è questa la lista CIRCOLARE

    Nodo* ant = ultimo;                       // il nodo prima di quello corrente
    cout << "eliminati: ";
    while (ant->succ != ant) {                // finché resta più di un nodo
        for (int c = 1; c < k; c++) ant = ant->succ;   // avanzo di k-1
        Nodo* fuori = ant->succ;              // il k-esimo esce
        cout << fuori->valore << " ";
        ant->succ = fuori->succ;
        delete fuori;
    }
    int sopravvissuto = ant->valore;
    delete ant;
    cout << endl;
    return sopravvissuto;
}

int main() {
    int r = giuseppe(7, 3);              // prima la chiamata (che stampa gli eliminati)...
    cout << "sopravvive il " << r << endl;
    r = giuseppe(10, 2);
    cout << "sopravvive il " << r << endl;
    return 0;
}
