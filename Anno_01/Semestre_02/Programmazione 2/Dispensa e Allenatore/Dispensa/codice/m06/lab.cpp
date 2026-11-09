// Modulo 6 - Laboratorio a step: segmento di somma massima (dalle slide)
// Compila: g++ -g lab.cpp -o lab.exe
#include <iostream>
#include <cstdlib>
using namespace std;

long long passi = 0;   // ===== STEP 1 ===== il contatore di passi

// ===== STEP 2 =====  Prova TUTTI i segmenti e li somma da capo: O(n^3)
int sommaMassima1(const int S[], int n) {
    int massimo = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            int somma = 0;
            for (int k = i; k <= j; k++) {    // ricalcolo S[i] + ... + S[j]
                somma += S[k];
                passi++;
            }
            if (somma > massimo) massimo = somma;
        }
    return massimo;
}

// ===== STEP 3 =====  Riuso la somma precedente: somma(i..j) = somma(i..j-1) + S[j]: O(n^2)
int sommaMassima2(const int S[], int n) {
    int massimo = 0;
    for (int i = 0; i < n; i++) {
        int somma = 0;
        for (int j = i; j < n; j++) {
            somma += S[j];
            passi++;
            if (somma > massimo) massimo = somma;
        }
    }
    return massimo;
}

// ===== STEP 4 =====  Una sola passata: O(n)
// Se la somma "in corso" diventa negativa, non conviene portarsela dietro: riparto da zero.
int sommaMassima3(const int S[], int n, int& inizio, int& fine) {
    int massimo = 0, somma = 0, partenza = 0;
    inizio = 0; fine = -1;                       // segmento vuoto
    for (int j = 0; j < n; j++) {
        somma += S[j];
        passi++;
        bool migliore = somma > massimo;
        bool piuCorto = somma == massimo && somma > 0 && (j - partenza) < (fine - inizio);
        if (migliore || piuCorto) {              // a parità di somma preferisco il più corto
            massimo = somma;
            inizio = partenza;
            fine = j;
        }
        if (somma < 0) {                         // zavorra: la butto
            somma = 0;
            partenza = j + 1;
        }
    }
    return massimo;
}

// ===== STEP 5 =====  Confronto su array casuali di dimensione crescente
void riempiCasuale(int v[], int n) {
    for (int i = 0; i < n; i++) v[i] = rand() % 21 - 10;    // valori tra -10 e 10
}

int main() {
    // STEP 2-4 sull'esempio piccolo
    int S[] = {2, -6, 3, 5, -2, 4, -9, 1};
    int n = 8, ini, fin;
    passi = 0; int r1 = sommaMassima1(S, n); long long p1 = passi;
    passi = 0; int r2 = sommaMassima2(S, n); long long p2 = passi;
    passi = 0; int r3 = sommaMassima3(S, n, ini, fin); long long p3 = passi;
    cout << "Esempio: somma massima " << r1 << " / " << r2 << " / " << r3
         << "  (segmento S[" << ini << ".." << fin << "])" << endl;
    cout << "Passi: " << p1 << " / " << p2 << " / " << p3 << endl << endl;

    // STEP 5
    srand(111222333);
    cout << "n\tO(n^3)\t\tO(n^2)\t\tO(n)\trisultati uguali?" << endl;
    int dims[] = {10, 100, 1000};
    for (int t = 0; t < 3; t++) {
        int m = dims[t];
        int* v = new int[m];
        riempiCasuale(v, m);
        passi = 0; int a = sommaMassima1(v, m); long long q1 = passi;
        passi = 0; int b = sommaMassima2(v, m); long long q2 = passi;
        passi = 0; int c = sommaMassima3(v, m, ini, fin); long long q3 = passi;
        cout << m << "\t" << q1 << (q1 < 10000000 ? "\t\t" : "\t") << q2
             << (q2 < 10000000 ? "\t\t" : "\t") << q3 << "\t"
             << ((a == b && b == c) ? "si" : "NO") << endl;
        delete[] v;
    }
    return 0;
}
