// Esercizio 3.2 - Ordinare tre numeri con scambi per reference
#include <iostream>
using namespace std;

void scambia(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}

// Dopo la chiamata: a <= b <= c. Le variabili del chiamante vengono modificate.
void ordinaTre(int& a, int& b, int& c) {
    if (a > b) scambia(a, b);   // ora a <= b
    if (b > c) scambia(b, c);   // ora c è il massimo
    if (a > b) scambia(a, b);   // sistemo di nuovo i primi due
}

int main() {
    int x = 9, y = 2, z = 5;
    ordinaTre(x, y, z);
    cout << x << " " << y << " " << z << endl;

    int p = 3, q = 3, r = 1;
    ordinaTre(p, q, r);
    cout << p << " " << q << " " << r << endl;
    return 0;
}
