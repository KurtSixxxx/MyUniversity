// Esercizio 12.1 - Pila su array statico, come nelle slide (con isFull)
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T, int CAP>
class PilaArray {
    T dati[CAP];
    int cima = -1;                        // indice dell'elemento in cima; -1 = vuota
public:
    bool vuota() const { return cima == -1; }
    bool piena() const { return cima == CAP - 1; }
    void push(const T& x) {
        if (piena()) throw overflow_error("pila piena");   // 1. verifico che non sia piena
        cima++;                                            // 2. incremento la cima
        dati[cima] = x;                                    // 3. inserisco
    }
    T pop() {
        if (vuota()) throw underflow_error("pila vuota");  // 1. verifico che non sia vuota
        T x = dati[cima];                                  // 2. leggo la cima
        cima--;                                            // 3. riduco la cima
        return x;
    }
};

int main() {
    PilaArray<int, 3> p;
    for (int i = 1; i <= 4; i++) {
        try { p.push(i * 10); cout << "push " << i * 10 << endl; }
        catch (const overflow_error& e) { cout << "push " << i * 10 << ": " << e.what() << endl; }
    }
    while (!p.vuota()) cout << "pop " << p.pop() << endl;
    try { p.pop(); } catch (const underflow_error& e) { cout << "pop: " << e.what() << endl; }
    return 0;
}
