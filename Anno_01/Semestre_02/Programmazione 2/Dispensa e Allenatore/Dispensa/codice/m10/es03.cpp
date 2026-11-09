// Esercizio 10.3 - Numeri complessi: + - * con operatori esterni
#include <iostream>
using namespace std;

class Complesso {
    double re, im;
public:
    Complesso(double r = 0, double i = 0) : re(r), im(i) {}
    double getRe() const { return re; }
    double getIm() const { return im; }
};

// Operatori ESTERNI senza friend: usano solo i getter pubblici
Complesso operator+(const Complesso& a, const Complesso& b) {
    return Complesso(a.getRe() + b.getRe(), a.getIm() + b.getIm());
}
Complesso operator-(const Complesso& a, const Complesso& b) {
    return Complesso(a.getRe() - b.getRe(), a.getIm() - b.getIm());
}
Complesso operator*(const Complesso& a, const Complesso& b) {     // (a+bi)(c+di) = (ac-bd) + (ad+bc)i
    return Complesso(a.getRe() * b.getRe() - a.getIm() * b.getIm(),
                     a.getRe() * b.getIm() + a.getIm() * b.getRe());
}
ostream& operator<<(ostream& os, const Complesso& c) {
    os << c.getRe();
    if (c.getIm() >= 0) os << "+";
    return os << c.getIm() << "i";
}

int main() {
    Complesso z(3, 2), w(1, -1);
    cout << "z = " << z << ", w = " << w << endl;
    cout << "z + w = " << z + w << endl;
    cout << "z - w = " << z - w << endl;
    cout << "z * w = " << z * w << endl;
    Complesso i(0, 1);
    cout << "i * i = " << i * i << endl;
    cout << "2 + z = " << 2 + z << "   (funziona perche' + e' esterno: 2 diventa Complesso(2))" << endl;
    return 0;
}
