#include <stdio.h>
#include <stdlib.h>

#define DIM 3

struct Contatto {
    int id;
    char nome[30];
    char numero[20];
};

int main(){
    struct Contatto rubrica[DIM];

    printf("Inserimento dei contatti...\n");

    for(int i = 0; i < DIM; i++){
        printf("\n");
        printf("Contatto [%d]\n", i + 1);
        rubrica[i].id = i + 1;

        printf("Inserisci il nome: ");
        scanf("%s", rubrica[i].nome);
        

        printf("Inserisci il numero di telefono: ");
        scanf("%s", rubrica[i].numero);
    }
    
    FILE *fp = fopen("filestruct.bin", "wb");

    if(fp == NULL){
        perror("ERRORE: ");
        exit(-1);
    }else{
        printf("File aperto con successo.\n");
    }
    
    for(int i = 0; i < DIM; i++) fwrite(&rubrica[i], sizeof(struct Contatto), 1, fp);

    fclose(fp);
    printf("File chiuso.\n");
    return 0;
}