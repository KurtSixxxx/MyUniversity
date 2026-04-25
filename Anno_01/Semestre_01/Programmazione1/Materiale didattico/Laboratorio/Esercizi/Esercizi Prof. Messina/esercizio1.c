#include <stdio.h>
#include <float.h>
#include <limits.h>

int main (){

    //1) Definire una variabile float x ed una double y. 
    //Inserire istruzioni di assegnamento tali che: 
    //a) alla variabile x sia assegnato un valore 10882000 
    //mediante un letterale in notazione scientifica
    //b) alla variabile y sia assegnato il prodotto di x per 
    //1.23456*10^100 in notazione scientifica

    float x = 10882e7;
    double y = x * 1.23456e100;

    //2) Stampare le variabili x e y mediante una istruzione printf: 
    // a) in notazione scientifica (specificatore %e/%E) 
    // b) inoltre specificando di stampare 6 cifre dopo la virgola

    printf("Variabile x: %.6e \n", x);
    printf("Variabile y: %.6E \n", y);

    //3) Moltiplicare x per un numero in virgola mobile tale che 
    //si ottenga un overflow negativo. Stampare il risultato
    //mediante una istruzione printf. 

   float x_overflow_neg = FLT_MIN;
   float valoreOverflow_neg = 0.5;

   float overflow_Neg = x_overflow_neg * valoreOverflow_neg;

   printf("Risultato overflow negativo: %e \n", overflow_Neg);

    //4) Moltiplicare y per un numero tale che si ottenga un overflow positivo. 
    //Stampare il risultato mediante una istruzione printf. 

   float y_overflow_pos = FLT_MAX;
   float valoreoverflow_pos = 2.0;

   float overflow_Pos = y_overflow_pos * valoreoverflow_pos;

   printf("Risultato overflow postivo: %e \n", overflow_Pos);

    //5) Definire due variabili intere con valori vicini o uguali al massimo numero rappresentabile. 
    //a) Sommare le due variabili assegnando il risultato ad una terza variabile intera, stampare il risultato; 
    //b) Sommare le due variabili assegnando il risultato ad una variabile di tipo long, e stampare il risultato; 

    int x_INTMAX = INT_MAX;
    int y_INTMAX = INT_MAX - 1;

    //Sommo le due variabili per ottenere la terza variabile, ossia z.
    int z = x + y;
    printf("Somma delle variabili intere: %d \n", z);

    //Adesso sommmo le due variabili e ottengo la variabile di tipo long long, ossia w.
    int w = (long)x +y;
    printf("Somma delle variabili in long: %ld \n", w);


    //6) Consultare la documentazione relativa al file header limits.h,
    //stampare quindi il range (valore minimo e valore massimo) del tipo "long long"; 
    long long valore_minimo = LLONG_MIN;
    long long valore_massimo = LLONG_MAX;

    printf("Valore minimo del tipo di dato long long: %lld \n", valore_minimo);
    printf("Valore massimo del tipo di dato long long: %lld \n", valore_massimo);

    //7) Stampare il valore restituito dall'operatore sizeof per il tipo long ed il tipo "long long";

    printf("Valore in byte del tipo long: %ld \n", sizeof(long));
    printf("Valore in byte del tipo long long: %lld \n", sizeof(long long));

return 0;

}