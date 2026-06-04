/*Apri un file con fopen, poi chiudilo. Dopo chiusura, prova a leggere e usa ferror per stampare se si è verificato un errore.*/

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

    fclose(fp);
    printf("File chiuso.\n");

    if(fgets(buffer, 100, fp) != NULL){
        printf("Riga letta: %s", buffer);
    }else if(ferror(fp)){
       perror("Errore I/O");
    }

    return 0;
}