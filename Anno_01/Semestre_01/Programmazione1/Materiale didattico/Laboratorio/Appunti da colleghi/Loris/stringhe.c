#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    int array=15;
    srand(time(0));
    char random[array];
    for(int i=0;i<array;i++){
        random[i]= 'a'+rand()%26;
        random[array - 1] = '\0';
        printf("\nArray=%s", random);
    }

    char caratteri[]={"matildina"};
    printf("\nStringa=%s", caratteri);

    char caratteri2[]={"Troppo lungo mi secca"};
    int lenght=0;
    while(caratteri2[lenght]!='\0'){
        lenght++;
    }
    printf("\nLunghezza della stringa=%d", lenght);
    printf("\nStringa=%s", caratteri2);

    const char *stringa_solo_lettura = "Esempio di stringa di sola lettura";
    int lunghezza=0;
    while(stringa_solo_lettura[lunghezza]!='\0'){
        lunghezza++;
    }
    printf("\nLunghezza di stringa=%d", lunghezza);
    printf("\nStringa=%s", stringa_solo_lettura);
}