// Esercizio 7.9 - Ordinamento generico con criterio a scelta (template + puntatore a funzione)
#include <iostream>
#include <string>
using namespace std;

struct Persona {
    string nome;
    int eta;
};

// "minore" decide l'ordine: lo sceglie chi chiama
template <typename T>
void ordina(T a[], int n, bool (*minore)(const T&, const T&)) {
    for (int i = 1; i < n; i++) {                 // insertion sort
        T x = a[i];
        int j = i - 1;
        while (j >= 0 && minore(x, a[j])) { a[j + 1] = a[j]; j--; }
        a[j + 1] = x;
    }
}

bool perEta(const Persona& a, const Persona& b) { return a.eta < b.eta; }
bool perNome(const Persona& a, const Persona& b) { return a.nome < b.nome; }
bool perEtaDecrescente(const Persona& a, const Persona& b) { return a.eta > b.eta; }
bool decrescente(const int& a, const int& b) { return a > b; }

void stampa(const Persona p[], int n) {
    for (int i = 0; i < n; i++) cout << p[i].nome << "(" << p[i].eta << ") ";
    cout << endl;
}

int main() {
    Persona p[] = {{"Marco", 31}, {"Ada", 22}, {"Luca", 45}, {"Bea", 19}};
    ordina(p, 4, perEta);             stampa(p, 4);
    ordina(p, 4, perNome);            stampa(p, 4);
    ordina(p, 4, perEtaDecrescente);  stampa(p, 4);
    int v[] = {4, 9, 1, 7};
    ordina(v, 4, decrescente);
    for (int i = 0; i < 4; i++) cout << v[i] << " ";
    cout << endl;
    return 0;
}
