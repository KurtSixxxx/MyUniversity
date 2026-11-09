// Esercizio 5.5 - ricerca generica (esercizio delle slide) con int, char e Punto
#include <iostream>
using namespace std;

template <typename T>
int ricerca(T dato, T v[], int dim) {
    for (int i = 0; i < dim; i++)
        if (v[i] == dato) return i;      // richiede l'operatore == su T
    return -1;
}

class Punto {
private:
    int x, y;
public:
    Punto(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Punto& p) const { return x == p.x && y == p.y; }   // anteprima Modulo 10
    friend ostream& operator<<(ostream& os, const Punto& p) { return os << "(" << p.x << "," << p.y << ")"; }
};

template <typename T>
void stampa(T v[], int n) {
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
}

int main() {
    int vi[] = {5, 8, 13, 21};
    char vc[] = {'x', 'y', 'z'};
    Punto vp[] = {Punto(0, 0), Punto(1, 2), Punto(3, 4)};
    stampa(vi, 4); stampa(vc, 3); stampa(vp, 3);

    int ni; char nc; int px, py;
    cin >> ni >> nc >> px >> py;                 // valori da cercare (dall'input)
    cout << ni << " -> indice " << ricerca(ni, vi, 4) << endl;
    cout << nc << " -> indice " << ricerca(nc, vc, 3) << endl;
    cout << Punto(px, py) << " -> indice " << ricerca(Punto(px, py), vp, 3) << endl;
    cout << "(9,9) -> indice " << ricerca(Punto(9, 9), vp, 3) << endl;
    return 0;
}
