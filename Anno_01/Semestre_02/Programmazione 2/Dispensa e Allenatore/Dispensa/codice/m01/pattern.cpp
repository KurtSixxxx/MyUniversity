// Modulo 1 - Pattern: classe con Information Hiding
// Compila: g++ -g pattern.cpp -o pattern.exe
#include <iostream>
#include <string>
using namespace std;

class ContoBancario {
private:                       // ZONA PRIVATA: nessuno da fuori può toccare questi dati
    string intestatario;
    double saldo;

public:                        // INTERFACCIA PUBBLICA: l'unico "sportello" verso l'esterno
    // Costruttore: prepara l'oggetto appena nasce (lo vedremo bene nel Modulo 4)
    ContoBancario(string nome, double saldoIniziale) {
        intestatario = nome;
        // Il controllo sta DENTRO la classe: lo stato resta sempre valido
        saldo = (saldoIniziale >= 0) ? saldoIniziale : 0;
    }

    // Setter "controllato": restituisce false se l'operazione non è valida
    bool deposita(double importo) {
        if (importo <= 0) return false;
        saldo += importo;
        return true;
    }

    bool preleva(double importo) {
        if (importo <= 0 || importo > saldo) return false;   // niente saldo negativo
        saldo -= importo;
        return true;
    }

    // Getter: const = promette di NON modificare l'oggetto
    double getSaldo() const { return saldo; }
    string getIntestatario() const { return intestatario; }

    void stampa() const {
        cout << intestatario << " -> saldo: " << saldo << " euro" << endl;
    }
};

int main() {
    ContoBancario c1("Mario", 100);     // oggetto 1
    ContoBancario c2("Lucia", -50);     // saldo negativo corretto a 0 dal costruttore

    c1.deposita(50);                    // messaggio: destinatario c1, selettore deposita, argomento 50
    if (!c1.preleva(1000))
        cout << "Prelievo rifiutato: saldo insufficiente" << endl;

    // c1.saldo = 1000000;              // ERRORE DI COMPILAZIONE: 'saldo' è private

    c1.stampa();
    c2.stampa();
    return 0;
}
