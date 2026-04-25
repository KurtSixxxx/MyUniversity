//Stampa dei numeri pari da 1 a 20 utilizzando un ciclo while:

#include <stdio.h>

int main (){
    
int i = 2; //Inizializzazione: int i = 2; inizializza la variabile i con il valore 2. Questo perché vogliamo iniziare con il primo numero pari.

while (i <= 20) // assicura che il ciclo si ripeta finché il valore di i è minore o uguale a 20.
{
printf ("%d \n", i);
i+=2; // incrementa i di 2 ad ogni iterazione. Poiché stiamo cercando i numeri pari, aggiungiamo 2 ad ogni passaggio per assicurarci di ottenere solo numeri pari.
}

return 0;

// Quindi, il ciclo inizierà con i uguale a 2 e lo incrementerà di 2 ad ogni iterazione fino a quando raggiunge o supera 20. In questo modo, verranno stampati solo i numeri pari tra 1 e 20.
}