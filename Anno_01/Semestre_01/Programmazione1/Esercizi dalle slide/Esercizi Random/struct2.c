#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define N 5

struct record {
    float a;    //numero in virgola mobile
    char c;     //carattere
    char *s;    //stringa 1
    char *w;    //stringa 2   
};

struct data{
    int ID;             //sempre positivo
    struct record rec;  //Record annidato, non puntatore
};
//---------------------------------------------------------------------------
void inizialize(struct record *ptr){                //funzione che prende in input la struttura
    ptr->a = (float)rand() / RAND_MAX * 14.50;      //randomizzo il numero in virgola mobile

    ptr->c = rand() % ('z' - 'a' + 1) + 'a';    //randomizzo il carattere

    //Alloco spazio per le stringhe
    ptr->s = malloc(sizeof(char) * 10);
    ptr->w = malloc(sizeof(char) * 10);

    //randomizzo i caratteri che compongono la stringa 1
    for(int i = 0; i < 9; i++){ // lasci un posto per '\0'
       ptr->s[i] = 'a' + rand()%('z' - 'a' + 1);
    }
    ptr->s[9] = '\0'; // fine stringa

    for(int i = 0; i < 9; i++){
       ptr->w[i] = rand()%('9' - '0' + 1) + '0'; 
    }
    ptr->w[9] = '\0';
}

void initData(struct data *ptr){ //!!!!!!!!!!
    static int count = 1;
    ptr->ID = count++;
    inizialize(&ptr->rec);
    //ptr->rec vuol dire “vai nella struct data puntata da ptr, e prendi il campo rec”.
    printf("ID: %d \n", ptr->ID);
    printf("float a: %.2f | char c: %c | stringa s: %s | stringa w: %s \n", ptr->rec.a, ptr->rec.c, ptr->rec.s, ptr->rec.w); //Per la stampa, sto dicendo a ptr: vai nel campo 'x' di rec e preleva il vaore, per questo uso sia freccia che punto
}

int main(){
srand(time(0));
struct data array[N]; //inizializzo N array di tipo struct data

    int k = 3; //il mio k a piacere è 3

    int i = 0;
    while(i < k){ //le 3 celle devono essere interi positivi
        array[i].ID = i + 1;
        i++;
    }

    int z = 3;
    while(z < N){ //le celle dopo le prime 3 sono -1
        array[z].ID = -1;
        z++;
    }

        for(int i = 0; i < k; i++){
            initData(&array[i]);
            printf("\n");
        }
    
return 0;
}