/*Apri un file binario che contiene una sequenza di struct, salta il secondo elemento usando fseek, e stampa il terzo con fread*/

#include <stdio.h>
#include <stdlib.h>

struct Contatto {
    int id;
    char nome[30];
    char numero[20];
};

int main(){

    FILE *fp = fopen("filestruct.bin", "rb");

    if(fp == NULL){
        perror("ERRORE: ");
        exit(-1);
    }else{ 
        printf("File aperto con successo.\n");
    }

    fseek(fp, sizeof(struct Contatto) * 2, SEEK_SET);

    //FILE *fp2 = fopen("filestruct.bin", "rb");

    struct Contatto letto;
    fread(&letto, sizeof(struct Contatto), 1, fp);

    printf("Dati letti:\n");
    printf("ID: %d | Nome: %s | Numero: %s\n", letto.id, letto.nome, letto.numero);

    fclose(fp);
    printf("File chiuso.\n");
    return 0;
}