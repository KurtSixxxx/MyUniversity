// Esercizio 8.9 - Torre di Hanoi
#include <iostream>
using namespace std;

int mosse = 0;

// Sposta n dischi dal piolo "da" al piolo "a", usando "via" come appoggio
void hanoi(int n, char da, char a, char via, bool stampa) {
    if (n == 0) return;                          // nessun disco: nulla da fare
    hanoi(n - 1, da, via, a, stampa);            // 1. sposto i n-1 dischi sopra, fuori dai piedi
    mosse++;
    if (stampa) cout << "  disco " << n << ": " << da << " -> " << a << endl;   // 2. sposto il disco grande
    hanoi(n - 1, via, a, da, stampa);            // 3. rimetto i n-1 dischi sopra il grande
}

int main() {
    cout << "3 dischi da A a C:" << endl;
    hanoi(3, 'A', 'C', 'B', true);
    cout << "mosse: " << mosse << endl;
    for (int n = 1; n <= 20; n += (n < 5 ? 1 : 5)) {
        mosse = 0;
        hanoi(n, 'A', 'C', 'B', false);
        cout << n << " dischi: " << mosse << " mosse" << endl;   // 2^n - 1
    }
    return 0;
}
