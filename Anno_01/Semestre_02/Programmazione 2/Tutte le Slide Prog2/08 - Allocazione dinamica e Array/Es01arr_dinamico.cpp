/*
Esercizio 1 bis: Scrivere un programma che sfrutta un metodo ‘leggiElementi()’
per inizializzare un array di double di dimensione non nota, chiedendo
all’utente di inserire un valore per volta fino a quando non viene inserito
il valore zero.
Successivamente, stampare gli elementi mediante un altro metodo ‘stampaElementi()’

IN QUESTO CASO USO GLI ARRAY DINAMICI:
- Allocazione dinamica: L'array cresce solo quando necessario, riducendo lo spreco di memoria.
- Espansione automatica: Quando lo spazio è insufficiente, il programma alloca un array più grande (+5 elementi).
- Gestione della memoria: Viene usato delete[] per liberare la memoria allocata.

*/


#include <iostream>
using namespace std;

void leggiElementi(double*& v, int& num, int& capacita) {
    cout << "Inserisci gli elementi uno per volta, quando hai finito inserisci 0." << endl;

    num = 0;  // Numero di elementi effettivi
    capacita = 5;  // Dimensione iniziale dell'array
    v = new double[capacita];  // Allocazione iniziale

    double valore;
    while (true) {
        cout << "Elemento da inserire:\t";
        cin >> valore;

        if (valore == 0) break;  // Terminazione input

        if (num == capacita) {
            // Espandere l'array di 5 elementi
            capacita += 5;
            double* nuovoArray = new double[capacita];

            // Copia dei vecchi valori nel nuovo array
            for (int i = 0; i < num; i++) {
                nuovoArray[i] = v[i];
            }

            delete[] v;  // Libera la vecchia memoria
            v = nuovoArray;
        }

        v[num] = valore;
        num++;
    }
}

void stampaElementi(double* v, int num) {
    for (int i = 0; i < num; i++)
        cout << "v[" << i << "]:\t" << v[i] << endl;
}

int main() {
    double* vettore = nullptr;
    int n, capacita;

    leggiElementi(vettore, n, capacita);
    cout << "Il vettore contiene " << n << " elementi, che sono:" << endl;
    stampaElementi(vettore, n);

    delete[] vettore;  // Deallocazione della memoria
    return 0;
}
