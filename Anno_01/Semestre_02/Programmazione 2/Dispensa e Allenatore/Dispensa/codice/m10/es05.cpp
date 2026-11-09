// Esercizio 10.5 - Basta definire < per poter ordinare con un template
#include <iostream>
using namespace std;

class Frazione {
    int num, den;               // den > 0
public:
    Frazione(int n = 0, int d = 1) : num(d < 0 ? -n : n), den(d < 0 ? -d : d) {}
    bool operator<(const Frazione& f) const { return num * f.den < f.num * den; }
    friend ostream& operator<<(ostream& os, const Frazione& f) { return os << f.num << "/" << f.den; }
};

template <typename T>
void ordina(T a[], int n) {                      // insertion sort: usa SOLO <
    for (int i = 1; i < n; i++) {
        T x = a[i];
        int j = i - 1;
        while (j >= 0 && x < a[j]) { a[j + 1] = a[j]; j--; }
        a[j + 1] = x;
    }
}

int main() {
    Frazione v[] = {Frazione(3, 4), Frazione(1, 3), Frazione(5, -6), Frazione(2, 5), Frazione(7, 8)};
    ordina(v, 5);
    for (int i = 0; i < 5; i++) cout << v[i] << " ";
    cout << endl;
    return 0;
}
