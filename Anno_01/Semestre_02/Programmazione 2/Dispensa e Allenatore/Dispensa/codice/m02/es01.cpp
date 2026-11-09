// Esercizio 2.1 - Saluto: getline dopo cin >>
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    int eta;
    string nome;

    cout << "Quanti anni hai? ";
    cin >> eta;
    // Senza questa riga il '\n' rimasto nel buffer verrebbe letto dalla getline,
    // che restituirebbe subito una stringa vuota.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Come ti chiami (nome e cognome)? ";
    getline(cin, nome);

    cout << "Ciao " << nome << "! Tra 10 anni avrai " << eta + 10 << " anni." << endl;
    return 0;
}
