// Esercizio 5.3 - stampa e somma generiche
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void stampaArray(const T v[], int n) {
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
}

// Richiede: T() (valore "zero" del tipo) e l'operatore +=
template <typename T>
T somma(const T v[], int n) {
    T s = T();            // int() = 0, double() = 0.0, string() = ""
    for (int i = 0; i < n; i++) s += v[i];
    return s;
}

int main() {
    int vi[] = {1, 2, 3, 4};
    double vd[] = {0.5, 0.25, 0.125};
    string vs[] = {"tem", "pla", "te"};
    stampaArray(vi, 4); cout << "somma: " << somma(vi, 4) << endl;
    stampaArray(vd, 3); cout << "somma: " << somma(vd, 3) << endl;
    stampaArray(vs, 3); cout << "somma: " << somma(vs, 3) << endl;   // per le stringhe + concatena
    return 0;
}
