// Esercizio 12.8 - Annulla e ripeti (undo/redo) con due pile
#include <iostream>
#include <string>
using namespace std;

template <typename T> struct Nodo { T valore; Nodo<T>* succ; };
template <typename T>
class Pila {
    Nodo<T>* cima = nullptr;
public:
    ~Pila() { svuota(); }
    void push(const T& x) { cima = new Nodo<T>{x, cima}; }
    T pop() { Nodo<T>* v = cima; T x = v->valore; cima = cima->succ; delete v; return x; }
    bool vuota() const { return cima == nullptr; }
    void svuota() { while (!vuota()) pop(); }
};

class Editor {
    string testo;
    Pila<string> annulla, ripeti;     // salvano le VERSIONI precedenti del testo
public:
    void scrivi(const string& s) {
        annulla.push(testo);          // salvo lo stato prima della modifica
        ripeti.svuota();              // una nuova modifica cancella la possibilità di "ripeti"
        testo += s;
    }
    void undo() {
        if (annulla.vuota()) { cout << "  (niente da annullare)" << endl; return; }
        ripeti.push(testo);
        testo = annulla.pop();
    }
    void redo() {
        if (ripeti.vuota()) { cout << "  (niente da ripetere)" << endl; return; }
        annulla.push(testo);
        testo = ripeti.pop();
    }
    void mostra() const { cout << "  \"" << testo << "\"" << endl; }
};

int main() {
    Editor e;
    e.scrivi("Ciao"); e.scrivi(" mondo"); e.scrivi("!"); e.mostra();
    e.undo(); e.mostra();
    e.undo(); e.mostra();
    e.redo(); e.mostra();
    e.scrivi("?"); e.mostra();
    e.redo();
    e.undo(); e.undo(); e.undo(); e.mostra();
    return 0;
}
