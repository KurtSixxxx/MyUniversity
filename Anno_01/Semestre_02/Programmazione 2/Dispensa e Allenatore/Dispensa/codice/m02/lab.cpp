// Modulo 2 - Laboratorio a step: registro dei voti
// Compila: g++ -g lab.cpp -o lab.exe
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cstdlib>
using namespace std;

// ===== STEP 2 =====  Tutto ciò che riguarda il registro sta in un namespace
namespace registro {
    const int MAX = 100;
    const int VOTO_MIN = 18;
    const int VOTO_MAX = 30;

    // ===== STEP 1 =====  Lettura sicura di un intero in un intervallo
    int leggiIntero(string messaggio, int min, int max) {
        int x;
        while (true) {
            cout << messaggio;
            cin >> x;
            if (cin.fail()) {                                         // non è un numero
                cerr << "  errore: serve un numero intero" << endl;
                cin.clear();                                          // 1. spengo la spia
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 2. butto la riga
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // tolgo il '\n'
                if (x >= min && x <= max) return x;
                cerr << "  errore: deve essere tra " << min << " e " << max << endl;
            }
        }
    }

    // ===== STEP 3 =====  Una riga "cognome voto" è valida solo se è esattamente così
    bool analizzaRiga(string riga, string& cognome, int& voto) {
        stringstream ss(riga);
        if (!(ss >> cognome >> voto)) return false;   // manca qualcosa o il voto non è un numero
        string avanzo;
        if (ss >> avanzo) return false;               // c'è roba in più
        return voto >= VOTO_MIN && voto <= VOTO_MAX;
    }

    // ===== STEP 4 =====  Statistiche
    double media(const int voti[], int n) {
        if (n == 0) return 0;
        int somma = 0;
        for (int i = 0; i < n; i++) somma += voti[i];
        return (double)somma / n;                     // cast: niente divisione intera
    }

    // ===== STEP 5 =====  Codice studente costruito con uno stringstream: STU-007
    string codice(int numero) {
        stringstream out;
        out << "STU-";
        if (numero < 100) out << "0";
        if (numero < 10) out << "0";
        out << numero;
        return out.str();
    }
}

int main() {
    using namespace registro;     // da qui posso scrivere MAX invece di registro::MAX

    // STEP 1
    int capienza = leggiIntero("Quanti studenti al massimo (1-100)? ", 1, MAX);

    // STEP 3 e 4: lettura delle righe
    string cognomi[MAX];
    int voti[MAX];
    int n = 0, scartate = 0;
    string riga;
    cout << "Inserisci 'cognome voto' (fine per terminare):" << endl;
    while (n < capienza && getline(cin, riga)) {
        if (riga == "fine") break;
        if (riga.empty()) continue;
        string c; int v;
        if (analizzaRiga(riga, c, v)) {
            cognomi[n] = c;
            voti[n] = v;
            n++;
        } else {
            cerr << "  riga scartata: \"" << riga << "\"" << endl;
            scartate++;
        }
    }

    cout << "\nRegistrati " << n << " studenti (scartate " << scartate << " righe)" << endl;
    if (n == 0) return 0;
    int iMax = 0;
    for (int i = 0; i < n; i++) {
        cout << "  " << codice(i + 1) << "  " << cognomi[i] << "  " << voti[i] << endl;
        if (voti[i] > voti[iMax]) iMax = i;
    }
    cout << "Media: " << media(voti, n) << endl;
    cout << "Migliore: " << cognomi[iMax] << endl;

    // STEP 5: estrazione casuale di due interrogati
    int seme = leggiIntero("Seme per l'estrazione: ", 0, 1000000);
    srand(seme);                                   // UNA sola volta
    int primo = rand() % n;                        // indice tra 0 e n-1
    int secondo = primo;
    while (n > 1 && secondo == primo)              // il secondo deve essere diverso
        secondo = rand() % n;
    cout << "Interrogati: " << codice(primo + 1) << " " << cognomi[primo];
    if (n > 1) cout << " e " << codice(secondo + 1) << " " << cognomi[secondo];
    cout << endl;
    return 0;
}
