// Esercizio 12.9 - Da notazione infissa a postfissa (algoritmo "dello scambio di binari")
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
    T top() const { return cima->valore; }
    bool vuota() const { return cima == nullptr; }
};

int priorita(char op) { return (op == '*' || op == '/') ? 2 : (op == '+' || op == '-') ? 1 : 0; }

// Le cifre passano subito all'uscita; gli operatori aspettano nella pila
string inPostfissa(const string& s) {
    Pila<char> ops;
    string out;
    for (char c : s) {
        if (c == ' ') continue;
        if (c >= '0' && c <= '9') { out += c; out += ' '; }
        else if (c == '(') ops.push(c);
        else if (c == ')') {
            while (ops.top() != '(') { out += ops.pop(); out += ' '; }
            ops.pop();                                  // butto la '('
        } else {                                        // operatore
            while (!ops.vuota() && priorita(ops.top()) >= priorita(c)) { out += ops.pop(); out += ' '; }
            ops.push(c);
        }
    }
    while (!ops.vuota()) { out += ops.pop(); out += ' '; }
    return out;
}

int valuta(const string& post) {                       // cifre singole
    Pila<int> p;
    for (char c : post) {
        if (c == ' ') continue;
        if (c >= '0' && c <= '9') { p.push(c - '0'); continue; }
        int b = p.pop(), a = p.pop();
        p.push(c == '+' ? a + b : c == '-' ? a - b : c == '*' ? a * b : a / b);
    }
    return p.pop();
}

int main() {
    string espr[] = {"3 + 4 * 2", "(3 + 4) * 2", "8 - 2 - 1", "(1 + 2) * (3 + 4) - 5"};
    for (int i = 0; i < 4; i++) {
        string post = inPostfissa(espr[i]);
        cout << espr[i] << "  ->  " << post << " =  " << valuta(post) << endl;
    }
    return 0;
}
