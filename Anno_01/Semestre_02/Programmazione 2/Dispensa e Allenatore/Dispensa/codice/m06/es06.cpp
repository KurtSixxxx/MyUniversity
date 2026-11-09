// Esercizio 6.6 - L'esempio delle slide: tre cicli, solo uno lineare
#include <iostream>
using namespace std;

long long func(int n) {
    long long count = 0;
    for (int i = n / 2; i <= n; i++)          // circa n/2 giri         -> O(n)
        for (int j = 1; j <= n; j = 2 * j)    // raddoppia              -> O(log n)
            for (int k = 1; k <= n; k = k * 2) // raddoppia             -> O(log n)
                count++;
    return count;
}

int main() {
    for (int n = 16; n <= 65536; n *= 16) {
        int lg = 0;
        for (int x = 1; x <= n; x *= 2) lg++;          // giri di un ciclo che raddoppia
        long long c = func(n);
        cout << "n = " << n << "\tcount = " << c
             << "\t(n/2+1) * lg * lg = " << (long long)(n / 2 + 1) * lg * lg << endl;
    }
    // Il prodotto dei tre fattori torna esatto: complessità O(n * log n * log n)
    return 0;
}
