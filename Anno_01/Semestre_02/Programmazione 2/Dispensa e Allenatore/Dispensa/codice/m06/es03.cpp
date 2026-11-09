// Esercizio 6.3 - Ciclo che raddoppia: logaritmo "a occhio"
#include <iostream>
using namespace std;

int main() {
    // Quante volte posso raddoppiare 1 prima di superare n? = quante volte posso dimezzare n
    for (int n = 1; n <= 1000000; n *= 10) {
        int passi = 0;
        for (int i = 1; i < n; i *= 2) passi++;
        cout << "n = " << n << "\tpassi = " << passi << endl;
    }
    // n moltiplicato per 10 -> passi aumentano solo di circa 3 o 4: crescita logaritmica.
    return 0;
}
