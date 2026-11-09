// Esercizio 10.9 - Insieme di interi: unione (+), intersezione (*), differenza (-), ==
#include <iostream>
using namespace std;

class Insieme {
    int* v;
    int n, cap;
public:
    Insieme() : v(new int[4]), n(0), cap(4) {}
    Insieme(const Insieme& o) : v(new int[o.cap]), n(o.n), cap(o.cap) { for (int i = 0; i < n; i++) v[i] = o.v[i]; }
    Insieme& operator=(const Insieme& o) {
        if (this != &o) {
            int* nuovo = new int[o.cap];
            for (int i = 0; i < o.n; i++) nuovo[i] = o.v[i];
            delete[] v; v = nuovo; n = o.n; cap = o.cap;
        }
        return *this;
    }
    ~Insieme() { delete[] v; }

    bool contiene(int x) const { for (int i = 0; i < n; i++) if (v[i] == x) return true; return false; }
    Insieme& operator+=(int x) {                      // aggiunge x se non c'è già
        if (contiene(x)) return *this;
        if (n == cap) {
            int* nuovo = new int[cap * 2];
            for (int i = 0; i < n; i++) nuovo[i] = v[i];
            delete[] v; v = nuovo; cap *= 2;
        }
        v[n++] = x;
        return *this;
    }
    Insieme operator+(const Insieme& o) const {        // unione
        Insieme r = *this;
        for (int i = 0; i < o.n; i++) r += o.v[i];
        return r;
    }
    Insieme operator*(const Insieme& o) const {        // intersezione
        Insieme r;
        for (int i = 0; i < n; i++) if (o.contiene(v[i])) r += v[i];
        return r;
    }
    Insieme operator-(const Insieme& o) const {        // differenza
        Insieme r;
        for (int i = 0; i < n; i++) if (!o.contiene(v[i])) r += v[i];
        return r;
    }
    bool operator==(const Insieme& o) const {          // stessi elementi, ordine qualunque
        if (n != o.n) return false;
        for (int i = 0; i < n; i++) if (!o.contiene(v[i])) return false;
        return true;
    }
    friend ostream& operator<<(ostream& os, const Insieme& s) {
        os << "{";
        for (int i = 0; i < s.n; i++) os << (i ? ", " : "") << s.v[i];
        return os << "}";
    }
};

int main() {
    Insieme a, b;
    int va[] = {1, 2, 3, 4, 2, 1};
    int vb[] = {3, 4, 5, 6};
    for (int i = 0; i < 6; i++) a += va[i];
    for (int i = 0; i < 4; i++) b += vb[i];
    cout << "A = " << a << ", B = " << b << endl;
    cout << "A + B = " << a + b << endl;
    cout << "A * B = " << a * b << endl;
    cout << "A - B = " << a - b << endl;
    cout << "(A - B) + (A * B) == A ? " << ((a - b) + (a * b) == a ? "si" : "no") << endl;
    return 0;
}
