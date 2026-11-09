// Modulo 7 - Pattern: i 5 algoritmi di ordinamento + ricerca binaria
// Compila: g++ -g pattern.cpp -o pattern.exe
#include <iostream>
using namespace std;

void scambia(int& a, int& b) { int t = a; a = b; b = t; }

// BUBBLE SORT: confronta coppie vicine; ogni passata porta il massimo in fondo
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool scambiato = false;
        for (int j = 0; j < n - 1 - i; j++)          // gli ultimi i sono già a posto
            if (a[j] > a[j + 1]) { scambia(a[j], a[j + 1]); scambiato = true; }
        if (!scambiato) break;                        // nessuno scambio: è già ordinato
    }
}

// SELECTION SORT: cerca il minimo del resto e lo mette in posizione i
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int iMin = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[iMin]) iMin = j;
        scambia(a[i], a[iMin]);
    }
}

// INSERTION SORT: come le carte in mano; inserisce a[i] al suo posto tra i precedenti
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int x = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > x) {      // sposto a destra i più grandi di x
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;                     // e metto x nel buco
    }
}

// MERGE SORT: divide a metà, ordina le metà, le fonde
void merge(int a[], int sx, int centro, int dx) {
    int* b = new int[dx - sx + 1];        // array di appoggio
    int i = sx, j = centro + 1, k = 0;
    while (i <= centro && j <= dx)
        b[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i <= centro) b[k++] = a[i++];
    while (j <= dx) b[k++] = a[j++];
    for (k = 0; k < dx - sx + 1; k++) a[sx + k] = b[k];   // ricopio in a
    delete[] b;
}
void mergeSort(int a[], int sx, int dx) {
    if (sx >= dx) return;                 // caso base: 0 o 1 elemento
    int centro = (sx + dx) / 2;
    mergeSort(a, sx, centro);
    mergeSort(a, centro + 1, dx);
    merge(a, sx, centro, dx);
}

// QUICK SORT (versione delle slide): pivot centrale, due indici che si vengono incontro
void quickSort(int a[], int sx, int dx) {
    int i = sx, j = dx;
    int pivot = a[(sx + dx) / 2];
    while (i <= j) {
        while (a[i] < pivot) i++;         // da sinistra: primo elemento "fuori posto"
        while (a[j] > pivot) j--;         // da destra: primo elemento "fuori posto"
        if (i <= j) { scambia(a[i], a[j]); i++; j--; }
    }
    if (sx < j) quickSort(a, sx, j);      // parte sinistra (tutti <= pivot)
    if (i < dx) quickSort(a, i, dx);      // parte destra (tutti >= pivot)
}

// RICERCA BINARIA (solo su array ORDINATO)
int ricercaBinaria(const int a[], int n, int x) {
    int sx = 0, dx = n - 1;
    while (sx <= dx) {
        int m = (sx + dx) / 2;
        if (a[m] == x) return m;
        if (a[m] < x) sx = m + 1; else dx = m - 1;
    }
    return -1;
}

void stampa(const char* nome, const int a[], int n) {
    cout << nome;
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    const int N = 8;
    int base[N] = {38, 27, 43, 3, 9, 82, 10, 27};
    int v[N];
    void (*algoritmi[3])(int[], int) = {bubbleSort, selectionSort, insertionSort};
    const char* nomi[3] = {"bubble:    ", "selection: ", "insertion: "};
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < N; i++) v[i] = base[i];
        algoritmi[k](v, N);
        stampa(nomi[k], v, N);
    }
    for (int i = 0; i < N; i++) v[i] = base[i];
    mergeSort(v, 0, N - 1);  stampa("merge:     ", v, N);
    for (int i = 0; i < N; i++) v[i] = base[i];
    quickSort(v, 0, N - 1);  stampa("quick:     ", v, N);

    cout << "43 in posizione " << ricercaBinaria(v, N, 43)
         << ", 50 in posizione " << ricercaBinaria(v, N, 50) << endl;
    return 0;
}
