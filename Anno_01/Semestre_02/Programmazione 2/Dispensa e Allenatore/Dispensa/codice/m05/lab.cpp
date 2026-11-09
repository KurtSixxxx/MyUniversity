// Modulo 5 - Laboratorio a step: un magazzino generico
// Compila: g++ -g lab.cpp -o lab.exe
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// ===== STEP 1 =====  Template di funzione: stampa e massimo di un array
template <typename T>
void stampa(const T v[], int n) {
    for (int i = 0; i < n; i++) cout << v[i] << (i < n - 1 ? ", " : "\n");
}

template <typename T>
int indiceMassimo(const T v[], int n) {
    int im = 0;
    for (int i = 1; i < n; i++)
        if (v[im] < v[i]) im = i;          // uso solo "<": meno richieste su T
    return im;
}

// ===== STEP 2 =====  Ordinamento generico (selection sort)
template <typename T>
void ordina(T a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int iMin = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[iMin]) iMin = j;
        T tmp = a[i]; a[i] = a[iMin]; a[iMin] = tmp;
    }
}

// ===== STEP 3 =====  Una classe "compatibile" con i template: serve < e <<
class Rettangolo {
private:
    double b, h;
public:
    Rettangolo(double base = 1, double altezza = 1) : b(base), h(altezza) {}
    double area() const { return b * h; }
    // Anteprima Modulo 10: insegniamo a Rettangolo cosa vuol dire "<"
    bool operator<(const Rettangolo& altro) const { return area() < altro.area(); }
    // ...e come si stampa con <<
    friend ostream& operator<<(ostream& os, const Rettangolo& r) {
        return os << r.b << "x" << r.h;
    }
};

// ===== STEP 4 =====  Template di classe: un contenitore che cresce
template <typename T>
class Magazzino {
private:
    T* dati;
    int n, cap;
public:
    Magazzino() : dati(new T[2]), n(0), cap(2) {}
    ~Magazzino() { delete[] dati; }
    Magazzino(const Magazzino& m) : dati(new T[m.cap]), n(m.n), cap(m.cap) {
        for (int i = 0; i < n; i++) dati[i] = m.dati[i];
    }
    Magazzino& operator=(const Magazzino& m) {
        if (this != &m) {
            T* nuovo = new T[m.cap];
            for (int i = 0; i < m.n; i++) nuovo[i] = m.dati[i];
            delete[] dati;
            dati = nuovo; n = m.n; cap = m.cap;
        }
        return *this;
    }
    void inserire(const T& x) {
        if (n == cap) {
            cap *= 2;
            T* nuovo = new T[cap];
            for (int i = 0; i < n; i++) nuovo[i] = dati[i];
            delete[] dati;
            dati = nuovo;
        }
        dati[n++] = x;
    }
    T estrarre() {                                  // toglie e restituisce l'ultimo
        if (vuoto()) throw underflow_error("magazzino vuoto");
        return dati[--n];
    }
    int numero() const { return n; }
    bool vuoto() const { return n == 0; }
    void ordinaTutto() { ordina(dati, n); }          // riuso il template dello STEP 2
    void stampaTutto() const { stampa(dati, n); }
};

// ===== STEP 5 =====  Template con DUE parametri, usato dentro un altro template
template <typename K, typename V>
class Coppia {
private:
    K chiave;
    V valore;
public:
    Coppia() : chiave(), valore() {}               // K() e V(): valore "vuoto" del tipo
    Coppia(K k, V v) : chiave(k), valore(v) {}
    K getChiave() const { return chiave; }
    V getValore() const { return valore; }
    bool operator<(const Coppia& c) const { return chiave < c.chiave; }
    friend ostream& operator<<(ostream& os, const Coppia& c) {
        return os << c.chiave << "=" << c.valore;
    }
};

int main() {
    cout << "=== STEP 1 ===" << endl;
    int numeri[] = {7, 3, 9, 1, 4};
    string nomi[] = {"Rita", "Ugo", "Anna", "Zoe"};
    stampa(numeri, 5);
    cout << "massimo: " << numeri[indiceMassimo(numeri, 5)]
         << ", ultimo in ordine alfabetico: " << nomi[indiceMassimo(nomi, 4)] << endl;

    cout << "\n=== STEP 2 ===" << endl;
    char lettere[] = {'t', 'e', 'm', 'p', 'l', 'a', 't', 'e'};
    ordina(numeri, 5);  stampa(numeri, 5);
    ordina(lettere, 8); stampa(lettere, 8);
    ordina(nomi, 4);    stampa(nomi, 4);

    cout << "\n=== STEP 3 ===" << endl;
    Rettangolo r[] = {Rettangolo(3, 4), Rettangolo(1, 1), Rettangolo(2, 5), Rettangolo(6, 0.5)};
    cout << "prima:  "; stampa(r, 4);
    ordina(r, 4);
    cout << "dopo:   "; stampa(r, 4);
    cout << "il piu' grande: " << r[indiceMassimo(r, 4)] << endl;

    cout << "\n=== STEP 4 ===" << endl;
    Magazzino<double> md;
    double valori[] = {2.5, 0.5, 9.75, 4.0};
    for (int i = 0; i < 4; i++) md.inserire(valori[i]);
    md.ordinaTutto();
    md.stampaTutto();
    cout << "estraggo " << md.estrarre() << ", ne restano " << md.numero() << endl;
    Magazzino<Rettangolo> mr;
    mr.inserire(Rettangolo(2, 2));
    mr.inserire(Rettangolo(1, 3));
    mr.ordinaTutto();
    mr.stampaTutto();
    try {
        Magazzino<int> vuoto;
        vuoto.estrarre();
    } catch (const underflow_error& e) {
        cout << "errore: " << e.what() << endl;
    }

    cout << "\n=== STEP 5 ===" << endl;
    Magazzino< Coppia<string, int> > inventario;      // template dentro template
    inventario.inserire(Coppia<string, int>("viti", 120));
    inventario.inserire(Coppia<string, int>("bulloni", 45));
    inventario.inserire(Coppia<string, int>("dadi", 300));
    inventario.ordinaTutto();                          // ordina per chiave
    inventario.stampaTutto();
    return 0;
}
