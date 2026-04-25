#include <stdio.h>
#include <math.h>

int main() {
    double x1, x2;
    int n;

    printf("Inserisci un numero decimale maggiore di zero: ");
    scanf("%lf", &x1);
    printf("Inserisci un altro numero decimale maggiore di zero: ");
    scanf("%lf", &x2);
    printf("Inserisci un numero intero maggiore di 1: ");
    scanf("%d", &n);

    if (x1 <= 0 || x2 <= 0 || x1 == x2 || n <= 1) {
        printf("Input non valido!\n");
        return 1;
    }

    // Arrotondamento ai valori interi più vicini
    int a = (int)(x1 + 0.5);
    int b = (int)(x2 + 0.5);

    // Ordina a e b
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    printf("\nEcco i valori arrotondati:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    // Ciclo per ogni p tra a e b
    for (int p = a; p <= b; p++) {
        int somma1 = 0;
        int somma2 = 0;

        // Somma degli N-1 numeri minori di p
        for (int d = 1; d <= n - 1; d++) {
            somma1 += (p - d);
        }

        // Somma dei 2N numeri maggiori di p
        for (int d = 1; d <= 2 * n; d++) {
            somma2 += (p + d);
        }

        printf("\nPer p = %d:\n", p);
        printf("  Somma N-1 numeri minori di p = %d\n", somma1);
        printf("  Somma 2N numeri maggiori di p = %d\n", somma2);
    }

    return 0;
}
