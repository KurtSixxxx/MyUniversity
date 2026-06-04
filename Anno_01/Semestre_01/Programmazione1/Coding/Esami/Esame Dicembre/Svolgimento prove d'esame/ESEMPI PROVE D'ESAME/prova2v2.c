#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readInput(int *n, char *s1, char *s2, char *c){
    printf("Inserire un intero: ");
    scanf("%d", n);
    if(*n >= 256){
        fprintf(stderr, "[ERR]: l'intero non può essere maggiore di 256.\n");
        exit(-1);
    }

    printf("Inserire una stringa: ");
    scanf("%.256s", s1);
    if(strlen(s1) != *n){
        fprintf(stderr, "[ERR]: La stringa deve essere di lunghezza %d\n", *n);
        exit(-1);
    }

    printf("Inserire una stringa: ");
    scanf("%.256s", s2);
    if(strlen(s2) != *n){
        fprintf(stderr, "[ERR]: La stringa deve essere di lunghezza %d\n", *n);
        exit(-1);
    }

    printf("Inserire un carattere: ");
    scanf(" %c", c);
    if(strlen(c) > 2){
        fprintf(stderr, "[ERR]: Il carattere immesso è non è un carattere.\n");
        exit(-1);
    }
}

int main(){
    int n;
    char s1[257];
    char s2[257];
    char c;

    readInput(&n, s1, s2, &c);
return 0;
}