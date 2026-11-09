// Modulo 12 - Pattern: Pila (LIFO) e Coda (FIFO) generiche su nodi dinamici
// Compila: g++ -g pattern.cpp -o pattern.exe
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
struct Nodo {
    T valore;
    Nodo<T>* succ;
};

// ================= PILA: si entra e si esce SOLO dalla cima =================
template <typename T>
class Pila {
    Nodo<T>* cima = nullptr;           // la cima è la TESTA della lista
    int n = 0;
public:
    Pila() {}
    ~Pila() { while (!vuota()) pop(); }
    Pila(const Pila&) = delete;        // copia vietata (per semplicità)
    Pila& operator=(const Pila&) = delete;

    void push(const T& x) {            // inserimento in testa: O(1)
        cima = new Nodo<T>{x, cima};
        n++;
    }
    T pop() {                          // rimozione in testa: O(1)
        if (vuota()) throw underflow_error("pop su pila vuota");
        Nodo<T>* vecchia = cima;
        T x = vecchia->valore;         // salvo il valore PRIMA di cancellare
        cima = cima->succ;
        delete vecchia;
        n--;
        return x;
    }
    const T& top() const {             // guardo senza togliere
        if (vuota()) throw underflow_error("top su pila vuota");
        return cima->valore;
    }
    bool vuota() const { return cima == nullptr; }
    int size() const { return n; }
};

// ================= CODA: si entra dal fondo, si esce dalla testa =================
template <typename T>
class Coda {
    Nodo<T>* testa = nullptr;          // da qui si ESCE
    Nodo<T>* fondo = nullptr;          // da qui si ENTRA
    int n = 0;
public:
    Coda() {}
    ~Coda() { while (!vuota()) dequeue(); }
    Coda(const Coda&) = delete;
    Coda& operator=(const Coda&) = delete;

    void enqueue(const T& x) {         // inserimento in coda: O(1) grazie a "fondo"
        Nodo<T>* nuovo = new Nodo<T>{x, nullptr};
        if (vuota()) testa = nuovo;
        else fondo->succ = nuovo;
        fondo = nuovo;
        n++;
    }
    T dequeue() {                      // rimozione in testa: O(1)
        if (vuota()) throw underflow_error("dequeue su coda vuota");
        Nodo<T>* vecchia = testa;
        T x = vecchia->valore;
        testa = testa->succ;
        if (testa == nullptr) fondo = nullptr;   // si è svuotata: anche fondo va azzerato
        delete vecchia;
        n--;
        return x;
    }
    const T& front() const {
        if (vuota()) throw underflow_error("front su coda vuota");
        return testa->valore;
    }
    bool vuota() const { return testa == nullptr; }
    int size() const { return n; }
};

int main() {
    Pila<string> p;
    Coda<string> c;
    string arrivi[] = {"Anna", "Bruno", "Carla", "Dario"};
    for (int i = 0; i < 4; i++) { p.push(arrivi[i]); c.enqueue(arrivi[i]); }

    cout << "Arrivano: Anna, Bruno, Carla, Dario" << endl;
    cout << "In cima alla pila: " << p.top() << ", in testa alla coda: " << c.front() << endl;
    cout << "Escono dalla PILA (LIFO): ";
    while (!p.vuota()) cout << p.pop() << " ";
    cout << endl << "Escono dalla CODA (FIFO): ";
    while (!c.vuota()) cout << c.dequeue() << " ";
    cout << endl;

    try {
        p.pop();
    } catch (const underflow_error& e) {
        cout << "Errore: " << e.what() << endl;
    }
    return 0;
}
