// Esercizio 10.1 - Punto con ==, != e <<
#include <iostream>
using namespace std;

class Punto {
    int x, y;
public:
    Punto(int x = 0, int y = 0) : x(x), y(y) {}
    // == come METODO: l'operando di sinistra è *this, quello di destra è il parametro
    bool operator==(const Punto& p) const { return x == p.x && y == p.y; }
    bool operator!=(const Punto& p) const { return !(*this == p); }       // riuso ==
    // << deve essere ESTERNO (a sinistra c'è cout, non un Punto): friend per leggere x e y
    friend ostream& operator<<(ostream& os, const Punto& p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

int main() {
    Punto a(1, 2), b(1, 2), c(3, 4);
    cout << a << " == " << b << " ? " << (a == b ? "si" : "no") << endl;
    cout << a << " != " << c << " ? " << (a != c ? "si" : "no") << endl;
    cout << "concatenato: " << a << " " << b << " " << c << endl;
    return 0;
}
