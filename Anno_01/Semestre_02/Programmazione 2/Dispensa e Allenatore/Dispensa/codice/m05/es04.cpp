// Esercizio 5.4 - contare le occorrenze (due parametri template)
#include <iostream>
#include <string>
using namespace std;

template <typename T>
int conta(const T v[], int n, const T& x) {
    int c = 0;
    for (int i = 0; i < n; i++)
        if (v[i] == x) c++;
    return c;
}

// T e U possono essere tipi diversi: confronto un double con un int
template <typename T, typename U>
int contaMaggiori(const T v[], int n, U soglia) {
    int c = 0;
    for (int i = 0; i < n; i++)
        if (v[i] > soglia) c++;
    return c;
}

int main() {
    int voti[] = {28, 30, 18, 30, 25, 30};
    char dna[] = {'A', 'C', 'G', 'A', 'T', 'A'};
    string colori[] = {"rosso", "blu", "rosso", "verde"};
    double temp[] = {18.5, 22.1, 25.0, 19.9};
    cout << "30 compare " << conta(voti, 6, 30) << " volte" << endl;
    cout << "'A' compare " << conta(dna, 6, 'A') << " volte" << endl;
    cout << "rosso compare " << conta(colori, 4, string("rosso")) << " volte" << endl;
    cout << "temperature sopra 20: " << contaMaggiori(temp, 4, 20) << endl;
    return 0;
}
