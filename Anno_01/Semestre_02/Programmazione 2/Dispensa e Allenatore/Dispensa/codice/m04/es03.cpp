// Esercizio 4.3 - Contare gli oggetti vivi con un membro static
#include <iostream>
using namespace std;

class Punto {
private:
    int x, y;
    static int vivi;                 // UNO solo per tutta la classe
    static int creati;

public:
    Punto(int a = 0, int b = 0) : x(a), y(b) { vivi++; creati++; }
    Punto(const Punto& p) : x(p.x), y(p.y) { vivi++; creati++; }   // anche le copie contano
    ~Punto() { vivi--; }

    static int getVivi() { return vivi; }       // si chiama con Punto::getVivi()
    static int getCreati() { return creati; }
};

int Punto::vivi = 0;                 // definizione e inizializzazione, fuori dalla classe
int Punto::creati = 0;

void perValore(Punto) {              // parametro senza nome: riceve una COPIA, che nasce qui e muore alla fine
    cout << "  dentro perValore: vivi = " << Punto::getVivi() << endl;
}

int main() {
    cout << "all'inizio: " << Punto::getVivi() << endl;
    Punto a(1, 2), b;
    cout << "dopo a, b: " << Punto::getVivi() << endl;
    {
        Punto c = a;
        Punto* d = new Punto(5, 5);
        cout << "nel blocco: " << Punto::getVivi() << endl;
        delete d;
    }
    cout << "dopo il blocco: " << Punto::getVivi() << endl;
    perValore(a);
    cout << "dopo perValore: " << Punto::getVivi()
         << " (creati in tutto: " << Punto::getCreati() << ")" << endl;
    return 0;
}
