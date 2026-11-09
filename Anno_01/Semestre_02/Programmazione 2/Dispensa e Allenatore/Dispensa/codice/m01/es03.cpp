// Esercizio 1.3 - struct contro class
#include <iostream>
#include <cmath>
using namespace std;

struct PuntoS {          // struct: senza specificatori tutto è PUBLIC
    double x, y;
};

class PuntoC {           // class: senza specificatori tutto è PRIVATE
    double x, y;         // <- privati!
public:
    PuntoC(double a, double b) { x = a; y = b; }
    double distanzaOrigine() const { return sqrt(x * x + y * y); }
};

int main() {
    PuntoS p;
    p.x = 3;             // OK: x è public
    p.y = 4;
    cout << "struct: distanza = " << sqrt(p.x * p.x + p.y * p.y) << endl;

    PuntoC q(3, 4);
    // q.x = 3;          // ERRORE: 'double PuntoC::x' is private within this context
    cout << "class:  distanza = " << q.distanzaOrigine() << endl;
    return 0;
}
