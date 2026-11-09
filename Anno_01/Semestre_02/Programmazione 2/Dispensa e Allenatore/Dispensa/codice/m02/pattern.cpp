// Modulo 2 - Pattern: I/O sicuro, namespace, scoping, stringstream
// Compila: g++ -g pattern.cpp -o pattern.exe
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

// ---------- 1. NAMESPACE: un "cognome" per i nomi ----------
namespace geometria {
    const double PI = 3.14159;
    double area(double r) { return PI * r * r; }        // area del cerchio
}
namespace finanza {
    double area(double base, double altezza) {           // stesso nome, nessun conflitto
        return base * altezza;
    }
}

// ---------- 2. SCOPING: globale vs locale ----------
int x = 100;                       // variabile GLOBALE

void demoScope() {
    int x = 5;                     // LOCALE: nasconde (shadowing) la globale
    cout << "x locale = " << x << ", x globale = " << ::x << endl;   // :: = scope globale
    {
        int x = 7;                 // blocco interno: nasconde quella locale
        cout << "x nel blocco = " << x << endl;
    }                              // qui la x=7 "muore"
    cout << "x locale di nuovo = " << x << endl;
}

// ---------- 3. LETTURA SICURA DI UN INTERO ----------
int leggiIntero(string messaggio) {
    int valore;
    while (true) {
        cout << messaggio;
        cin >> valore;
        if (cin.fail()) {                                   // l'utente ha scritto "ciao"
            cerr << "Errore: inserisci un numero intero!" << endl;
            cin.clear();                                    // 1) spengo la spia d'errore
            cin.ignore(numeric_limits<streamsize>::max(), '\n');   // 2) butto la riga sbagliata
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');   // tolgo il '\n' rimasto
            return valore;
        }
    }
}

int main() {
    cout << "Area cerchio r=2: " << geometria::area(2) << endl;
    cout << "Area rettangolo 3x4: " << finanza::area(3, 4) << endl;

    demoScope();

    int eta = leggiIntero("Quanti anni hai? ");

    string nomeCompleto;
    cout << "Nome e cognome: ";
    getline(cin, nomeCompleto);                 // legge anche gli spazi
    cout << "Ciao " << nomeCompleto << ", hai " << eta << " anni" << endl;

    // ---------- 4. STRINGSTREAM: "spezzare" una stringa ----------
    string riga = "Mario 22 1.80";
    stringstream ss(riga);
    string nome; int anni; double altezza;
    ss >> nome >> anni >> altezza;              // come cin, ma legge dalla stringa
    cout << nome << " | " << anni << " | " << altezza << endl;

    // e al contrario: costruire una stringa con <<
    stringstream out;
    out << "Utente-" << anni;
    string codice = out.str();
    cout << "Codice generato: " << codice << endl;
    return 0;
}
