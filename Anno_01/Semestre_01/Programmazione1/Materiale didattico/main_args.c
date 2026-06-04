#include <stdio.h> // printf(), fptinff(), etc
#include <stdlib.h>  // strtoul() 
#include <string.h> // strlen() 

#define ERR "[ERROR]"

/* il paremetro argc rappresenta il numero di parametri o argomenti 
 * forniti a riga di comando dall'utente 
 * per l'esecuzione del programma. 
 *
 * ES: ./a.out primo secondo 2 45.6 otto 
 * In questo caso argc conterra' il valore 6, ovvero: 
 * - i cinque argomenti dopo il nome del programma
 * - il nome del programma, il quale viene conteggiato
 *
 * il parametro argv e' un array di puntatori a carattere
 * - ogni elemento di argv rappresenta la stringa 
 *   corrispondente all'argomento o parametro passato a riga di 
 *   comando
 * - argv[0] punta alla stringa "./a.out"; argv[1] punta alla stringa "primo", 
 *   argv[2] puntera' alla stringa "secondo" e cosi via
 *
 */
int main(int argc, char *argv[]){
	
  // parsing degli argomenti a riga di comando 
  // il parsing è un processo che analizza un flusso di dati in ingresso, in modo da determinare la correttezza della sua struttura grazie ad una data grammatica formale, in questo caso i nostri controlli.
  for(size_t i=0; i<argc; i++)
    printf("\n i=%zd, argv[%zd]=%s", i, i, argv[i]); 

  printf("\n");

  /* Caso d'uso. L'utente deve inserire, in ordine
   * - due parametri interi a e b, a in [10, 20], b in [0.0, 5.0]
   * - una stringa s1 che sia lunga almeno 10 caratteri, al massimo 20 caratteri
   * - una stringa s2 che sia lunga almeno 5 caratteri, al massimo 15 caratteri
   */ 

  /* Si controlli che il numero di parametri a riga di comando 
   * sia almeno 4
   */ 
  if(argc<5){ // ricordiamo che argc = numero di parametri + 1 (il nome del programma)
    fprintf(stderr, "\n Usage: %s <a> <b> <s1> <s2>", argv[0]); 
    return -1;
  }

  // parsing e controllo parametri a e b (uso funzione strtoul). strtoul (string to unsigned long) è una funzione di libreria standard del linguaggio C che converte una stringa di caratteri in un valore di tipo unsigned long int (un numero intero lungo senza segno).
  // I parametri di strtoul sono 3 e sono: la stringa da convertire, un puntatore a un puntatore di carattere, la base numerica per la conversione (ad esempio, 10 per decimale).
  char *ptr1, *ptr2; 
  unsigned long a = strtoul(argv[1], &ptr1, 10); 
  unsigned long b = strtoul(argv[2], &ptr2, 10); 

  fprintf(stderr, "\n Checking parameter a.."); 
  // vedi documentazione famiglia di funzioni strtoul()
  if(ptr1 == argv[1] || a < 10 || a > 20){ // controllo argomenti
    fprintf(stderr, "\n %s Parameter a must be an integer in [10, 20], arg: %s\n", ERR, argv[1]);
    return -1; 
  }
  fprintf(stderr, "OK"); 

  fprintf(stderr, "\n Checking parameter b.."); 
  if(ptr1 == argv[2] || b < 0.0 || b > 5.0){
    fprintf(stderr, "\n %s Parameter b must be an integere in [10, 20], arg: %s\n", ERR, argv[2]);
    return -1; 
  }
  fprintf(stderr, "OK"); 

  // controllo lunghezza stringhe s1 ed s2 
  fprintf(stderr, "\n Checking parameter s1.."); 
  if(strlen(argv[3])<10 || strlen(argv[3])>20){
    fprintf(stderr, "\n %s Length of string s1 must be in [10, 20], arg: %s\n", ERR, argv[3]);
    return -1; 
  }
  fprintf(stderr, "OK"); 

  fprintf(stderr, "\n Checking parameter s2.."); 
  if(strlen(argv[4])<5 || strlen(argv[4])>15){
    fprintf(stderr, "\n %s Length of string s2 must be in [5, 15], arg: %s\n", ERR, argv[4]);
    return -1; 
  } 
  fprintf(stderr, "OK"); 
  
}
