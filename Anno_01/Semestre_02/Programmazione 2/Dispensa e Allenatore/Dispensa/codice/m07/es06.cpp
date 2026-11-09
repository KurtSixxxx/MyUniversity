// Esercizio 7.6 - MergeSort di oggetti per chiave: è STABILE
#include <iostream>
#include <string>
using namespace std;

struct Studente {
    string nome;
    int voto;
};

void merge(Studente a[], int sx, int c, int dx) {
    Studente* b = new Studente[dx - sx + 1];
    int i = sx, j = c + 1, k = 0;
    while (i <= c && j <= dx)
        // "<=" e non "<": a parità di voto passa prima quello di SINISTRA -> stabilità
        b[k++] = (a[i].voto <= a[j].voto) ? a[i++] : a[j++];
    while (i <= c) b[k++] = a[i++];
    while (j <= dx) b[k++] = a[j++];
    for (k = 0; k <= dx - sx; k++) a[sx + k] = b[k];
    delete[] b;
}

void mergeSort(Studente a[], int sx, int dx) {
    if (sx >= dx) return;
    int c = (sx + dx) / 2;
    mergeSort(a, sx, c);
    mergeSort(a, c + 1, dx);
    merge(a, sx, c, dx);
}

int main() {
    // già in ordine alfabetico
    Studente s[] = {{"Anna", 27}, {"Bruno", 30}, {"Carla", 27}, {"Dario", 18},
                    {"Elena", 30}, {"Franco", 24}, {"Gina", 27}};
    mergeSort(s, 0, 6);
    for (int i = 0; i < 7; i++) cout << s[i].voto << "  " << s[i].nome << endl;
    // A parità di voto i nomi restano in ordine alfabetico: Anna, Carla, Gina
    return 0;
}
