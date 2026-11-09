// Esercizio 2.8 - Istogramma di 6000 lanci di un dado
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    srand(111222333);                   // seme fisso: stessi risultati a ogni esecuzione
    const int LANCI = 6000;
    int frequenza[7] = {0};             // uso gli indici 1..6, lo 0 resta inutilizzato

    for (int i = 0; i < LANCI; i++) {
        int faccia = 1 + rand() % 6;    // intervallo [1, 6]
        frequenza[faccia]++;
    }

    for (int f = 1; f <= 6; f++) {
        cout << f << ": " << frequenza[f] << "\t";
        for (int s = 0; s < frequenza[f] / 50; s++) cout << '*';   // un * ogni 50 lanci
        cout << endl;
    }
    return 0;
}
