// Esercizio 4.10 - Pila di interi su array dinamico (anteprima del Modulo 12)
#include <iostream>
#include <stdexcept>
using namespace std;

class Pila {
private:
    int* dati;
    int cima;       // numero di elementi presenti (= indice della prima cella libera)
    int cap;

public:
    explicit Pila(int capacita = 4) : dati(new int[capacita > 0 ? capacita : 1]), cima(0),
                                     cap(capacita > 0 ? capacita : 1) {}
    Pila(const Pila& p) : dati(new int[p.cap]), cima(p.cima), cap(p.cap) {
        for (int i = 0; i < cima; i++) dati[i] = p.dati[i];
    }
    Pila& operator=(const Pila& p) {
        if (this != &p) {
            int* nuovo = new int[p.cap];
            for (int i = 0; i < p.cima; i++) nuovo[i] = p.dati[i];
            delete[] dati;
            dati = nuovo; cima = p.cima; cap = p.cap;
        }
        return *this;
    }
    ~Pila() { delete[] dati; }

    void push(int x) {
        if (cima == cap) {                         // piena: raddoppio
            int* nuovo = new int[cap * 2];
            for (int i = 0; i < cima; i++) nuovo[i] = dati[i];
            delete[] dati;
            dati = nuovo;
            cap *= 2;
        }
        dati[cima++] = x;
    }
    int pop() {
        if (vuota()) throw underflow_error("pop su pila vuota");
        return dati[--cima];
    }
    int top() const {
        if (vuota()) throw underflow_error("top su pila vuota");
        return dati[cima - 1];
    }
    bool vuota() const { return cima == 0; }
    int size() const { return cima; }
};

int main() {
    Pila p;
    for (int i = 1; i <= 6; i++) p.push(i * 10);
    Pila copia = p;                       // copia profonda
    cout << "Svuoto p: ";
    while (!p.vuota()) cout << p.pop() << " ";     // LIFO: esce prima l'ultimo entrato
    cout << endl;
    cout << "La copia ha ancora " << copia.size() << " elementi, in cima " << copia.top() << endl;
    try {
        p.pop();
    } catch (const underflow_error& e) {
        cout << "Errore: " << e.what() << endl;
    }
    return 0;
}
