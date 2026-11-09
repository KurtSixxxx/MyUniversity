// Esercizio 12.5 - Palindromo con una pila e una coda insieme
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
template <typename T>
class Coda {
    Nodo<T>* testa = nullptr; Nodo<T>* fondo = nullptr;
public:
    ~Coda() { while (!vuota()) dequeue(); }
    void enqueue(const T& x) { Nodo<T>* n = new Nodo<T>{x, nullptr}; if (vuota()) testa = n; else fondo->succ = n; fondo = n; }
    T dequeue() { Nodo<T>* v = testa; T x = v->valore; testa = testa->succ; if (!testa) fondo = nullptr; delete v; return x; }
    bool vuota() const { return testa == nullptr; }
};

// La pila restituisce i caratteri al contrario, la coda nell'ordine originale:
// se escono sempre uguali, la frase è palindroma. Considero solo le lettere, senza distinguere maiuscole e minuscole.
bool palindromo(const string& s) {
    Pila<char> p;
    Coda<char> c;
    for (int i = 0; i < (int)s.length(); i++) {
        char ch = s[i];
        if (ch >= 'A' && ch <= 'Z') ch = ch - 'A' + 'a';
        if (ch < 'a' || ch > 'z') continue;       // salto spazi, apostrofi, punteggiatura
        p.push(ch);
        c.enqueue(ch);
    }
    while (!p.vuota())
        if (p.pop() != c.dequeue()) return false;
    return true;
}

int main() {
    string frasi[] = {"Anna", "I topi non avevano nipoti", "Programmazione", "Ai lati d'Italia"};
    for (int i = 0; i < 4; i++)
        cout << "\"" << frasi[i] << "\": " << (palindromo(frasi[i]) ? "palindroma" : "no") << endl;
    return 0;
}
