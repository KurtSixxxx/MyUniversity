// Esercizio 11.3 - Massimo di una lista: iterativo e ricorsivo
#include <iostream>
using namespace std;

struct Nodo { int valore; Nodo* succ; };

int massimoIter(Nodo* testa) {                    // la lista non deve essere vuota
    int m = testa->valore;
    for (Nodo* p = testa->succ; p != nullptr; p = p->succ)
        if (p->valore > m) m = p->valore;
    return m;
}

int massimoRic(Nodo* p) {
    if (p->succ == nullptr) return p->valore;     // caso base: un solo nodo
    int mResto = massimoRic(p->succ);             // massimo del resto della lista
    return (p->valore > mResto) ? p->valore : mResto;
}

int main() {
    int dati[] = {7, -2, 15, 4, 15, 0};
    Nodo* l = nullptr;
    for (int i = 5; i >= 0; i--) l = new Nodo{dati[i], l};
    cout << "iterativo: " << massimoIter(l) << ", ricorsivo: " << massimoRic(l) << endl;
    while (l) { Nodo* t = l->succ; delete l; l = t; }
    return 0;
}
