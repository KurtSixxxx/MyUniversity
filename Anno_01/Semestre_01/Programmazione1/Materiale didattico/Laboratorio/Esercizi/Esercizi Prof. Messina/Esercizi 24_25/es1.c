/*1) Definire alcune variabili intere con nomi a piacimento: 
    - short 
    - unsigned int 
    - long
    
    a) assegnare alcuni valori a piacimento, stampare tali valori 
    mediante la funzione di libreria printf() e gli specificatori 
    di formato %hd, %u, %ld rispetticamente. 

    b) codificare istruzioni che permettano di aggiornare le variabili per ottenere overflow (sommare opportuni valori). In particolare: 
      - overflow positivo per lo short 
      - overflow per la variabile unsigned 
      - overflow negativo per la variabile long 

    c)  stampare dunque i risultato con la funzione printf e gli 
      specificatori di formato citati in precedenza.*/

#include <stdio.h>

//Dichiaro le funzioni richieste per l'overlflow
// B)

short overflowShort (short s) {
  printf("Valore Short prima dell'overflow: %hd \n", s);
  s = s + 32767; //overflow positivo per lo short 
  return s;
  printf("\n");
}

unsigned int overflowUnsigned (unsigned int ui) {
  printf("Valore Unsigned int prima dell'overflow: %u \n", ui);
  ui = ui + 4294967295; //overflow per la variabile unsigned 
  return ui;
  printf("\n");
}

long overflowLong (long l) {
  printf("Valore long prima dell'overflow: %ld \n", l);
  l = l - 2147483647; //overflow negativo per la variabile long 
  return l;
  printf("\n");
}
int main(){
// A)
  short s = 123;
  unsigned int ui = 1029;
  long l = 10023;

  printf("Short: %hd \n", s);
  printf("Unsigned int: %u \n", ui);
  printf("Long: %ld \n", l);
  printf("\n");




// C)
s = overflowShort(s);
ui = overflowUnsigned(ui);
l = overflowLong(l);

return 0;
}