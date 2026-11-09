// Esercizio 5.8 - Contenitore<T, N> con parametri di default (dalle slide)
#include <iostream>
#include <stdexcept>
using namespace std;

// N è un parametro NON di tipo: un valore intero noto a compile-time
template <typename T = int, int N = 5>
class Contenitore {
private:
    T dati[N];                    // array STATICO: N deve essere una costante
    int elementi;
public:
    Contenitore() : elementi(0) {}
    void inserire(T el) {
        if (elementi == N) throw overflow_error("contenitore pieno");
        dati[elementi++] = el;
    }
    T estrarre() {
        if (vuoto()) throw underflow_error("contenitore vuoto");
        return dati[--elementi];
    }
    int numero() const { return elementi; }
    bool vuoto() const { return elementi == 0; }
    int capacita() const { return N; }
};

int main() {
    Contenitore<> c;                       // T = int, N = 5 (tutti i default)
    Contenitore<char, 3> lettere;          // T = char, N = 3
    for (int i = 1; i <= 5; i++) c.inserire(i * 100);
    cout << "c: " << c.numero() << "/" << c.capacita() << endl;
    try {
        c.inserire(600);
    } catch (const overflow_error& e) {
        cout << "errore: " << e.what() << endl;
    }
    lettere.inserire('a'); lettere.inserire('b');
    cout << "estraggo da lettere: " << lettere.estrarre() << lettere.estrarre() << endl;
    // Contenitore<int, 5> e Contenitore<int, 6> sono DUE CLASSI DIVERSE per il compilatore
    return 0;
}
