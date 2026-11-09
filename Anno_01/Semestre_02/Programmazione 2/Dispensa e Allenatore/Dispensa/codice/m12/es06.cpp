// Esercizio 12.6 - Una coda costruita con due pile
#include <iostream>
#include <stdexcept>
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

template <typename T>
class CodaDuePile {
    Pila<T> entrata;              // qui entrano i nuovi elementi
    Pila<T> uscita;               // da qui escono, già nell'ordine giusto
public:
    void enqueue(const T& x) { entrata.push(x); }
    T dequeue() {
        if (uscita.vuota()) {                         // travaso SOLO quando l'uscita è vuota
            while (!entrata.vuota()) uscita.push(entrata.pop());   // l'ordine si capovolge
        }
        if (uscita.vuota()) throw underflow_error("coda vuota");
        return uscita.pop();
    }
    bool vuota() const { return entrata.vuota() && uscita.vuota(); }
};

int main() {
    CodaDuePile<int> c;
    for (int i = 1; i <= 3; i++) c.enqueue(i);
    cout << c.dequeue() << " ";            // 1
    c.enqueue(4); c.enqueue(5);
    while (!c.vuota()) cout << c.dequeue() << " ";   // 2 3 4 5
    cout << endl;
    return 0;
}
