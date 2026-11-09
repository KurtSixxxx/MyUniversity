// Esercizio 6.8 - Numeri primi: provare tutti i divisori o solo fino alla radice?
#include <iostream>
using namespace std;

long long divisioni;

bool primoLento(int n) {                  // prova d = 2, 3, ..., n-1   -> O(n)
    if (n < 2) return false;
    for (int d = 2; d < n; d++) {
        divisioni++;
        if (n % d == 0) return false;
    }
    return true;
}

bool primoVeloce(int n) {                 // prova solo finché d*d <= n  -> O(radice di n)
    if (n < 2) return false;
    for (int d = 2; d * d <= n; d++) {    // se n = a*b, uno dei due è <= radice di n
        divisioni++;
        if (n % d == 0) return false;
    }
    return true;
}

int main() {
    int numeri[] = {97, 9973, 999983};    // tutti primi: il caso PEGGIORE
    for (int t = 0; t < 3; t++) {
        int n = numeri[t];
        divisioni = 0; bool a = primoLento(n);  long long dl = divisioni;
        divisioni = 0; bool b = primoVeloce(n); long long dv = divisioni;
        cout << n << (a && b ? " primo" : " non primo") << "\tlento: " << dl
             << "\tveloce: " << dv << endl;
    }
    int quanti = 0;
    for (int n = 2; n <= 100000; n++) if (primoVeloce(n)) quanti++;
    cout << "Primi fino a 100000: " << quanti << endl;
    return 0;
}
