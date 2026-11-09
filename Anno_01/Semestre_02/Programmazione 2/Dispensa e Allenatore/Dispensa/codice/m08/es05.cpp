// Esercizio 8.5 - Contare un carattere in una stringa, ricorsivamente
#include <iostream>
#include <string>
using namespace std;

// Guardo il carattere in posizione i, il resto lo chiedo alla ricorsione
int conta(const string& s, char c, int i) {
    if (i == (int)s.length()) return 0;                // stringa finita
    int questo = (s[i] == c) ? 1 : 0;
    return questo + conta(s, c, i + 1);
}

int main() {
    string frase = "la ricorsione e' una cosa seria";
    cout << "'a' compare " << conta(frase, 'a', 0) << " volte" << endl;
    cout << "'r' compare " << conta(frase, 'r', 0) << " volte" << endl;
    cout << "'z' compare " << conta(frase, 'z', 0) << " volte" << endl;
    return 0;
}
