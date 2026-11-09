// Esercizio 7.8 - Counting sort: ordinare voti 18-30 SENZA confronti, in O(n + k)
#include <iostream>
#include <cstdlib>
using namespace std;

void countingSort(int a[], int n, int minimo, int massimo) {
    int k = massimo - minimo + 1;
    int* conta = new int[k];
    for (int i = 0; i < k; i++) conta[i] = 0;
    for (int i = 0; i < n; i++) conta[a[i] - minimo]++;      // 1. conto le occorrenze
    int pos = 0;
    for (int v = 0; v < k; v++)                              // 2. riscrivo in ordine
        for (int c = 0; c < conta[v]; c++) a[pos++] = v + minimo;
    delete[] conta;
}

int main() {
    srand(111222333);
    const int N = 20;
    int voti[N];
    for (int i = 0; i < N; i++) voti[i] = 18 + rand() % 13;  // 18..30
    countingSort(voti, N, 18, 30);
    for (int i = 0; i < N; i++) cout << voti[i] << " ";
    cout << endl;
    return 0;
}
