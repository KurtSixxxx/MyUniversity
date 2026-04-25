/*Esercizio 7*/

#include <stdio.h>

int sommaArray (int *array, int dimensione){
    int somma = 0; // Questa variabile tiene traccia della somma cumulativa degli elementi dell'array. 
    for(int i = 0; i < dimensione; i++){
        somma += array[i];
    } //  Questo ciclo for serve per attraversare l'array partendo dal primo elemento (i = 0) fino all'ultimo (i < dimensione).
return somma;
}

int main(){
    
int array[10] = {12, 13, 56, 64, 23, 14, 34, 65, 88, 63};
int somma = sommaArray(array, 10); //Chiamo la funzione e passo l'array e la sua dimensione

printf("%d", somma);

return 0;

}
