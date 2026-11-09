// Modulo 5 - Pattern: template di funzione e template di classe
// Compila: g++ -g pattern.cpp -o pattern.exe
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// ---------- 1. TEMPLATE DI FUNZIONE ----------
// T è un "segnaposto" per un tipo: verrà sostituito dal compilatore.
template <typename T>
T massimo(T a, T b) {
    return (a > b) ? a : b;          // richiede che T sappia fare ">"
}

template <typename T>
void scambia(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void stampaArray(const T v[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) cout << v[i] << " ";   // richiede che T sappia fare "<<"
    cout << "]" << endl;
}

// ---------- 2. TEMPLATE DI CLASSE ----------
template <typename T>
class Scatola {
private:
    T* dati;
    int n, cap;

public:
    Scatola(int capacita = 4);
    ~Scatola() { delete[] dati; }
    Scatola(const Scatola& s);
    Scatola& operator=(const Scatola& s);

    void inserisci(const T& x);
    T get(int i) const;
    int size() const { return n; }
};

// I metodi definiti FUORI dalla classe ripetono "template <typename T>"
// e usano il nome completo Scatola<T>::
template <typename T>
Scatola<T>::Scatola(int capacita) : dati(new T[capacita]), n(0), cap(capacita) {}

template <typename T>
Scatola<T>::Scatola(const Scatola& s) : dati(new T[s.cap]), n(s.n), cap(s.cap) {
    for (int i = 0; i < n; i++) dati[i] = s.dati[i];
}

template <typename T>
Scatola<T>& Scatola<T>::operator=(const Scatola& s) {
    if (this != &s) {
        T* nuovo = new T[s.cap];
        for (int i = 0; i < s.n; i++) nuovo[i] = s.dati[i];
        delete[] dati;
        dati = nuovo; n = s.n; cap = s.cap;
    }
    return *this;
}

template <typename T>
void Scatola<T>::inserisci(const T& x) {
    if (n == cap) {
        T* nuovo = new T[cap * 2];
        for (int i = 0; i < n; i++) nuovo[i] = dati[i];
        delete[] dati;
        dati = nuovo;
        cap *= 2;
    }
    dati[n++] = x;
}

template <typename T>
T Scatola<T>::get(int i) const {
    if (i < 0 || i >= n) throw out_of_range("indice non valido");
    return dati[i];
}

int main() {
    // Il compilatore DEDUCE T dagli argomenti
    cout << massimo(3, 7) << " " << massimo(2.5, 1.5) << " "
         << massimo(string("ciao"), string("mondo")) << endl;
    // massimo(3, 4.5) non compila: T sarebbe int o double? Lo dico io:
    cout << massimo<double>(3, 4.5) << endl;

    int a = 1, b = 2;
    string s1 = "uno", s2 = "due";
    scambia(a, b);
    scambia(s1, s2);
    cout << a << " " << b << " " << s1 << " " << s2 << endl;

    char lettere[] = {'c', 'i', 'a', 'o'};
    stampaArray(lettere, 4);

    // Per le classi template il tipo si scrive SEMPRE tra < >
    Scatola<int> si;
    for (int i = 1; i <= 6; i++) si.inserisci(i * i);
    Scatola<string> ss;
    ss.inserisci("alfa");
    ss.inserisci("beta");
    Scatola<string> copia = ss;                 // costruttore di copia del template
    copia.inserisci("gamma");
    cout << "si: " << si.size() << " elementi, l'ultimo e' " << si.get(5) << endl;
    cout << "ss: " << ss.size() << ", copia: " << copia.size() << " (" << copia.get(2) << ")" << endl;
    return 0;
}
