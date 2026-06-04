/*Codificare un programma in linguaggio C che operi un numero indefinito
di volte la moltiplicazione di un numero in virgola mobile y > 0 per un
altro numero in virgola mobile x < 1: y ← y ∗ x.
Ad ogni iterazione si stampi il risultato della moltiplicazione.
L’algoritmo deve terminare quando si verifica la condizione di underflow,
ovvero il risultato viene approssimato con lo zero.
Codificare l’algoritmo anche con un numero di partenza y < 0, stampare
il risultato finale (lo 0 “negativo”).
Stampare i risultati in notazione scientifica.
*/

#include <stdio.h>
#include <float.h>

int main(){
    float y, x;
    printf("Inserisci un valore (in virgola mobile) per y: ");
    scanf("%f", &y);
    printf("Inserisci un valore (in virgola mobile) per x: ");
    scanf("%f", &x);

    if(y < 0.0 || x > 1.0 || x == y){
        printf("Input non valido!\n");
        return 1;
    }

    do{
        y *= x;
        printf("%f", y);
    }while(y > 0.0);
    

    return 0;
}