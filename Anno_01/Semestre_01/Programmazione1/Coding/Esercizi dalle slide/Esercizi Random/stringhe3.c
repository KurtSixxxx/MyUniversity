#include <stdio.h>
#include <string.h>

int main(){
    char s1[20]; 
    char s2[20];

    printf("Inserisci il tuo nome e cognome: ");
    scanf("%s %s", s1, s2); //scanf("%s %s", &s1, &s2); → NON serve & con gli array
    
    printf("\n");
    printf("Contenuto stringa 1: %s\n", s1);
    printf("Contenuto stringa 2: %s\n", s2);

    char arr[40]; //creiamo l'array risultante con la dimensione raddoppiata
    int lenS1 = strlen(s1); //preleviamo la lunghezza di s1
    s1[lenS1] = ';'; //aggiungiamo, con furbizia il ; alla fine della stringa
    s1[lenS1 + 1] = '\0'; //Agiungiamo il terminatore per non incorrere in problemi
    int lenS2 = strlen(s2); //preleviamo la lunghezza di s2
    int lenS1S2 = lenS1 + lenS2; //la lunghezza dell'array sarà data dalla somma della lunghezza di entrambe le stringhe
    strcpy(arr, s1); //Copio all'inizio della stringa
    strcpy(&arr[(lenS1S2 + 1) - lenS2], s2); //Copio dopo il punto e virgola

    printf("Stringa risultante: %s", arr);
    

    return 0;
}