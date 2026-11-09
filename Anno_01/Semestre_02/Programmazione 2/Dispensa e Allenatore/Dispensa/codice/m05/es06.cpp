// Esercizio 5.6 - ordinamento generico (esercizio delle slide): int, char, Rettangolo per area
#include <iostream>
using namespace std;

template <typename T>
void ordina(T a[], int n) {                 // bubble sort
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j + 1] < a[j]) {          // richiede solo l'operatore <
                T t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
            }
}

template <typename T>
void stampa(const T a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

class Rettangolo {
private:
    double b, h;
public:
    Rettangolo(double b = 1, double h = 1) : b(b), h(h) {}
    double area() const { return b * h; }
    bool operator<(const Rettangolo& r) const { return area() < r.area(); }
    friend ostream& operator<<(ostream& os, const Rettangolo& r) {
        return os << "[" << r.b << "x" << r.h << "=" << r.area() << "]";
    }
};

int main() {
    int vi[] = {42, 7, 19, 3};
    char vc[] = {'q', 'w', 'e', 'r', 't', 'y'};
    Rettangolo vr[] = {Rettangolo(5, 5), Rettangolo(2, 3), Rettangolo(10, 1), Rettangolo(1, 1)};

    cout << "prima:" << endl; stampa(vi, 4); stampa(vc, 6); stampa(vr, 4);
    ordina(vi, 4); ordina(vc, 6); ordina(vr, 4);
    cout << "dopo:" << endl;  stampa(vi, 4); stampa(vc, 6); stampa(vr, 4);
    return 0;
}
