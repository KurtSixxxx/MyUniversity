//Metodo Montecarlo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int N;          // numero di campionamenti
    int M = 0;      // punti dentro il cerchio

    printf("Inserisci il numero di campionamenti: ");
    scanf("%d", &N);

    srand(time(0)); // inizializza seme

    for (int i = 0; i < N; i++) {
        // genera x,y in [-1,1]
        double x = -1.0 + 2.0 * rand() / (double)RAND_MAX;
        double y = -1.0 + 2.0 * rand() / (double)RAND_MAX;

        // verifica se il punto cade nel cerchio unitario
        if (x*x + y*y <= 1.0) {
            M++;
        }
    }

    // stima di π
    double pi = 4.0 * M / N;
    printf("Stima di pi greco = %.6f\n", pi);

    return 0;
}