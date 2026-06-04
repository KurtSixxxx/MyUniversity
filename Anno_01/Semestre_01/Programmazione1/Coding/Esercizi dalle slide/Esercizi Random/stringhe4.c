#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERBI 10 //Definiamo il numero massimo di verbo da inserire
#define MAX_LUNGHEZZA 30 //Definiamo lunghezzza massima dei verbi

int main(){
    char s[MAX_VERBI][MAX_LUNGHEZZA]; //Definiamo l'array di stringhe
    
    //Inizializziamo i contatori
    int verbiAre = 0; 
    int verbiEre = 0;
    int verbiIre = 0;

    //Sottostringhe da cercare
    char *are = "are";
    char *ere = "ere";
    char *ire = "ire";

    //Puntatore per la funzione strstr()
    char *trovato;

    //For loop che ci fa inserire tutti verbi
    for(int i = 0; i < MAX_VERBI; i++){
            printf("Inserire un verbo: ");
            scanf("%s", s[i]);
        }   
        
    printf("\n");
    
    //For loop che stampa tutti i verbi
    for(int i = 0; i < MAX_VERBI; i++){
            printf("%s\n", s[i]);
       }

    printf("\n");

    //For loop che itera su tutte le stringhe, utilizza condizionali per verificare se la sottostringa è stata trovata ed aggiorna i contatori
    for(int i = 0; i < MAX_VERBI; i++){
            trovato = strstr(s[i], are);
            if(trovato != NULL) verbiAre++; //! <---  Il confronto 'if (trovato != NULL)' è l'unico modo sicuro per verificare il successo di strstr().
        //! SBAGLIATO (trovato == are)      //!       Confrontare i puntatori con '==' è inaffidabile, perché la loro uguaglianza dipende da come il compilatore alloca la memoria, un comportamento che non è standard e può variare.
            trovato = strstr(s[i], ere);
            if(trovato != NULL) verbiEre++;

            trovato = strstr(s[i], ire);
            if(trovato != NULL) verbiIre++;   
        }

    printf("Numero di verbi in coniugazione 'are': %d\n", verbiAre);
    printf("Numero di verbi in coniugazione 'ere': %d\n", verbiEre);
    printf("Numero di verbi in coniugazione 'ire': %d\n", verbiIre);
    
    return 0;
}