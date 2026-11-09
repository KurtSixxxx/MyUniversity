// Esercizio 1.8 - Automobile
// Compila: g++ -g es08.cpp -o es08.exe
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Automobile {
private:
    string modello;
    int velocita;         // km/h, mai negativa, mai oltre VEL_MAX
    double carburante;    // litri, tra 0 e SERBATOIO

    static const int VEL_MAX = 180;
    static constexpr double SERBATOIO = 40.0;

public:
    Automobile(string m, double litri) {
        modello = m;
        velocita = 0;
        if (litri < 0) litri = 0;
        if (litri > SERBATOIO) litri = SERBATOIO;
        carburante = litri;
    }

    // Accelera di 'delta' km/h consumando 1 litro ogni 10 km/h
    bool accelera(int delta) {
        if (delta <= 0) return false;
        double consumo = delta / 10.0;
        if (consumo > carburante) return false;           // non basta benzina
        carburante -= consumo;
        velocita += delta;
        if (velocita > VEL_MAX) velocita = VEL_MAX;       // limite fisico
        return true;
    }

    void frena(int delta) {
        if (delta <= 0) return;
        velocita -= delta;
        if (velocita < 0) velocita = 0;
    }

    void fermati() { velocita = 0; }

    double rifornisci(double litri) {                    // restituisce i litri effettivamente messi
        if (litri <= 0) return 0;
        double spazio = SERBATOIO - carburante;
        double messi = (litri < spazio) ? litri : spazio;
        carburante += messi;
        return messi;
    }

    int getVelocita() const { return velocita; }
    double getCarburante() const { return carburante; }
    string getModello() const { return modello; }

    void stampa() const {
        cout << "[" << modello << "] vel=" << velocita
             << " km/h, carburante=" << carburante << " L" << endl;
    }
};

int main() {
    srand(111222333);                       // seed fisso: risultati riproducibili

    const int N = 3;
    Automobile flotta[N] = {
        Automobile("Panda", 5),
        Automobile("Punto", 30),
        Automobile("Tipo", 100)             // verrà limitato a 40 litri
    };

    // 5 accelerazioni casuali (tra 10 e 90 km/h) su ogni auto
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < 5; k++) {
            int delta = 10 + rand() % 81;
            if (!flotta[i].accelera(delta))
                cout << flotta[i].getModello() << ": accelerazione di " << delta << " rifiutata" << endl;
        }
    }

    // Trova l'auto più veloce
    int iMax = 0;
    for (int i = 1; i < N; i++)
        if (flotta[i].getVelocita() > flotta[iMax].getVelocita())
            iMax = i;

    for (int i = 0; i < N; i++) flotta[i].stampa();
    cout << "La piu' veloce e': " << flotta[iMax].getModello() << endl;

    flotta[0].fermati();
    cout << "Messi " << flotta[0].rifornisci(100) << " litri nella Panda" << endl;
    flotta[0].stampa();
    return 0;
}
