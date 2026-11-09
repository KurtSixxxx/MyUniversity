// Modulo 3 - Laboratorio a step: stazione meteo
// Compila: g++ -g lab.cpp -o lab.exe
#include <iostream>
#include <cstdlib>
using namespace std;

// ===== STEP 1 =====  Più risultati con i parametri reference
void minMax(const double* v, int n, double& mn, double& mx) {
    mn = mx = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < mn) mn = v[i];
        if (v[i] > mx) mx = v[i];
    }
}

// ===== STEP 2 =====  Array dinamico che raddoppia quando è pieno
void aggiungi(double*& v, int& n, int& cap, double x) {
    if (n == cap) {
        cap = (cap == 0) ? 2 : cap * 2;
        double* nuovo = new double[cap];       // 1. blocco più grande
        for (int i = 0; i < n; i++)            // 2. copia
            nuovo[i] = v[i];
        delete[] v;                            // 3. libero il vecchio
        v = nuovo;                             // 4. sposto il puntatore (per questo double*&)
    }
    v[n++] = x;
}

double* leggiMisure(int& n) {
    double* v = nullptr;
    int cap = 0;
    n = 0;
    double x;
    while (cin >> x && x != 0)
        aggiungi(v, n, cap, x);
    cout << "(capacita' finale " << cap << " per " << n << " misure)" << endl;
    return v;
}

// ===== STEP 3 =====  Nuovo array di dimensione ESATTA: prima conto, poi copio
double* sopraSoglia(const double* v, int n, double soglia, int& m) {
    m = 0;
    for (int i = 0; i < n; i++) if (v[i] > soglia) m++;
    if (m == 0) return nullptr;
    double* r = new double[m];
    int k = 0;
    for (int i = 0; i < n; i++) if (v[i] > soglia) r[k++] = v[i];
    return r;
}

// ===== STEP 4 =====  Matrice dinamica giorni x ore
int** creaMatrice(int r, int c) {
    int** m = new int*[r];
    for (int i = 0; i < r; i++) m[i] = new int[c];
    return m;
}

double* medieRighe(int** m, int r, int c) {
    double* medie = new double[r];
    for (int i = 0; i < r; i++) {
        int somma = 0;
        for (int j = 0; j < c; j++) somma += m[i][j];
        medie[i] = (double)somma / c;
    }
    return medie;
}

// ===== STEP 5 =====  Liberare e azzerare: il puntatore passa per reference
void distruggiMatrice(int**& m, int r) {
    for (int i = 0; i < r; i++) delete[] m[i];
    delete[] m;
    m = nullptr;                               // il chiamante non resta con un dangling pointer
}

void stampa(const double* v, int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << "]" << endl;
}

int main() {
    // STEP 1: su un array statico
    double prova[5] = {12.5, 9, 21.3, 17, 4.2};
    double mn, mx;
    minMax(prova, 5, mn, mx);
    cout << "STEP 1  min = " << mn << ", max = " << mx << endl;

    // STEP 2: misure lette da tastiera fino a 0
    int n;
    cout << "STEP 2  Inserisci le temperature (0 per finire):" << endl;
    double* misure = leggiMisure(n);
    if (n == 0) return 0;
    stampa(misure, n);
    minMax(misure, n, mn, mx);
    double soglia = (mn + mx) / 2;

    // STEP 3
    int m;
    double* calde = sopraSoglia(misure, n, soglia, m);
    cout << "STEP 3  sopra " << soglia << " (" << m << "): ";
    stampa(calde, m);

    // STEP 4: 3 giorni x 4 rilevazioni casuali tra 10 e 30
    srand(111222333);
    const int G = 3, H = 4;
    int** tab = creaMatrice(G, H);
    for (int i = 0; i < G; i++)
        for (int j = 0; j < H; j++)
            tab[i][j] = 10 + rand() % 21;
    cout << "STEP 4" << endl;
    for (int i = 0; i < G; i++) {
        cout << "  giorno " << i + 1 << ":";
        for (int j = 0; j < H; j++) cout << " " << tab[i][j];
        cout << endl;
    }
    double* medie = medieRighe(tab, G, H);
    cout << "  medie: ";
    stampa(medie, G);

    // STEP 5: ogni new ha il suo delete
    delete[] misure;
    delete[] calde;          // se è nullptr, delete[] non fa nulla
    delete[] medie;
    distruggiMatrice(tab, G);
    cout << "STEP 5  memoria liberata, tab = " << (tab == nullptr ? "nullptr" : "???") << endl;
    return 0;
}
