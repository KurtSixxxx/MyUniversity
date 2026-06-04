/*Apri un file in scrittura. Scrivi un messaggio, usa fflush per forzare la scrittura prima della fclose. Verifica il file senza chiuderlo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp = fopen("testo.txt", "w");

    if(fp == NULL){
        perror("ERRORE: ");
        exit (-1);
    }else{
        printf("File aperto con successo.\n\n");
    }

    char stringa[100] = "Mi piace tanto il mare!";

    fputs(stringa, fp)
    fscanf(fp, "%s", stringa)

    if(feof(fp)) printf("\n\nHai raggiunto la fine del file.\n\n");

    clearerr(fp);
    rewind(fp);

    while(fgets(stringa, 100, fp) != NULL){
        printf("Riga letta: %s", stringa);
    }

    fclose(fp);
    printf("\n\nFile chiuso.\n");
    return 0;
}