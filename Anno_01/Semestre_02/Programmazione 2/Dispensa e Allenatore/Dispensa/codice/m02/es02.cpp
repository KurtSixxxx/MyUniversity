// Esercizio 2.2 - Calcolatrice "a op b"
#include <iostream>
using namespace std;

int main() {
    double a, b;
    char op;
    // cin >> legge un double, poi un char (saltando gli spazi), poi un double
    while (cin >> a >> op >> b) {
        switch (op) {
            case '+': cout << a << " + " << b << " = " << a + b << endl; break;
            case '-': cout << a << " - " << b << " = " << a - b << endl; break;
            case '*': cout << a << " * " << b << " = " << a * b << endl; break;
            case '/':
                if (b == 0) cerr << "Errore: divisione per zero" << endl;
                else cout << a << " / " << b << " = " << a / b << endl;
                break;
            default:
                cerr << "Operatore sconosciuto: " << op << endl;
        }
    }
    return 0;
}
