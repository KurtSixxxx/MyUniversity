// Esercizio 3.4 - Statistiche: tre risultati da una sola funzione
#include <iostream>
using namespace std;

// Restituisce false se l'array è vuoto. I risultati escono dai parametri reference.
bool statistiche(const int v[], int n, int& minimo, int& massimo, double& media) {
    if (n <= 0) return false;
    minimo = massimo = v[0];
    int somma = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] < minimo) minimo = v[i];
        if (v[i] > massimo) massimo = v[i];
        somma += v[i];
    }
    media = (double)somma / n;
    return true;
}

int main() {
    int voti[] = {24, 30, 18, 27, 26};
    int mn, mx;
    double med;
    if (statistiche(voti, 5, mn, mx, med))
        cout << "min " << mn << ", max " << mx << ", media " << med << endl;
    if (!statistiche(voti, 0, mn, mx, med))
        cout << "array vuoto: nessuna statistica" << endl;
    return 0;
}
