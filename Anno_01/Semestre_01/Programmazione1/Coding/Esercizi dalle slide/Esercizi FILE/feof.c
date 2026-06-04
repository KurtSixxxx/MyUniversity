/*Leggi un file binario con fread in un ciclo while. Dopo il ciclo, stampa se hai raggiunto la fine del file con feof.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prima vesione del codice fallita... Sotto questo commento ho riciclato un codice per usare feof()
int main(){
    
    FILE *fp = fopen("prova.bin", "wb");

    if(fp == NULL){
        perror("ERRORE: ");
        exit(-1);
    }else{
        printf("File aperto con successo.\n");
    }

    char stringa[100] = ("Il sole e' molto caldo!");
    char buffer[30];
    
    printf("Scrivo una frase sul file binario...\n");
    fwrite(stringa, sizeof(char), strlen(stringa) + 1, fp); //scrive solo i caratteri effettivi (es. se è "ciao", scrive 4) → !! ma non salva il terminatore \0. Se vuoi salvare anche il \0, fai + 1

    int i = 0;
    while(i < 10){
        i++;
        fwrite(buffer, sizeof(char), strlen(buffer) + 1, fp);
    }

    char stringaletta[100];
    char bufferletto[30];
    fread(stringaletta, sizeof(char), 100, fp);

    while(i < 10){
            i++;
            fread(bufferletto, sizeof(char), 30, fp);
        }

    printf("Cosa ho letto:\n");
    printf("%s\n", stringa);

    /*printf("Ho letto anche: \n");
    int j = 0;
    while(j < 10){
        j++;
        printf("%d\n", j);
    }

    int value = 0;

    if(feof(fp)){
        printf("Ho raggiunto la fine del file.\n");
        value = 1;
    }else{
        fprintf(stderr, "Non ho ancora raggiunto la fine del file. Impossibile chiudere il file.\n");
    }

    

    if(value == 1){
        fclose(fp);
        printf("File chiuso.\n");
    }
    return 0;
} */

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