// Esercizio 7.3 - Insertion sort su stringhe (ordine alfabetico)
#include <iostream>
#include <string>
using namespace std;

void insertionSort(string a[], int n) {
    for (int i = 1; i < n; i++) {
        string x = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > x) {      // per le string, > è l'ordine alfabetico
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

int main() {
    string nomi[] = {"Rossi", "Bianchi", "Verdi", "Neri", "Esposito", "bianchi"};
    insertionSort(nomi, 6);
    for (int i = 0; i < 6; i++) cout << nomi[i] << endl;
    // "bianchi" minuscolo finisce in fondo: le minuscole vengono DOPO le maiuscole (codici ASCII)
    return 0;
}
