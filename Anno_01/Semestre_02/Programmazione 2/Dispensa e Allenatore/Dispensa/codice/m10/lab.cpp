// Modulo 10 - Laboratorio a step: la classe Vettore (come la classe Array delle slide)
// Compila: g++ -g lab.cpp -o lab.exe
#include <iostream>
#include <stdexcept>
using namespace std;

class Vettore {
private:
    int* dati;
    int n;

public:
    explicit Vettore(int dim = 0) : dati(dim > 0 ? new int[dim] : nullptr), n(dim > 0 ? dim : 0) {
        for (int i = 0; i < n; i++) dati[i] = 0;
    }

    // ===== STEP 5 =====  Regola dei Tre (operator= è anch'esso un operatore!)
    Vettore(const Vettore& v) : dati(v.n > 0 ? new int[v.n] : nullptr), n(v.n) {
        for (int i = 0; i < n; i++) dati[i] = v.dati[i];
    }
    Vettore& operator=(const Vettore& v) {
        if (this != &v) {
            int* nuovo = (v.n > 0) ? new int[v.n] : nullptr;
            for (int i = 0; i < v.n; i++) nuovo[i] = v.dati[i];
            delete[] dati;
            dati = nuovo;
            n = v.n;
        }
        return *this;
    }
    ~Vettore() { delete[] dati; }

    int size() const { return n; }

    // ===== STEP 2 =====  operator[]: due versioni
    int& operator[](int i) {                       // per SCRIVERE: v[3] = 7 (restituisce un riferimento)
        if (i < 0 || i >= n) throw out_of_range("indice fuori dal vettore");
        return dati[i];
    }
    int operator[](int i) const {                  // per LEGGERE da un Vettore const
        if (i < 0 || i >= n) throw out_of_range("indice fuori dal vettore");
        return dati[i];
    }

    // ===== STEP 4 =====  += come membro (modifica me), + come esterno (crea un nuovo vettore)
    Vettore& operator+=(const Vettore& v) {        // somma elemento per elemento
        if (n != v.n) throw invalid_argument("dimensioni diverse");
        for (int i = 0; i < n; i++) dati[i] += v.dati[i];
        return *this;
    }

    // ===== STEP 6 =====  Concatenazione con l'operatore |  (un uso "creativo" ma lecito)
    Vettore operator|(const Vettore& v) const {
        Vettore r(n + v.n);
        for (int i = 0; i < n; i++) r.dati[i] = dati[i];
        for (int i = 0; i < v.n; i++) r.dati[n + i] = v.dati[i];
        return r;
    }

    friend ostream& operator<<(ostream& os, const Vettore& v);   // ===== STEP 1 =====
    friend istream& operator>>(istream& is, Vettore& v);         // ===== STEP 6 =====
    friend bool operator==(const Vettore& a, const Vettore& b);  // ===== STEP 3 =====
};

// ===== STEP 1 =====  Stampa: [ 1 2 3 ]
ostream& operator<<(ostream& os, const Vettore& v) {
    os << "[ ";
    for (int i = 0; i < v.n; i++) os << v.dati[i] << " ";
    return os << "]";
}

// ===== STEP 3 =====  Uguaglianza (come nelle slide) e disuguaglianza
bool operator==(const Vettore& a, const Vettore& b) {
    if (a.n != b.n) return false;
    for (int i = 0; i < a.n; i++)
        if (a.dati[i] != b.dati[i]) return false;
    return true;
}
bool operator!=(const Vettore& a, const Vettore& b) { return !(a == b); }

// ===== STEP 4 =====
Vettore operator+(const Vettore& a, const Vettore& b) {
    Vettore r = a;
    r += b;
    return r;
}

// ===== STEP 6 =====  Lettura: prima la dimensione, poi gli elementi
istream& operator>>(istream& is, Vettore& v) {
    int dim;
    if (!(is >> dim) || dim < 0) { is.setstate(ios::failbit); return is; }
    Vettore tmp(dim);
    for (int i = 0; i < dim; i++) is >> tmp.dati[i];
    if (is) v = tmp;                               // solo se tutto è andato bene
    return is;
}

int main() {
    Vettore a(4);
    cout << "STEP 1: a = " << a << endl;

    for (int i = 0; i < a.size(); i++) a[i] = (i + 1) * 10;     // STEP 2: [] in scrittura
    const Vettore copiaCostante = a;
    cout << "STEP 2: a = " << a << ", copiaCostante[2] = " << copiaCostante[2] << endl;
    try {
        a[10] = 5;
    } catch (const out_of_range& e) {
        cout << "        errore: " << e.what() << endl;
    }

    Vettore b = a;                                              // STEP 3
    cout << "STEP 3: a == b ? " << (a == b ? "si" : "no");
    b[0] = 99;
    cout << ", dopo b[0] = 99: a == b ? " << (a == b ? "si" : "no") << endl;

    cout << "STEP 4: a + b = " << a + b << endl;                // STEP 4
    a += a;
    cout << "        dopo a += a: a = " << a << endl;

    Vettore c;                                                  // STEP 5
    c = a;
    c[1] = -1;
    cout << "STEP 5: c = " << c << ", a = " << a << " (indipendenti)" << endl;

    Vettore letto;                                              // STEP 6
    cin >> letto;
    cout << "STEP 6: letto = " << letto << ", letto | b = " << (letto | b) << endl;
    return 0;
}
