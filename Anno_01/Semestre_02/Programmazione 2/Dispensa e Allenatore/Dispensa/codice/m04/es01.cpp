// Esercizio 4.1 - Rettangolo con parametri di default e lista di inizializzazione
#include <iostream>
#include <cmath>
using namespace std;

class Rettangolo {
private:
    double base, altezza;

public:
    // Un solo costruttore copre tre casi: R(), R(b), R(b, h)
    Rettangolo(double b = 1, double h = 1) : base(b > 0 ? b : 1), altezza(h > 0 ? h : 1) {}

    double getBase() const { return base; }
    double getAltezza() const { return altezza; }
    bool setBase(double b) { if (b <= 0) return false; base = b; return true; }
    bool setAltezza(double h) { if (h <= 0) return false; altezza = h; return true; }

    double area() const { return base * altezza; }
    double perimetro() const { return 2 * (base + altezza); }
    double diagonale() const { return sqrt(base * base + altezza * altezza); }
    bool isQuadrato() const { return base == altezza; }

    void stampa() const {
        cout << base << "x" << altezza << ": area " << area() << ", perimetro "
             << perimetro() << ", diagonale " << diagonale()
             << (isQuadrato() ? " (quadrato)" : "") << endl;
    }
};

int main() {
    Rettangolo r1;            // 1 x 1
    Rettangolo r2(4);         // 4 x 1
    Rettangolo r3(3, 4);      // 3 x 4
    Rettangolo r4(-2, 5);     // base non valida -> 1
    r1.stampa(); r2.stampa(); r3.stampa(); r4.stampa();
    const Rettangolo fisso(2, 2);
    cout << "Area del rettangolo costante: " << fisso.area() << endl;   // ok: area() è const
    // fisso.setBase(3);      // ERRORE: setBase non è const
    return 0;
}
