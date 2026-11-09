// Esercizio 4.5 - Punto2D dentro Rettangolo (composizione + lista di inizializzazione)
#include <iostream>
using namespace std;

class Punto2D {
private:
    int x, y;
public:
    Punto2D(int x = 0, int y = 0) : x(x), y(y) {}   // x(x): l'attributo x prende il parametro x
    int getX() const { return x; }
    int getY() const { return y; }
};

class Rettangolo {
private:
    Punto2D topLeft, bottomRight;      // due OGGETTI come attributi
public:
    // I membri oggetto si inizializzano nella lista: è il modo giusto
    Rettangolo(Punto2D tl, Punto2D br) : topLeft(tl), bottomRight(br) {}

    bool contiene(Punto2D p) const {
        return p.getX() >= topLeft.getX() && p.getX() <= bottomRight.getX()
            && p.getY() <= topLeft.getY() && p.getY() >= bottomRight.getY();
    }
    bool contiene(const Rettangolo& r) const {      // overloading: stesso nome, parametro diverso
        return contiene(r.topLeft) && contiene(r.bottomRight);
    }
};

int main() {
    Punto2D p = {10, 20};                  // le graffe chiamano il costruttore Punto2D(10, 20)
    Rettangolo B({10, 20}, {50, 10});      // come nella traccia delle slide
    Rettangolo piccolo({20, 18}, {30, 12});
    Rettangolo sporge({40, 25}, {60, 15});
    cout << boolalpha;
    cout << "B contiene p (sul bordo)?   " << B.contiene(p) << endl;
    cout << "B contiene (5, 15)?         " << B.contiene(Punto2D(5, 15)) << endl;
    cout << "B contiene piccolo?         " << B.contiene(piccolo) << endl;
    cout << "B contiene sporge?          " << B.contiene(sporge) << endl;
    return 0;
}
