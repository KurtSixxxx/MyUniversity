// Esercizio 5.9 - Specializzazione: un caso particolare per un tipo
#include <iostream>
using namespace std;

// Versione generale: usa ==
template <typename T>
bool uguali(T a, T b) {
    return a == b;
}

// Specializzazione per double: == sui reali è inaffidabile (0.1 + 0.2 != 0.3)
template <>
bool uguali<double>(double a, double b) {
    double diff = a - b;
    if (diff < 0) diff = -diff;
    return diff < 1e-9;
}

// Specializzazione per stringhe C: == confronterebbe gli INDIRIZZI, non il testo
template <>
bool uguali<const char*>(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && a[i] == b[i]) i++;
    return a[i] == b[i];
}

int main() {
    cout << boolalpha;
    cout << "int:    " << uguali(3, 3) << endl;
    cout << "0.1+0.2 == 0.3 con l'operatore ==: " << (0.1 + 0.2 == 0.3) << endl;
    cout << "double: " << uguali(0.1 + 0.2, 0.3) << endl;
    char s1[] = "ciao", s2[] = "ciao";
    const char* p1 = s1;
    const char* p2 = s2;
    cout << "indirizzi uguali? " << (p1 == p2) << endl;
    cout << "const char*: " << uguali(p1, p2) << endl;
    return 0;
}
