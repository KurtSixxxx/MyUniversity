// Esercizio 1.9 - Bonifico tra conti (oggetti che si mandano messaggi)
#include <iostream>
#include <string>
using namespace std;

class ContoBancario {
private:
    string intestatario;
    double saldo;

public:
    ContoBancario(string nome, double s) {
        intestatario = nome;
        saldo = (s >= 0) ? s : 0;
    }
    bool deposita(double x) {
        if (x <= 0) return false;
        saldo += x;
        return true;
    }
    bool preleva(double x) {
        if (x <= 0 || x > saldo) return false;
        saldo -= x;
        return true;
    }
    // Un conto manda messaggi a UN ALTRO conto.
    // 'dest' è passato per reference (&): così modifichiamo l'originale, non una copia.
    bool bonifico(ContoBancario& dest, double x) {
        if (&dest == this) return false;      // bonifico a se stessi: vietato
        if (!preleva(x)) return false;        // prima tolgo da me...
        dest.deposita(x);                     // ...poi do all'altro
        return true;
    }
    void stampa() const {
        cout << "  " << intestatario << ": " << saldo << " euro" << endl;
    }
};

int main() {
    ContoBancario a("Anna", 500), b("Bruno", 100);
    cout << "Bonifico 200 da Anna a Bruno: " << (a.bonifico(b, 200) ? "ok" : "rifiutato") << endl;
    cout << "Bonifico 1000 da Bruno ad Anna: " << (b.bonifico(a, 1000) ? "ok" : "rifiutato") << endl;
    cout << "Bonifico 50 da Anna ad Anna: " << (a.bonifico(a, 50) ? "ok" : "rifiutato") << endl;
    a.stampa();
    b.stampa();
    return 0;
}
