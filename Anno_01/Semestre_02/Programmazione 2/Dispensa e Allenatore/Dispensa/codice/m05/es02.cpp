// Esercizio 5.2 - scambia generico e ruota tre valori
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void scambia(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

// a <- b <- c <- a  (rotazione a sinistra), usando scambia due volte
template <typename T>
void ruota(T& a, T& b, T& c) {
    scambia(a, b);       // ora a = b_vecchio, b = a_vecchio
    scambia(b, c);       // ora b = c_vecchio, c = a_vecchio
}

int main() {
    int i = 1, j = 2, k = 3;
    ruota(i, j, k);
    cout << i << " " << j << " " << k << endl;
    string a = "rosso", b = "verde", c = "blu";
    ruota(a, b, c);
    cout << a << " " << b << " " << c << endl;
    double x = 1.5, y = -1.5;
    scambia(x, y);
    cout << x << " " << y << endl;
    return 0;
}
