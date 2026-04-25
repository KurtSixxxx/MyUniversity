/*
2) Definire una variabile float x ed una double y. 
Inserire istruzioni tali che: 
   a) alla variabile x sia assegnato il valore 10882000; 
   b) alla variabile y sia assegnato il prodotto di x per 
      il letterale 1.23456*10^100, quest'ultimo 
      espresso in notazione scientifica

      
3) Stampare le variabili x e y mediante una istruzione printf: 
   a) in notazione scientifica (specificatore %e/%E) 
   b) inoltre specificando di stampare 6 cifre dopo la virgola 
   
*/
#include <stdio.h>

int main(){

    float x = 10882000;
    double y = x * 1.23456e100;

    printf("Float X = %f \n", x);
    printf("Double Y = %.6e \n", y);
   

    return 0;
}