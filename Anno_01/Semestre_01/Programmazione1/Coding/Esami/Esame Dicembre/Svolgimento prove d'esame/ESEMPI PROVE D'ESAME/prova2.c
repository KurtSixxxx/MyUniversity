#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Inserire intero (<256)
    se intero > 256 -> errore

Inserire s1 e s2
    se non hanno stessa lunghezza -> errore
    se non sono stringhe -> errore

Inserire carattere c
    se non è carattere -> errore
*/

/*void readInput(int *n, char *s1, char *s2, char *c){
    printf("Inserire un intero: ");
    scanf("%d", n);
    if(*n >= 256){
        fprintf(stderr, "[ERR]: l'intero deve essere < 256.\n");
        exit(-1);
    }

    printf("Inserire una stringa: ");
    scanf("%.256s", s1);
    if(strlen(s1) != *n) { 
    fprintf(stderr, "[ERR]: la stringa S1 non ha la lunghezza corretta (%d).\n", *n);
    exit(-1);
    }

    printf("Inserire una seconda stringa: ");
    scanf("%.256s", s2);
    if(strlen(s2) != *n) { 
    fprintf(stderr, "[ERR]: la stringa S2 non ha la lunghezza corretta (%d).\n", *n);
    exit(-1);
    }

    printf("Inserire un carattere: ");
    scanf(" %c", c);
    if(strlen(c)!=1){
        fprintf(stderr, "[ERR]: il carattere immesso non è un carattere.\n");
        exit(-1);
    }
}*/

void readInput(int *n, char *s1, char *s2, char *c) {
    printf("Si inserica un intero n: ");
    scanf("%d", n);
    printf("Si inserisca una stringa di lunghezza %d: ", *n);
    scanf("%s", s1);
    printf("Si inserisca una stringa di lunghezza %d: ", *n);
    scanf("%s", s2);
    if(strlen(s1)!=*n || strlen(s2)!=*n) {
        fprintf(stderr, "Errore! Le stringhe non sono di lunghezza %d\n", *n);
        exit(-1);
    }
    while(!getchar());
    printf("Inserire un carattere: ");
    scanf("%c", c);
}

char* replaceChar(char **s1, char **s2, char *c);

char* invertString();
char* sort();
void printResult(char* string);


int main(){
    int n;
    char s1[257];
    char s2[257];
    char c;
    readInput(&n, s1, s2, &c);
}