// Modulo 3 - Pattern: puntatori, reference, array statici e dinamici
// Compila: g++ -g pattern.cpp -o pattern.exe
#include <iostream>
using namespace std;

// ---------- 1. TRE MODI DI PASSARE UN PARAMETRO ----------
void scambiaValore(int a, int b) {         // riceve FOTOCOPIE: non cambia nulla fuori
    int t = a; a = b; b = t;
}
void scambiaPuntatore(int* a, int* b) {    // riceve INDIRIZZI: lavora sugli originali
    int t = *a; *a = *b; *b = t;
}
void scambiaReference(int& a, int& b) {    // riceve ALIAS: lavora sugli originali
    int t = a; a = b; b = t;
}

// ---------- 2. ARRAY PASSATO A FUNZIONE ----------
// int v[] e int* v sono LA STESSA COSA: la funzione riceve solo l'indirizzo
// del primo elemento, quindi la dimensione va passata a parte.
double media(const int v[], int n) {        // const: la funzione non modifica v
    int somma = 0;
    for (int i = 0; i < n; i++) somma += v[i];
    return (double)somma / n;
}

// ---------- 3. FUNZIONE CHE CREA UN ARRAY DINAMICO ----------
// Restituisce il puntatore all'array nello heap: chi lo riceve deve fare delete[]
int* creaQuadrati(int n) {
    int* a = new int[n];
    for (int i = 0; i < n; i++) a[i] = i * i;
    return a;                               // OK: lo heap sopravvive alla funzione
}

// ---------- 4. MATRICE DINAMICA r x c ----------
int** creaMatrice(int r, int c) {
    int** m = new int*[r];                  // array di r puntatori (le righe)
    for (int i = 0; i < r; i++)
        m[i] = new int[c];                  // ogni riga è un array di c int
    return m;
}
void distruggiMatrice(int** m, int r) {
    for (int i = 0; i < r; i++) delete[] m[i];   // prima le righe...
    delete[] m;                                  // ...poi l'array di puntatori
}

int main() {
    // --- Puntatori: & = "indirizzo di", * = "vai all'indirizzo" ---
    int n = 75;
    int* p = &n;            // p contiene l'indirizzo di n
    *p = 100;               // modifico n passando da p
    cout << "n = " << n << ", *p = " << *p << endl;

    int& r = n;             // r è un altro nome per n
    r = 5;
    cout << "dopo r = 5: n = " << n << endl;

    // --- Passaggio parametri ---
    int x = 1, y = 2;
    scambiaValore(x, y);     cout << "valore:    x=" << x << " y=" << y << endl;
    scambiaPuntatore(&x, &y); cout << "puntatore: x=" << x << " y=" << y << endl;
    scambiaReference(x, y);  cout << "reference: x=" << x << " y=" << y << endl;

    // --- Array statico e aritmetica dei puntatori ---
    int v[5] = {10, 20, 30, 40, 50};
    int* q = v;                              // il nome dell'array = indirizzo di v[0]
    cout << "v[2] = " << v[2] << ", *(q+2) = " << *(q + 2) << endl;
    cout << "sizeof(v) = " << sizeof(v) << " byte, elementi = " << sizeof(v) / sizeof(v[0]) << endl;
    cout << "media = " << media(v, 5) << endl;

    // --- Array dinamico: dimensione decisa a run-time ---
    int dim = 6;
    int* quad = creaQuadrati(dim);
    for (int i = 0; i < dim; i++) cout << quad[i] << " ";
    cout << endl;
    delete[] quad;           // con [] perché è stato creato con new[]
    quad = nullptr;          // niente puntatore pendente (dangling)

    // --- Variabile dinamica singola ---
    double* d = new double(3.14);
    cout << "*d = " << *d << endl;
    delete d;                // senza [] perché creato con new (non new[])
    d = nullptr;

    // --- Matrice dinamica ---
    int R = 2, C = 3;
    int** m = creaMatrice(R, C);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            m[i][j] = i * 10 + j;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) cout << m[i][j] << "\t";
        cout << endl;
    }
    distruggiMatrice(m, R);
    m = nullptr;
    return 0;
}
