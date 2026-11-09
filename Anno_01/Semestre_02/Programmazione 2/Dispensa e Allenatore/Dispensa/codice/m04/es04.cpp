// Esercizio 4.4 - Il puntatore this
#include <iostream>
using namespace std;

class Punto {
private:
    int x, y;

public:
    Punto(int x = 0, int y = 0) {
        this->x = x;      // this->x è l'attributo, x da solo è il parametro
        this->y = y;
    }
    // Restituendo *this (per reference) si possono concatenare le chiamate
    Punto& setX(int x) { this->x = x; return *this; }
    Punto& setY(int y) { this->y = y; return *this; }
    Punto& sposta(int dx, int dy) { x += dx; y += dy; return *this; }

    bool stessoOggetto(const Punto& altro) const { return this == &altro; }  // stesso indirizzo?
    bool stesseCoordinate(const Punto& altro) const { return x == altro.x && y == altro.y; }

    void stampa() const { cout << "(" << x << ", " << y << ") all'indirizzo " << this << endl; }
};

int main() {
    Punto p;
    p.setX(3).setY(4).sposta(1, 1);       // tre messaggi in fila allo STESSO oggetto
    p.stampa();

    Punto q(4, 5);
    Punto& r = p;
    cout << boolalpha;                    // stampa true/false invece di 1/0
    cout << "p e q stesse coordinate? " << p.stesseCoordinate(q) << endl;
    cout << "p e q stesso oggetto?    " << p.stessoOggetto(q) << endl;
    cout << "p e r stesso oggetto?    " << p.stessoOggetto(r) << endl;
    return 0;
}
