//Calcolo della somma dei numeri da 1 a 100 utilizzando un ciclo while:
#include <stdio.h>

int main() {
    int i = 1;
    int somma = 0;

    while (i <= 100) {
        somma += i;
        i++;
    }
// finché i è minore o uguale di 100 somma 1 a somma, la quale sarebbe 0.

    printf("La somma dei numeri da 1 a 100 è: %d\n", somma);

    return 0;
}