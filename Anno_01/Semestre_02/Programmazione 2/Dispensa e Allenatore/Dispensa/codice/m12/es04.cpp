// Esercizio 12.4 - Da decimale a binario (o a qualunque base) con una pila
#include <iostream>
#include <string>
using namespace std;

template <typename T> struct Nodo { T valore; Nodo<T>* succ; };
template <typename T>
class Pila {
    Nodo<T>* cima = nullptr;
public:
    ~Pila() { while (!vuota()) pop(); }
    void push(const T& x) { cima = new Nodo<T>{x, cima}; }
    T pop() { Nodo<T>* v = cima; T x = v->valore; cima = cima->succ; delete v; return x; }
    bool vuota() const { return cima == nullptr; }
};

// I resti delle divisioni escono al contrario rispetto alle cifre: la pila li rimette in ordine
string converti(int n, int base) {
    if (n == 0) return "0";
    const char cifre[] = "0123456789ABCDEF";
    Pila<char> p;
    while (n > 0) {
        p.push(cifre[n % base]);
        n /= base;
    }
    string r;
    while (!p.vuota()) r += p.pop();
    return r;
}

int main() {
    int numeri[] = {13, 255, 1024, 0};
    for (int i = 0; i < 4; i++)
        cout << numeri[i] << " = " << converti(numeri[i], 2) << " (bin) = "
             << converti(numeri[i], 8) << " (oct) = " << converti(numeri[i], 16) << " (hex)" << endl;
    return 0;
}
