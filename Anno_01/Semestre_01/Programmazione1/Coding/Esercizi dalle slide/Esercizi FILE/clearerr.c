/*Leggi fino alla fine di un file, verifica con feof. Poi usa clearerr e rewind, e dimostra che ora puoi leggere di nuovo il file.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp = fopen("testo.txt", "r");

    if(fp == NULL){
        perror("ERRORE: ");
        exit (-1);
    }else{
        printf("File aperto con successo.\n\n");
    }

    char buffer[100];

    while(fgets(buffer, 100, fp) != NULL){
        printf("Riga letta: %s", buffer);
    }

    if(feof(fp)) printf("\n\nHai raggiunto la fine del file.\n\n");

    clearerr(fp);
    rewind(fp);

    while(fgets(buffer, 100, fp) != NULL){
        printf("Riga letta: %s", buffer);
    }

    fclose(fp);
    printf("\n\nFile chiuso.\n");
    return 0;
}