#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    int viewsTotali;
    float guadagnoStimato;
} canale;


int main(){
    canale *ptr;
    int n; // Numero di 'canali' da allocare nella memoria dinamica

    printf("Numero canali: ");
    scanf("%d", &n);

    // Alloco la memoria per n strutture di tipo "canale"
    ptr = (canale *) malloc(n * sizeof(canale));

    for(int i = 0; i < n; i++){
        printf("Nome canale: ");
        scanf("%s", (ptr+i)->nome); // Con (ptr+i)->nome andiamo a mettere nella struttura il nome.
        /* (ptr+i) il '+i' fa richiamo all'aritmrtica dei puntatori.
        Utilizzando l'operatore di incremento +i con ptr, puoi accedere agli elementi successivi dell'array di strutture. */

        printf("Numero di visualizzazioni totali: ");
        scanf("%d", &(ptr+i)->viewsTotali);

        // Calcolo guadagno e assegno valore
        (ptr+i)->guadagnoStimato = (ptr+i)->viewsTotali / 1000.00;
    }

    printf("\nStampa canali e guadagni:\n");
    for(int i = 0; i < n; ++i){
        printf("[Operatore '.']\t\t Nome: %s\tGuadagno: %.2f\n", (*(ptr+i)).nome, (*(ptr+i)).guadagnoStimato);
        printf("[Operatore '->']\t Nome: %s\tGuadagno: %.2f\n", (ptr+i)->nome, (ptr+i)->guadagnoStimato);
    }

    return 0;
}