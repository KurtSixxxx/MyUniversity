/*Apri un file di testo, leggi una riga con fgets, poi usa ftell per stampare la posizione corrente del cursore.*/

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
    

    if(fgets(buffer, 100, fp) != NULL){
        printf("Ho letto: %s\n", buffer);
    }

    long posizione = ftell(fp);
    printf("Cursore alla posizione %ld\n", posizione);

    fclose(fp);
    printf("File chiuso.\n");
    return 0;
}