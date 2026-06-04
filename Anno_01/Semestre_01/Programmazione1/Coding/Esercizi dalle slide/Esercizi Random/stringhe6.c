#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(){
    char input[10][20]; //input[numero stringhe][lunghezza stringhe]

    for(int i = 0; i < 10; i++){ //inserire stringhe
        printf("Inserisci la stringa %d: ", i + 1);
        fgets(input[i], sizeof(input), stdin);
    }

    /*for(int i = 0; i < 10; i++){
            printf("Stringa %d: %s\n", i, input[i]);
       }
    printf("\n");*/

    int lettereminuscole = 0;
    int caratterinumeri = 0;
    int spazi = 0;
    char buffer[100];

    for(int i = 0; i < 10; i++){
            lettereminuscole = 0;  //azzeriamo tutti i contatori qui, all'inizio della nuova stringa
            caratterinumeri = 0;
            spazi = 0;

        for(int j = 0; j < 20; j++){
            if(islower((unsigned char)input[i][j])) lettereminuscole++; //incrementiamo i counter per mantenere un valore
            if(isdigit((unsigned char)input[i][j])) caratterinumeri++;
            if(isspace((unsigned char)input[i][j])) spazi++;
        }
        sprintf(buffer, "Stringa: %s\n Numero di minuscole: %d \n Numero di caratteri che rappresentano numeri: %d \n Numero di spazi: %d", input[i], lettereminuscole, caratterinumeri, spazi);
        printf("-----------------------------------------------------------\n");
        printf("%s\n", buffer); //stampiamo dal buffer riempito con ssprintf
        for(int x = 0; x < 50; x++) buffer[x] = '\0'; //azzeriamo il buffer per evitare errori
    }

    return 0;
}

//numero di lettere minuscole islower(**input)
//numero di caratteri che sono numeri isdigit(**input)
//numero di spazi isspace(**input)