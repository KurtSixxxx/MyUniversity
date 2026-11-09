// Esercizio 5.7 - Coppia<T, U>: un template di classe con due tipi
#include <iostream>
#include <string>
using namespace std;

template <typename T, typename U>
class Coppia {
private:
    T primo;
    U secondo;
public:
    Coppia(T p, U s) : primo(p), secondo(s) {}
    T getPrimo() const { return primo; }
    U getSecondo() const { return secondo; }
    void setPrimo(T p) { primo = p; }
    void setSecondo(U s) { secondo = s; }
    Coppia<U, T> invertita() const { return Coppia<U, T>(secondo, primo); }   // tipi scambiati!
    void stampa() const { cout << "(" << primo << ", " << secondo << ")" << endl; }
};

// Funzione template che "costruisce" una coppia deducendo i tipi da sola
template <typename T, typename U>
Coppia<T, U> creaCoppia(T a, U b) { return Coppia<T, U>(a, b); }

int main() {
    Coppia<string, int> eta("Mario", 22);
    eta.stampa();
    eta.setSecondo(23);
    eta.invertita().stampa();                 // Coppia<int, string>

    Coppia<double, double> punto(1.5, -2.0);
    punto.stampa();

    creaCoppia('x', 3.14).stampa();           // Coppia<char, double>, tipi dedotti
    return 0;
}
