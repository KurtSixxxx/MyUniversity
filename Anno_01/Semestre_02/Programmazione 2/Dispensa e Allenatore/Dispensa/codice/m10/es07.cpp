// Esercizio 10.7 - operator>> che legge uno Studente e segnala gli errori
#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Studente {
    string nome;
    int voto;
public:
    Studente() : nome("?"), voto(0) {}
    friend istream& operator>>(istream& is, Studente& s) {
        string n; int v;
        if (is >> n >> v && v >= 18 && v <= 30) {   // tutto valido: modifico s
            s.nome = n;
            s.voto = v;
        } else {
            is.setstate(ios::failbit);              // altrimenti segnalo il fallimento come cin
        }
        return is;
    }
    friend ostream& operator<<(ostream& os, const Studente& s) { return os << s.nome << " (" << s.voto << ")"; }
};

int main() {
    Studente s;
    int letti = 0;
    while (true) {
        if (cin >> s) {
            cout << "letto " << s << endl;
            letti++;
        } else {
            if (cin.eof()) break;                   // fine input
            cout << "riga non valida, la salto" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << letti << " studenti letti" << endl;
    return 0;
}
