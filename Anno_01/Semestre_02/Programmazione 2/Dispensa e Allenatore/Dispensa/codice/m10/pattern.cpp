// Modulo 10 - Pattern: la classe Frazione con tutti gli operatori principali
// Compila: g++ -g pattern.cpp -o pattern.exe
#include <iostream>
#include <stdexcept>
using namespace std;

class Frazione {
private:
    int num, den;                               // den > 0, sempre ridotta
    static int mcd(int a, int b) {
        if (a < 0) a = -a;
        while (b != 0) { int r = a % b; a = b; b = r; }
        return a;
    }
    void semplifica() {
        if (den < 0) { num = -num; den = -den; }
        int m = mcd(num, den);
        if (m > 1) { num /= m; den /= m; }
    }

public:
    Frazione(int n = 0, int d = 1) : num(n), den(d) {
        if (den == 0) throw invalid_argument("denominatore nullo");
        semplifica();
    }

    // --- OPERATORI MEMBRO: l'operando di SINISTRA è *this ---
    Frazione& operator+=(const Frazione& b) {          // modifica me stesso, restituisce me stesso
        num = num * b.den + b.num * den;
        den = den * b.den;
        semplifica();
        return *this;
    }
    Frazione operator-() const { return Frazione(-num, den); }   // meno unario: -f
    Frazione& operator++() { num += den; return *this; }          // ++f (prefisso): +1, poi restituisce
    Frazione operator++(int) {                                     // f++ (postfisso): il parametro int
        Frazione vecchia = *this;                                  // è solo un segnaposto
        num += den;
        return vecchia;                                            // restituisce il valore PRIMA
    }

    // --- OPERATORI ESTERNI dichiarati friend: possono leggere num e den ---
    friend Frazione operator+(const Frazione& a, const Frazione& b);
    friend Frazione operator*(const Frazione& a, const Frazione& b);
    friend bool operator==(const Frazione& a, const Frazione& b);
    friend bool operator<(const Frazione& a, const Frazione& b);
    friend ostream& operator<<(ostream& os, const Frazione& f);
    friend istream& operator>>(istream& is, Frazione& f);
};

Frazione operator+(const Frazione& a, const Frazione& b) {
    Frazione r = a;          // copia di a...
    r += b;                  // ...riuso += (il codice della somma sta in un solo posto)
    return r;                // restituisco un oggetto NUOVO, per valore
}
Frazione operator*(const Frazione& a, const Frazione& b) {
    return Frazione(a.num * b.num, a.den * b.den);
}
bool operator==(const Frazione& a, const Frazione& b) {
    return a.num == b.num && a.den == b.den;     // sono sempre ridotte: basta confrontare
}
bool operator!=(const Frazione& a, const Frazione& b) { return !(a == b); }   // riuso ==
bool operator<(const Frazione& a, const Frazione& b) {
    return a.num * b.den < b.num * a.den;        // a/b < c/d  <=>  a*d < c*b  (den positivi)
}
ostream& operator<<(ostream& os, const Frazione& f) {
    os << f.num;
    if (f.den != 1) os << "/" << f.den;
    return os;                                   // restituisco lo stream: cout << a << b
}
istream& operator>>(istream& is, Frazione& f) {  // legge "n/d"
    int n, d;
    char barra;
    if (is >> n >> barra >> d && barra == '/' && d != 0) f = Frazione(n, d);
    else is.setstate(ios::failbit);              // segnalo l'errore come fa cin
    return is;
}

int main() {
    Frazione a(1, 2), b(3, 4), c(2, 4);
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "-b = " << -b << endl;
    cout << "a == c ? " << (a == c ? "si" : "no") << ",  a != b ? " << (a != b ? "si" : "no") << endl;
    cout << "a < b ? " << (a < b ? "si" : "no") << endl;
    a += Frazione(1, 3);
    cout << "dopo a += 1/3: a = " << a << endl;
    Frazione x = a++;
    cout << "x = a++  ->  x = " << x << ", a = " << a << endl;
    Frazione y = ++a;
    cout << "y = ++a  ->  y = " << y << ", a = " << a << endl;
    cout << "a + 1 = " << a + 1 << "   (1 diventa Frazione(1) da solo)" << endl;

    Frazione letta;
    while (cin >> letta) cout << "letta: " << letta << endl;
    return 0;
}
