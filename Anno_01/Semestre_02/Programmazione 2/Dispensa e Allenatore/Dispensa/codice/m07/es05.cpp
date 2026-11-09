// Esercizio 7.5 - Ricerca binaria ricorsiva e posizione di inserimento
#include <iostream>
using namespace std;

int binariaRic(const int a[], int sx, int dx, int x) {
    if (sx > dx) return -1;                         // caso base: intervallo vuoto
    int m = (sx + dx) / 2;
    if (a[m] == x) return m;
    if (a[m] < x) return binariaRic(a, m + 1, dx, x);
    return binariaRic(a, sx, m - 1, x);
}

// Prima posizione in cui x può essere inserito mantenendo l'array ordinato
int posizioneInserimento(const int a[], int n, int x) {
    int sx = 0, dx = n;                             // nota: dx = n, non n-1
    while (sx < dx) {
        int m = (sx + dx) / 2;
        if (a[m] < x) sx = m + 1;
        else dx = m;
    }
    return sx;
}

int main() {
    int a[] = {3, 8, 8, 15, 21, 40};
    int n = 6;
    int prove[] = {15, 4, 8, 50, 1};
    for (int k = 0; k < 5; k++) {
        int x = prove[k];
        cout << x << ": trovato in " << binariaRic(a, 0, n - 1, x)
             << ", si inserirebbe in posizione " << posizioneInserimento(a, n, x) << endl;
    }
    return 0;
}
