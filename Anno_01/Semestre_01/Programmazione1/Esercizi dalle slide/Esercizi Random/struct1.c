#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

struct record {
    float a; //numero in virgola mobile
    char c; //carattere
    char *s; //stringa 1
    char *w; //stringa 2   
};

void inizialize(struct record *ptr){ //funzione che prende in input la struttura
    ptr->a = (float)rand() / RAND_MAX * 14.50; //randomizzo il numero in virgola mobile

    ptr->c = rand() % ('z' - 'a' + 1) + 'a'; //randomizzo il carattere

    //Alloco spazio per le stringhe
    ptr->s = malloc(sizeof(char) * 10);
    ptr->w = malloc(sizeof(char) * 10);

    //randomizzo i caratteri che compongono la stringa 1
    for(int i = 0; i < 9; i++){  // lasci un posto per '\0'
       ptr->s[i] = 'a' + rand()%('z' - 'a' + 1);
       ptr->s[9] = '\0';  // fine stringa
    }

    for(int i = 0; i < 9; i++){
       ptr->w[i] = rand()%('9' - '0' + 1) + '0';
       ptr->w[9] = '\0'; //fine stringa 
    }
}

int main(){
    srand(time(0));
    struct record *test = (struct record*) malloc(sizeof(struct record));
    inizialize(test); //dato che test è un puntatore dobbiamo usare l'arrow operator ->
    printf("float a: %.2f | char c: %c | stringa s: %s | stringa w: %s", test->a, test->c, test->s, test->w);

    free(test->s);
    free(test->w);
    free(test);

    return 0;
}