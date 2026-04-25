#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(){
    srand(time(0));

//Parte 1
    char s1[16];
    s1[15] = '\0';
    for(int i = 0; i < 15; i++) s1[i] = rand()%('z' - 'a' + 1) + 'a';
    printf("%s \n", s1);

//Parte 2
    char s2[5] = {'c', 'i', 'a', 'o', '\0'};
    printf("%s \n", s2);

//Parte 3
    char s3[] = "Programma";
    printf("Lunghezza: %lu \t Stringa: %s", strlen(s3), s3);
    printf("\n");

//Parte 4
    const char *s4 = "Costante";
    printf("Lunghezza: %lu \t Stringa: %s", strlen(s4), s4);

    return 0;
}