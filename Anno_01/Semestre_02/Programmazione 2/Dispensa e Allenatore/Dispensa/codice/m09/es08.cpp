// Esercizio 9.8 - Gerarchia di eccezioni e ordine dei catch (dalle slide)
#include <iostream>
#include <exception>
#include <string>
using namespace std;

class ErroreBanca : public exception {               // eccezione "madre" del programma
public:
    const char* what() const noexcept override { return "errore bancario generico"; }
};
class SaldoInsufficiente : public ErroreBanca {       // eccezione più specifica
    string msg;
public:
    SaldoInsufficiente(double mancano) : msg("saldo insufficiente, mancano " + to_string((int)mancano) + " euro") {}
    const char* what() const noexcept override { return msg.c_str(); }
};
class ContoBloccato : public ErroreBanca {
public:
    const char* what() const noexcept override { return "conto bloccato"; }
};

void preleva(double saldo, double importo, bool bloccato) {
    if (bloccato) throw ContoBloccato();
    if (importo > saldo) throw SaldoInsufficiente(importo - saldo);
    cout << "prelievo di " << importo << " eseguito" << endl;
}

int main() {
    double prove[3][3] = {{100, 50, 0}, {100, 250, 0}, {100, 10, 1}};
    for (int k = 0; k < 3; k++) {
        try {
            preleva(prove[k][0], prove[k][1], prove[k][2] != 0);
        } catch (const SaldoInsufficiente& e) {       // le PIU' SPECIFICHE per prime
            cout << "[SaldoInsufficiente] " << e.what() << endl;
        } catch (const ErroreBanca& e) {              // poi quelle più generali
            cout << "[ErroreBanca] " << e.what() << endl;
        } catch (const exception& e) {                // infine la madre di tutte
            cout << "[exception] " << e.what() << endl;
        }
    }
    // Se catch(const ErroreBanca&) fosse PRIMO, catturerebbe anche SaldoInsufficiente
    // e il catch specifico non verrebbe mai raggiunto (il compilatore avvisa).
    return 0;
}
