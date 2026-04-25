//Calcolo della somma dei numeri da 1 a 100 utilizzando un ciclo while:

 #include <stdio.h>

 int main (){

    int i = 1;
    int somma = 0;

    while(i<=100){
        
        somma += i;
        i++;
    }

      printf("Il risultato equivale a: %d", somma);
   
return 0;

 }