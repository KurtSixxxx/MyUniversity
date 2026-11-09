// Esercizio 10.10 - Data con ++ (giorno successivo), <, - (giorni di differenza) e <<
#include <iostream>
using namespace std;

class Data {
    int g, m, a;
    static bool bisestile(int anno) { return (anno % 4 == 0 && anno % 100 != 0) || anno % 400 == 0; }
    static int giorniNelMese(int mese, int anno) {
        int gm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (mese == 2 && bisestile(anno)) ? 29 : gm[mese - 1];
    }
public:
    Data(int giorno, int mese, int anno) : g(giorno), m(mese), a(anno) {}
    Data& operator++() {                           // giorno successivo
        g++;
        if (g > giorniNelMese(m, a)) { g = 1; m++; }
        if (m > 12) { m = 1; a++; }
        return *this;
    }
    bool operator<(const Data& d) const {
        if (a != d.a) return a < d.a;
        if (m != d.m) return m < d.m;
        return g < d.g;
    }
    bool operator==(const Data& d) const { return g == d.g && m == d.m && a == d.a; }
    int operator-(const Data& prima) const {       // giorni da "prima" a *this (contando con ++)
        if (*this < prima) return -(prima - *this);
        int giorni = 0;
        Data d = prima;
        while (!(d == *this)) { ++d; giorni++; }
        return giorni;
    }
    friend ostream& operator<<(ostream& os, const Data& d) {
        return os << (d.g < 10 ? "0" : "") << d.g << "/" << (d.m < 10 ? "0" : "") << d.m << "/" << d.a;
    }
};

int main() {
    Data d(28, 2, 2024);
    cout << d;
    ++d; cout << " -> " << d;
    ++d; cout << " -> " << d << endl;
    Data capodanno(31, 12, 2025);
    cout << capodanno << " -> " << ++capodanno << endl;
    Data oggi(5, 11, 2026), esame(27, 11, 2026);
    cout << "giorni all'esame: " << esame - oggi << endl;
    cout << (oggi < esame ? "oggi viene prima dell'esame" : "?") << endl;
    return 0;
}
