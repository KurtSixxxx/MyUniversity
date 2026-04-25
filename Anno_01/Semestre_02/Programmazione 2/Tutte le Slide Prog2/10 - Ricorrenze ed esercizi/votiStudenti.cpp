#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//#include <limits>

using namespace std;

// Costante: massimo numero di voti che possiamo gestire per studente
const int MAX_VOTI = 100;
const int MAX_STUDENTI = 100;

// Struct con array statico
struct Studente {
    string nome;
    int voti[MAX_VOTI];
    int numVoti;
    float media;
    int votoMin;
    int votoMax;
    bool promosso;
};

// Calcola la media dei voti
float calcolaMedia(const int voti[], int n) {
    int somma = 0;
    for (int i = 0; i < n; i++) {
        somma += voti[i];
    }
    return n > 0 ? static_cast<float>(somma) / n : 0;
}

// Trova il voto massimo
int trovaMassimo(const int voti[], int n) {
    //int _max = numeric_limits<int>::min();
    int _max = -1;
    for (int i = 0; i < n; i++) {
        if (voti[i] > _max) _max = voti[i];
    }
    return _max;
}

// Trova il voto minimo
int trovaMinimo(const int voti[], int n) {
    //int min = numeric_limits<int>::max();
    int _min = 1000;
    for (int i = 0; i < n; i++) {
        if (voti[i] < _min) _min = voti[i];
    }
    return _min;
}

// Verifica se promosso
bool isPromosso(float media) {
    return media >= 18.0;
}

// Legge studenti da file con massimo MAX_STUDENTI
int leggiStudenti(const string& filename, Studente studenti[]) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Errore nell'apertura del file: " << filename << endl;
        return 0;
    }

    string riga;
    int count = 0;
    int promossi = 0;
    int bocciati = 0;
    while (getline(inputFile, riga) && count < MAX_STUDENTI) {
        stringstream ss(riga);
        Studente s;
        ss >> s.nome;

        s.numVoti = 0;
        int voto;
        while (ss >> voto && s.numVoti < MAX_VOTI) {
            s.voti[s.numVoti++] = voto;
        }

        // Calcolo dei dati derivati
        s.media = calcolaMedia(s.voti, s.numVoti);
        s.votoMin = trovaMinimo(s.voti, s.numVoti);
        s.votoMax = trovaMassimo(s.voti, s.numVoti);
        s.promosso = isPromosso(s.media);
        // conto i promossi ed i bocciati
        (s.promosso ? promossi++ : bocciati++);

        studenti[count++] = s;
    }

    cout << "Promossi:\t" << promossi << "/" << (count)
         << "\tBocciati:\t" << bocciati << "/" << (count) << endl;
    inputFile.close();
    return count; // restituisce il numero di studenti letti
}

// Scrittura su file
void scriviReport(const string& filename, const Studente studenti[], int n) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Errore nella scrittura del file: " << filename << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        outputFile << studenti[i].nome << " "
                   << studenti[i].media << " "
                   << studenti[i].votoMin << " "
                   << studenti[i].votoMax << " "
                   << (studenti[i].promosso ? "PROMOSSO" : "BOCCIATO") << endl;
    }

    outputFile.close();
}

int main() {
    Studente studenti[MAX_STUDENTI];
    int numeroStudenti = leggiStudenti("voti.txt", studenti);
    scriviReport("report.txt", studenti, numeroStudenti);
    cout << "Analisi completata. Report salvato in 'report.txt'." << endl;
    return 0;
}
