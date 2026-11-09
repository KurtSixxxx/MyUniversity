// Esercizio 14.1 - Matrice di adiacenza: gradi, adiacenza, grafo completo
#include <iostream>
using namespace std;

const int N = 5;

int grado(bool m[N][N], int u) {             // somma della riga u
    int g = 0;
    for (int j = 0; j < N; j++) if (m[u][j]) g++;
    return g;
}
int numeroArchi(bool m[N][N]) {              // ogni arco compare due volte (m[i][j] e m[j][i])
    int tot = 0;
    for (int i = 0; i < N; i++) tot += grado(m, i);
    return tot / 2;
}
bool completo(bool m[N][N]) {                // ogni coppia di vertici DISTINTI è adiacente
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j && !m[i][j]) return false;
    return true;
}

int main() {
    bool m[N][N] = {};                       // tutto a false
    int archi[][2] = {{0,1}, {0,2}, {1,2}, {2,3}, {3,4}};
    for (int k = 0; k < 5; k++) {
        m[archi[k][0]][archi[k][1]] = true;
        m[archi[k][1]][archi[k][0]] = true;  // non orientato: simmetrica
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << m[i][j] << " ";
        cout << "   grado(" << i << ") = " << grado(m, i) << endl;
    }
    cout << "Archi: " << numeroArchi(m) << endl;
    cout << "0 e 2 adiacenti? " << (m[0][2] ? "si" : "no") << endl;
    cout << "0 e 4 adiacenti? " << (m[0][4] ? "si" : "no") << endl;
    cout << "Completo? " << (completo(m) ? "si" : "no") << endl;

    for (int i = 0; i < N; i++)              // aggiungo tutti gli archi mancanti
        for (int j = 0; j < N; j++)
            if (i != j) m[i][j] = true;
    cout << "Dopo aver aggiunto tutti gli archi: completo? " << (completo(m) ? "si" : "no")
         << ", archi = " << numeroArchi(m) << " (= 5*4/2)" << endl;
    return 0;
}
