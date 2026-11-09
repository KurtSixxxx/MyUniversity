// Esercizio 5.10 - Pila<T> generica e una funzione template che la usa
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class Pila {
private:
    T* dati;
    int cima, cap;
public:
    Pila() : dati(new T[2]), cima(0), cap(2) {}
    ~Pila() { delete[] dati; }
    Pila(const Pila& p) : dati(new T[p.cap]), cima(p.cima), cap(p.cap) {
        for (int i = 0; i < cima; i++) dati[i] = p.dati[i];
    }
    Pila& operator=(const Pila& p) {
        if (this != &p) {
            T* nuovo = new T[p.cap];
            for (int i = 0; i < p.cima; i++) nuovo[i] = p.dati[i];
            delete[] dati;
            dati = nuovo; cima = p.cima; cap = p.cap;
        }
        return *this;
    }
    void push(const T& x) {
        if (cima == cap) {
            T* nuovo = new T[cap * 2];
            for (int i = 0; i < cima; i++) nuovo[i] = dati[i];
            delete[] dati;
            dati = nuovo;
            cap *= 2;
        }
        dati[cima++] = x;
    }
    T pop() {
        if (vuota()) throw underflow_error("pila vuota");
        return dati[--cima];
    }
    bool vuota() const { return cima == 0; }
};

// Inverte un array di QUALSIASI tipo passando per una Pila<T>
template <typename T>
void invertiConPila(T v[], int n) {
    Pila<T> p;
    for (int i = 0; i < n; i++) p.push(v[i]);
    for (int i = 0; i < n; i++) v[i] = p.pop();     // escono al contrario (LIFO)
}

template <typename T>
void stampa(const T v[], int n) {
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
}

int main() {
    int vi[] = {1, 2, 3, 4, 5};
    string vs[] = {"primo", "secondo", "terzo"};
    invertiConPila(vi, 5);
    invertiConPila(vs, 3);
    stampa(vi, 5);
    stampa(vs, 3);

    // Parentesi bilanciate con Pila<char>
    string espr = "{[(a+b)*c]-(d)}";
    Pila<char> p;
    bool ok = true;
    for (int i = 0; i < (int)espr.length() && ok; i++) {
        char c = espr[i];
        if (c == '(' || c == '[' || c == '{') p.push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (p.vuota()) { ok = false; break; }
            char a = p.pop();
            ok = (a == '(' && c == ')') || (a == '[' && c == ']') || (a == '{' && c == '}');
        }
    }
    if (!p.vuota()) ok = false;
    cout << espr << (ok ? " e' bilanciata" : " NON e' bilanciata") << endl;
    return 0;
}
