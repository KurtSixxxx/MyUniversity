// Esercizio 12.2 - Invertire una stringa (e le parole di una frase) con una pila
#include <iostream>
#include <string>
#include <sstream>
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

string inverti(const string& s) {
    Pila<char> p;
    for (int i = 0; i < (int)s.length(); i++) p.push(s[i]);
    string r;
    while (!p.vuota()) r += p.pop();
    return r;
}

string invertiParole(const string& frase) {
    Pila<string> p;
    stringstream ss(frase);
    string parola;
    while (ss >> parola) p.push(parola);
    string r;
    while (!p.vuota()) { r += p.pop(); if (!p.vuota()) r += " "; }
    return r;
}

int main() {
    cout << inverti("programmazione") << endl;
    cout << invertiParole("la pila esce al contrario") << endl;
    return 0;
}
