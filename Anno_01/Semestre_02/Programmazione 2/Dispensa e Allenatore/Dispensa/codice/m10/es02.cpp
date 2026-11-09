// Esercizio 10.2 - Durata con + e << nel formato hh:mm:ss
#include <iostream>
using namespace std;

class Durata {
    int secondiTotali;
public:
    Durata(int h = 0, int m = 0, int s = 0) : secondiTotali(h * 3600 + m * 60 + s) {}
    Durata operator+(const Durata& d) const {         // + come metodo const: non modifica *this
        Durata r;
        r.secondiTotali = secondiTotali + d.secondiTotali;
        return r;
    }
    friend ostream& operator<<(ostream& os, const Durata& d) {
        int h = d.secondiTotali / 3600, m = d.secondiTotali % 3600 / 60, s = d.secondiTotali % 60;
        if (h < 10) os << "0";
        os << h << ":";
        if (m < 10) os << "0";
        os << m << ":";
        if (s < 10) os << "0";
        return os << s;
    }
};

int main() {
    Durata brano1(0, 3, 45), brano2(0, 4, 30), film(1, 52, 0);
    cout << brano1 << " + " << brano2 << " = " << brano1 + brano2 << endl;
    cout << "tutto insieme: " << brano1 + brano2 + film << endl;   // (brano1 + brano2) + film
    return 0;
}
