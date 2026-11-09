// Esercizio 7.1 - Bubble sort con uscita anticipata: quante passate?
#include <iostream>
using namespace std;

int bubbleSort(int a[], int n) {          // restituisce il numero di passate fatte
    int passate = 0;
    for (int i = 0; i < n - 1; i++) {
        passate++;
        bool scambiato = false;
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
                scambiato = true;
            }
        if (!scambiato) break;            // passata senza scambi: ho finito
    }
    return passate;
}

int main() {
    int ordinato[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int quasi[]    = {1, 2, 3, 5, 4, 6, 7, 8};
    int inverso[]  = {8, 7, 6, 5, 4, 3, 2, 1};
    cout << "gia' ordinato: " << bubbleSort(ordinato, 8) << " passate (caso migliore, O(n))" << endl;
    cout << "quasi ordinato: " << bubbleSort(quasi, 8) << " passate" << endl;
    cout << "al contrario:  " << bubbleSort(inverso, 8) << " passate (caso peggiore, O(n^2))" << endl;
    return 0;
}
