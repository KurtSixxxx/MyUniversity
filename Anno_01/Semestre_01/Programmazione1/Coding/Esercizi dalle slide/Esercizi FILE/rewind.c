/*Leggi la prima riga di un file di testo, poi usa rewind per tornare all'inizio e rileggila di nuovo.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fp = fopen("testo.txt", "r");

    if(fp == NULL){
        perror("ERRORE: ");
        exit(-1);
    }else{ 
        printf("File aperto con successo.\n");
    }

    char buffer[100];
    int i = 0;

    if(fgets(buffer, 100, fp) != NULL){
        i++;
        printf("Ho letto per la %d volta: %s\n", i, buffer);
    }

    rewind(fp);
    i++;

    if(fgets(buffer, 100, fp) != NULL){
        printf("Ho letto per la %d volta: %s\n", i, buffer);
    }

    fclose(fp);
    printf("File chiuso.\n");
    return 0;
}