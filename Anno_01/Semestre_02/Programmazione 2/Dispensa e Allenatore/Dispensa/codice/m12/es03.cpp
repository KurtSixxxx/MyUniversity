// Esercizio 12.3 - La coda di stampa (FIFO)
#include <iostream>
#include <string>
using namespace std;

struct Lavoro { string documento; int pagine; };

template <typename T> struct Nodo { T valore; Nodo<T>* succ; };
template <typename T>
class Coda {
    Nodo<T>* testa = nullptr; Nodo<T>* fondo = nullptr;
public:
    ~Coda() { while (!vuota()) dequeue(); }
    void enqueue(const T& x) {
        Nodo<T>* n = new Nodo<T>{x, nullptr};
        if (vuota()) testa = n; else fondo->succ = n;
        fondo = n;
    }
    T dequeue() { Nodo<T>* v = testa; T x = v->valore; testa = testa->succ; if (!testa) fondo = nullptr; delete v; return x; }
    bool vuota() const { return testa == nullptr; }
};

int main() {
    Coda<Lavoro> stampante;
    stampante.enqueue({"tesi.pdf", 120});
    stampante.enqueue({"biglietto.pdf", 1});
    stampante.enqueue({"slide.pdf", 40});
    int minuto = 0;
    while (!stampante.vuota()) {
        Lavoro l = stampante.dequeue();
        int durata = (l.pagine + 19) / 20;            // 20 pagine al minuto, arrotondato per eccesso
        cout << "minuto " << minuto << ": stampo " << l.documento << " (" << l.pagine
             << " pag., " << durata << " min)" << endl;
        minuto += durata;
    }
    cout << "finito al minuto " << minuto << endl;
    // Il biglietto da 1 pagina aspetta 6 minuti: in una coda FIFO conta solo l'ordine di arrivo
    return 0;
}
