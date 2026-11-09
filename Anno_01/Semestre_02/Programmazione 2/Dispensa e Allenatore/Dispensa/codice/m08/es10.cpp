// Esercizio 8.10 - Tutte le permutazioni di una stringa (backtracking)
#include <iostream>
#include <string>
using namespace std;

int contatore = 0;

// Le posizioni da 0 a k-1 sono già fissate; provo ogni carattere rimasto in posizione k
void permuta(string& s, int k) {
    if (k == (int)s.length()) {                  // tutte fissate: ho una permutazione
        contatore++;
        cout << s << " ";
        return;
    }
    for (int i = k; i < (int)s.length(); i++) {
        swap(s[k], s[i]);          // scelgo s[i] per la posizione k
        permuta(s, k + 1);         // permuto il resto
        swap(s[k], s[i]);          // TORNO INDIETRO: rimetto a posto (backtracking)
    }
}

int main() {
    string s = "abc";
    permuta(s, 0);
    cout << "\n" << contatore << " permutazioni di abc" << endl;
    contatore = 0;
    string t = "1234";
    permuta(t, 0);
    cout << "\n" << contatore << " permutazioni di 1234 (4! = 24)" << endl;
    return 0;
}
