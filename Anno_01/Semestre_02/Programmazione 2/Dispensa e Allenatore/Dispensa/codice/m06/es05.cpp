// Esercizio 6.5 - Ricerca lineare: caso migliore, peggiore, medio
#include <iostream>
using namespace std;

int confronti;

int ricerca(const int v[], int n, int x) {
    for (int i = 0; i < n; i++) {
        confronti++;
        if (v[i] == x) return i;
    }
    return -1;
}

int main() {
    const int N = 1000;
    int v[N];
    for (int i = 0; i < N; i++) v[i] = i * 3;          // 0, 3, 6, ...

    confronti = 0; ricerca(v, N, 0);
    cout << "caso migliore (primo elemento): " << confronti << " confronti" << endl;
    confronti = 0; ricerca(v, N, 3 * (N - 1));
    cout << "caso peggiore (ultimo elemento): " << confronti << " confronti" << endl;
    confronti = 0; ricerca(v, N, 1);
    cout << "caso peggiore (assente): " << confronti << " confronti" << endl;

    long long totale = 0;                                // media su tutti gli elementi presenti
    for (int i = 0; i < N; i++) {
        confronti = 0;
        ricerca(v, N, v[i]);
        totale += confronti;
    }
    cout << "caso medio (elemento presente): " << (double)totale / N << " confronti" << endl;
    // migliore O(1), peggiore O(n), medio circa n/2 -> O(n)
    return 0;
}
