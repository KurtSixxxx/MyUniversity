// Modulo 7 - Laboratorio a step: prestazioni degli algoritmi di ordinamento (dalle slide)
// Compila: g++ -O2 lab.cpp -o lab.exe
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

long long confronti = 0;                 // contatore globale

// ===== STEP 1 =====  Strumenti: array casuale, copia, verifica
void generaArrayCasuale(int* a, int num) {
    for (int i = 0; i < num; i++) a[i] = rand();   // 0 .. RAND_MAX (32767 con MinGW)
}
void copia(const int* da, int* a, int n) { for (int i = 0; i < n; i++) a[i] = da[i]; }
bool ordinato(const int* a, int n) {
    for (int i = 1; i < n; i++) if (a[i - 1] > a[i]) return false;
    return true;
}
void scambia(int& a, int& b) { int t = a; a = b; b = t; }

// ===== STEP 2 =====  Gli algoritmi quadratici (con contatore)
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool scambiato = false;
        for (int j = 0; j < n - 1 - i; j++) {
            confronti++;
            if (a[j] > a[j + 1]) { scambia(a[j], a[j + 1]); scambiato = true; }
        }
        if (!scambiato) break;
    }
}
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int x = a[i], j = i - 1;
        while (j >= 0 && (confronti++, a[j] > x)) { a[j + 1] = a[j]; j--; }
        a[j + 1] = x;
    }
}

// ===== STEP 3 =====  Merge sort
void merge(int a[], int sx, int c, int dx, int* b) {    // b: appoggio allocato UNA volta
    int i = sx, j = c + 1, k = sx;
    while (i <= c && j <= dx) {
        confronti++;
        b[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    }
    while (i <= c) b[k++] = a[i++];
    while (j <= dx) b[k++] = a[j++];
    for (k = sx; k <= dx; k++) a[k] = b[k];
}
void mergeSort(int a[], int sx, int dx, int* b) {
    if (sx >= dx) return;
    int c = (sx + dx) / 2;
    mergeSort(a, sx, c, b);
    mergeSort(a, c + 1, dx, b);
    merge(a, sx, c, dx, b);
}
void mergeSort(int a[], int n) {                        // "involucro" comodo
    int* b = new int[n];
    mergeSort(a, 0, n - 1, b);
    delete[] b;
}

// ===== STEP 4 =====  Quick sort (pivot centrale, come nelle slide)
void quickSort(int a[], int sx, int dx) {
    int i = sx, j = dx, pivot = a[(sx + dx) / 2];
    while (i <= j) {
        while (confronti++, a[i] < pivot) i++;
        while (confronti++, a[j] > pivot) j--;
        if (i <= j) { scambia(a[i], a[j]); i++; j--; }
    }
    if (sx < j) quickSort(a, sx, j);
    if (i < dx) quickSort(a, i, dx);
}
void quickSort(int a[], int n) { quickSort(a, 0, n - 1); }

// ===== STEP 5 =====  Misura: confronti e millisecondi
void misura(const char* nome, void (*ordina)(int[], int), const int* orig, int n) {
    int* v = new int[n];
    copia(orig, v, n);
    confronti = 0;
    auto t1 = high_resolution_clock::now();
    ordina(v, n);
    auto t2 = high_resolution_clock::now();
    duration<double, milli> ms = t2 - t1;
    cout << "  " << nome << "  confronti: " << setw(10) << confronti      // setw: colonna larga 10
         << "   tempo: " << setw(9) << fixed << setprecision(3) << ms.count() << " ms"
         << (ordinato(v, n) ? "" : "  ERRORE: non ordinato!") << endl;
    delete[] v;
}

int main() {
    srand(111222333);
    for (int n = 100; n <= 100000; n *= 10) {
        int* orig = new int[n];
        generaArrayCasuale(orig, n);
        cout << "n = " << n << endl;
        if (n <= 10000) {                                // i quadratici oltre diventano lenti
            misura("bubble   ", bubbleSort, orig, n);
            misura("insertion", insertionSort, orig, n);
        }
        misura("merge    ", mergeSort, orig, n);
        misura("quick    ", quickSort, orig, n);
        delete[] orig;
    }
    return 0;
}
