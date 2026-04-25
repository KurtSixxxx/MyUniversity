/*Trovare il valore massimo in un array*/

#include <stdio.h>

int main (){

int array[] = {10, 35, 80, 9, 2};
int i;
int massimo = array [i];
int lunghezza = sizeof(array)/sizeof(array[i]);

for(i = 1; i < lunghezza; i++){
    if(array[i]>massimo){
        massimo = array[i];
    }
}

printf("Il valore massimo corrisponde a: %d", massimo);

return 0;

}