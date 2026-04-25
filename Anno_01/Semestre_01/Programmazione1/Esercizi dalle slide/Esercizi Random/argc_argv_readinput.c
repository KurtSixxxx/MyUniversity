#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR "[ERROR]: "

/*
A compreso tra 10 e 20
B compreso tra 30 e 40
S almeno 5 e massimo 15
M almmeno 10 e massimo 20
*/

void readInput(int argc, char* argv[], int *a, int *b, char* s, char* m){
    if(argc < 5){
        fprintf(stderr, "Uso: %s <a> <b> <s> <m>", argv[0]);
        exit(EXIT_FAILURE);
    }

    *a = atoi(argv[1]);
    *b = atoi(argv[2]);

    if(*a < 10 || *a > 20){
        fprintf(stderr, ERR "<a> deve essere compreso tra 10 e 20.\n");
        exit(EXIT_FAILURE);
    }

    if(*b < 30 || *b > 40){
        fprintf(stderr, ERR "<b> deve essere compreso tra 30 e 40.\n");
        exit(EXIT_FAILURE);
    }

    if(strlen(argv[3]) < 5 || strlen(argv[3]) > 15){
        fprintf(stderr, ERR "<s> deve essere lungo almeno 5 e massimo 15.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(s, argv[3]);

    if(strlen(argv[4]) < 10 || strlen(argv[4]) > 20){
        fprintf(stderr, ERR "<m> deve essere lungo almeno 10 e massimo 20\n");
        exit(EXIT_FAILURE);
    }
    strcpy(m, argv[4]);
    
}

int main(int argc, char* argv[]){
    int a, b;
    char s[100], m[100];

    readInput(argc, argv, &a, &b, s, m);
    printf("Valori validi:\n a= %d\n b= %d\n s= %s\n m= %s\n", a, b, s, m);

    return 0;
}