// Esercizio 3.5 - Invertire un array "sul posto" con due puntatori
#include <iostream>
using namespace std;

void inverti(int* v, int n) {
    int* sx = v;              // primo elemento
    int* dx = v + n - 1;      // ultimo elemento
    while (sx < dx) {         // si incontrano a metà
        int t = *sx;
        *sx = *dx;
        *dx = t;
        sx++;
        dx--;
    }
}

void stampa(const int* v, int n) {
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
}

int main() {
    int pari[6] = {1, 2, 3, 4, 5, 6};
    int dispari[5] = {10, 20, 30, 40, 50};
    inverti(pari, 6);
    inverti(dispari, 5);
    stampa(pari, 6);
    stampa(dispari, 5);
    return 0;
}
