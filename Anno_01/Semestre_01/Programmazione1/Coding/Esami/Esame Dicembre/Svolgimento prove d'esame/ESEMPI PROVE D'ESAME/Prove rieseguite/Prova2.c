#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void readInput(int *n, char *s1, char *s2, char *c){
    printf("Inserire un intero n: ");
    scanf("%d", n);
    if(*n >= 256){
        fprintf(stderr, "[ERR]: il valore di n deve essere minore di 256.\n");
        exit(-1);
    }

    printf("Inserire una stringa s1: ");
    scanf("%256s", s1);
    if(strlen(s1) != *n){
        fprintf(stderr, "[ERR]: La stringa deve essere di lunghezza %d\n", *n);
        exit(-1);
    }

    printf("Inserire una stringa s2: ");
    scanf("%256s", s2);
   if(strlen(s2) != *n){
        fprintf(stderr, "[ERR]: La stringa deve essere di lunghezza %d\n", *n);
        exit(-1);
    }

    printf("Inserire un carattere c: ");
    scanf(" %c", c);
    if(*c < 'a' || *c > 'z'){
        fprintf(stderr, "[ERR]: il parametro immesso non è un carattere.\n");
    }

    printf("Parametri immessi:\n");
    printf("n = %d \t s1: %s \t s2: %s \t c: %c\n", *n, s1, s2, *c);
}

char* replaceChar(int n, char *s1, char *s2, char *c){
    char *s3 = malloc(sizeof(char) * strlen(s1)+1);
        if(s3 == NULL){
            fprintf(stderr, "[ERR]: errore nel processo di allocazione stringa.\n");
            exit(-1);
        }

        strcpy(s3, s1);
        for(int i = 0; i < n; i++){
            if(s3[i] == *c){
                s3[i] = s2[i];
            }else{
                s3[i] = s1[i];
            }
        }
        
    return s3;
}

char* invertString(int n, char *s2){
    char *s4 = malloc(sizeof(char) * strlen(s2)+1);
        if(s4 == NULL){
            fprintf(stderr, "[ERR]: errore nel processo di allocazione stringa.\n");
            exit(-1);
        }
    
    int len = n;
    int i = 0;
    int count = 1;
    while(i < n){
        s4[i] = s2[len - count];
        count++;
        i++;
    }
    s4[n] = '\0';

    return s4;
}

char* sort(int n, char *s3, char* s4){
    char *s5 = malloc(sizeof(char) * (n*2));
    if(s5 == NULL){
        fprintf(stderr, "[ERR]: errore nel processo di allocazione stringa.\n");
        exit(-1);
    }

    strcpy(s5, s3);   // copia s3
    strcat(s5, s4);   // appiccica s4 dopo s3
    int len = strlen(s5);
    for(int i = 0; i < len-1; i++){
        bool sentinella = 0;
        for(int j = 0; j < len - i - 1; j++){
            if(s5[j] > s5[j+1]){
                char tmp = s5[j];
                s5[j] = s5[j+1];
                s5[j+1] = tmp;
                sentinella = 1;
            }
        }
        if(sentinella == 0) break;
    }

    return s5;
}

void printResult(char *s5){
    for(int i = 0; i < strlen(s5); i++){
        int ascii = (int)s5[i];
        if(ascii % 2 == 1) s5[i] = '*';
    }

    printf("\nASCII dispari: %s", s5);
}

int main(){
    int n;
    char s1[256];
    char s2[256];
    char c;
    readInput(&n, s1, s2, &c);
    char *s3 = replaceChar(n, s1, s2, &c);
    printf("\nReplace Char: %s\n", s3);
    char *s4 = invertString(n, s2);
    printf("\nInverse String: %s\n", s4);
    char *s5 = sort(n, s3, s4);
    printf("\nsort: %s\n", s5);
    printResult(s5);
}