// Esercizio 8.6 - Invertire un array e una stringa, ricorsivamente
#include <iostream>
#include <string>
using namespace std;

// Scambio gli estremi, poi inverto la parte interna
void inverti(int v[], int i, int j) {
    if (i >= j) return;                  // 0 o 1 elementi: niente da fare
    int t = v[i]; v[i] = v[j]; v[j] = t;
    inverti(v, i + 1, j - 1);
}

// Il contrario di "ciao" è: contrario("iao") + 'c'
string contrario(const string& s) {
    if (s.length() <= 1) return s;
    return contrario(s.substr(1)) + s[0];      // substr(1) = la stringa senza il primo carattere
}

int main() {
    int v[] = {1, 2, 3, 4, 5, 6, 7};
    inverti(v, 0, 6);
    for (int i = 0; i < 7; i++) cout << v[i] << " ";
    cout << endl;
    cout << contrario("ricorsione") << endl;
    return 0;
}
