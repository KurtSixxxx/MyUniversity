#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp = fopen("testo.txt", "r");

    if(fp == NULL){
        perror("ERRORE: ");
        exit (-1);
    }else{
        printf("File aperto con successo.\n");
    }

    char buffer[100];
    int countCiao = 0;

    while(fgets(buffer, 100, fp) != NULL){
        if(strstr(buffer, "ciao") != NULL) countCiao++;
    }

    printf("Numbers of 'ciao': %d\n", countCiao);

    fclose(fp);
    printf("File chiuso.\n");
    return 0;
}