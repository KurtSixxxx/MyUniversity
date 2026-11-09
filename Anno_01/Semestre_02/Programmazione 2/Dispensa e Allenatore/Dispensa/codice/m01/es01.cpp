// Esercizio 1.1 - Rettangolo
#include <iostream>
using namespace std;

class Rettangolo {
private:
    double base, altezza;

public:
    Rettangolo(double b, double h) {
        base = 1; altezza = 1;          // valori sicuri di partenza
        setBase(b);                     // riuso i setter: il controllo è in un solo posto
        setAltezza(h);
    }
    bool setBase(double b) {
        if (b <= 0) return false;
        base = b;
        return true;
    }
    bool setAltezza(double h) {
        if (h <= 0) return false;
        altezza = h;
        return true;
    }
    double area() const { return base * altezza; }
    double perimetro() const { return 2 * (base + altezza); }
    void stampa() const {
        cout << "Rettangolo " << base << " x " << altezza
             << " -> area " << area() << ", perimetro " << perimetro() << endl;
    }
};

int main() {
    Rettangolo r(3, 4);
    r.stampa();
    if (!r.setBase(-5)) cout << "Base -5 rifiutata" << endl;
    r.setAltezza(10);
    r.stampa();
    Rettangolo s(0, 2);                 // base non valida: resta 1
    s.stampa();
    return 0;
}
