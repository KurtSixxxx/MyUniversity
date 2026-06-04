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

    printf("Lettura dei contatti...\n");
    
    FILE *fp2 = fopen("filestruct.bin", "rb");

    if(fp2 == NULL){
        perror("ERRORE: ");
        exit(-1);
    }else{
        printf("File aperto con successo.\n");
    }
    
    struct Contatto letti[DIM];
    for(int i = 0; i < DIM; i++) fread(&letti[i], sizeof(struct Contatto), 1, fp2);

    printf("Contatti letti:\n");
    for(int i = 0; i < DIM; i++){
        printf("Contatto [%d] | Nome: %s | Numero: %s\n", letti[i].id, letti[i].nome, letti[i].numero);
    }

    if(feof(fp2)){
        printf("Ho raggiunto la fine del file.\n");
    }

    fclose(fp2);
    printf("File chiuso.\n");
    return 0;
}