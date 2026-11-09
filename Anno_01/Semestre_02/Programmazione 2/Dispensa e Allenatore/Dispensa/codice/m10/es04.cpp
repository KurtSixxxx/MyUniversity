// Esercizio 10.4 - ++ e -- prefissi e postfissi
#include <iostream>
using namespace std;

class Contatore {
    int valore;
public:
    Contatore(int v = 0) : valore(v) {}
    Contatore& operator++() { ++valore; return *this; }            // ++c: incrementa e restituisce SE STESSO
    Contatore operator++(int) { Contatore v = *this; ++valore; return v; }   // c++: restituisce la COPIA vecchia
    Contatore& operator--() { if (valore > 0) --valore; return *this; }      // non sotto zero
    Contatore operator--(int) { Contatore v = *this; if (valore > 0) --valore; return v; }
    friend ostream& operator<<(ostream& os, const Contatore& c) { return os << c.valore; }
};

int main() {
    Contatore c(5);
    cout << "c = " << c << endl;
    Contatore a = c++;
    cout << "a = c++  -> a = " << a << ", c = " << c << endl;
    Contatore b = ++c;
    cout << "b = ++c  -> b = " << b << ", c = " << c << endl;
    ++(++c);                                     // il prefisso restituisce un riferimento: si concatena
    cout << "dopo ++(++c): c = " << c << endl;
    Contatore z(1);
    z--; z--; z--;
    cout << "z dopo tre z--: " << z << endl;
    return 0;
}
