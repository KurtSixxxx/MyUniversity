// Esercizio 3.9 - Trasposta di una matrice dinamica
#include <iostream>
using namespace std;

int** crea(int r, int c) {
    int** m = new int*[r];
    for (int i = 0; i < r; i++) m[i] = new int[c];
    return m;
}

void distruggi(int**& m, int r) {
    for (int i = 0; i < r; i++) delete[] m[i];
    delete[] m;
    m = nullptr;
}

// La trasposta di una matrice r x c è una matrice c x r: t[j][i] = m[i][j]
int** trasposta(int** m, int r, int c) {
    int** t = crea(c, r);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            t[j][i] = m[i][j];
    return t;
}

void stampa(int** m, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << m[i][j] << "\t";
        cout << endl;
    }
}

int main() {
    int R = 2, C = 3;
    int** m = crea(R, C);
    int k = 1;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            m[i][j] = k++;
    cout << "Originale " << R << "x" << C << ":" << endl;
    stampa(m, R, C);

    int** t = trasposta(m, R, C);
    cout << "Trasposta " << C << "x" << R << ":" << endl;
    stampa(t, C, R);

    distruggi(m, R);     // m ha R righe
    distruggi(t, C);     // t ha C righe: attenzione a non sbagliare!
    return 0;
}
