// Esercizio 12.7 - Pila che conosce il suo minimo in O(1)
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class PilaConMinimo {
    struct Nodo { T valore; T minimoFinoQui; Nodo* succ; };   // ogni nodo ricorda il minimo "sotto di sé"
    Nodo* cima = nullptr;
public:
    ~PilaConMinimo() { while (!vuota()) pop(); }
    void push(const T& x) {
        T m = (vuota() || x < cima->minimoFinoQui) ? x : cima->minimoFinoQui;
        cima = new Nodo{x, m, cima};
    }
    T pop() {
        if (vuota()) throw underflow_error("pila vuota");
        Nodo* v = cima; T x = v->valore; cima = cima->succ; delete v; return x;
    }
    T minimo() const {
        if (vuota()) throw underflow_error("pila vuota");
        return cima->minimoFinoQui;                  // nessun ciclo: O(1)
    }
    bool vuota() const { return cima == nullptr; }
};

int main() {
    PilaConMinimo<int> p;
    int dati[] = {5, 7, 3, 8, 1, 9};
    for (int i = 0; i < 6; i++) { p.push(dati[i]); cout << "push " << dati[i] << " -> minimo " << p.minimo() << endl; }
    while (!p.vuota()) {
        cout << "minimo " << p.minimo() << ", pop " << p.pop() << endl;
    }
    return 0;
}
