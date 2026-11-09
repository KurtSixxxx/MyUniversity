// Modulo 6 - Pattern: CONTARE I PASSI per vedere la complessità
// Compila: g++ -g pattern.cpp -o pattern.exe
#include <iostream>
using namespace std;

long long passi;     // contatore globale: ogni operazione "elementare" fa passi++

void costante(int n) {               // O(1): non dipende da n
    passi++;                         // es. leggere v[0]
    (void)n;
}

void logaritmico(int n) {            // O(log n): i raddoppia a ogni giro
    for (int i = 1; i < n; i *= 2) passi++;
}

void lineare(int n) {                // O(n): un giro per ogni elemento
    for (int i = 0; i < n; i++) passi++;
}

void nlogn(int n) {                  // O(n log n): n volte un ciclo logaritmico
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j *= 2) passi++;
}

void quadratico(int n) {             // O(n^2): due cicli annidati su n
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) passi++;
}

// Esegue f(n), restituisce quanti passi ha fatto
long long conta(void (*f)(int), int n) {   // f è un puntatore a funzione (Modulo 3)
    passi = 0;
    f(n);
    return passi;
}

int main() {
    int dimensioni[] = {10, 100, 1000, 10000};
    cout << "n\tO(1)\tO(logn)\tO(n)\tO(nlogn)\tO(n^2)" << endl;
    for (int k = 0; k < 4; k++) {
        int n = dimensioni[k];
        cout << n << "\t" << conta(costante, n) << "\t" << conta(logaritmico, n)
             << "\t" << conta(lineare, n) << "\t" << conta(nlogn, n)
             << "\t\t" << conta(quadratico, n) << endl;
    }
    return 0;
}
