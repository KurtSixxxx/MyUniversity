// Esercizio 1.10 - Frazione sempre semplificata (invariante di classe)
#include <iostream>
using namespace std;

class Frazione {
private:
    int num, den;        // INVARIANTE: den > 0 e frazione ridotta ai minimi termini

    static int mcd(int a, int b) {        // algoritmo di Euclide
        if (a < 0) a = -a;
        while (b != 0) { int r = a % b; a = b; b = r; }
        return a;
    }
    void semplifica() {                   // privato: lo chiamano solo i metodi della classe
        if (den < 0) { num = -num; den = -den; }   // il segno sta sempre al numeratore
        int m = mcd(num, den);
        if (m > 1) { num /= m; den /= m; }
    }

public:
    Frazione(int n, int d) {
        if (d == 0) { n = 0; d = 1; }     // denominatore nullo: diventa 0/1
        num = n; den = d;
        semplifica();
    }
    Frazione somma(Frazione altra) const {          // restituisce un NUOVO oggetto
        return Frazione(num * altra.den + altra.num * den, den * altra.den);
    }
    Frazione prodotto(Frazione altra) const {
        return Frazione(num * altra.num, den * altra.den);
    }
    double valore() const { return (double)num / den; }
    void stampa() const {
        cout << num;
        if (den != 1) cout << "/" << den;
    }
};

int main() {
    Frazione a(2, 4), b(1, -3), c(5, 0);
    cout << "a = "; a.stampa(); cout << endl;            // 1/2
    cout << "b = "; b.stampa(); cout << endl;            // -1/3
    cout << "c = "; c.stampa(); cout << endl;            // 0
    cout << "a + b = "; a.somma(b).stampa(); cout << endl;
    cout << "a * b = "; a.prodotto(b).stampa();
    cout << " = " << a.prodotto(b).valore() << endl;
    cout << "a + a = "; a.somma(a).stampa(); cout << endl;   // 1
    return 0;
}
