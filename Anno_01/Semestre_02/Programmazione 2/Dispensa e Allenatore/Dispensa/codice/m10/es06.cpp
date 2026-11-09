// Esercizio 10.6 - Matrice 2x2 con operator() per l'accesso, * e ==
#include <iostream>
using namespace std;

class Matrice2 {
    double m[2][2];
public:
    Matrice2(double a = 0, double b = 0, double c = 0, double d = 0) {
        m[0][0] = a; m[0][1] = b; m[1][0] = c; m[1][1] = d;
    }
    double& operator()(int i, int j) { return m[i][j]; }          // M(i, j) = valore
    double operator()(int i, int j) const { return m[i][j]; }     // lettura su const
    Matrice2 operator*(const Matrice2& b) const {                  // prodotto righe per colonne
        Matrice2 r;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                r(i, j) = m[i][0] * b(0, j) + m[i][1] * b(1, j);
        return r;
    }
    bool operator==(const Matrice2& b) const {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                if (m[i][j] != b(i, j)) return false;
        return true;
    }
    friend ostream& operator<<(ostream& os, const Matrice2& a) {
        return os << "[" << a(0, 0) << " " << a(0, 1) << "; " << a(1, 0) << " " << a(1, 1) << "]";
    }
};

int main() {
    Matrice2 A(1, 2, 3, 4), I(1, 0, 0, 1), B(0, 1, 1, 0);
    cout << "A * I = " << A * I << (A * I == A ? "  (uguale ad A)" : "") << endl;
    cout << "A * B = " << A * B << endl;
    cout << "B * A = " << B * A << "  (il prodotto non e' commutativo)" << endl;
    A(1, 1) = 10;
    cout << "dopo A(1,1) = 10: A = " << A << endl;
    return 0;
}
