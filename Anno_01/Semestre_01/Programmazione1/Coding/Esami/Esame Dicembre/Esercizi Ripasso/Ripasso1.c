#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int n; //Dichiariamo la variabile che conterrà la dimensione
  printf("Inserire la dimensione dell'array: "); //Chiediamo input da tastiera all'utente
  scanf("%d", &n); //Salviamo il valore
  
  int *arr = malloc(sizeof(int) * n); //Allochiamo dinamicamente nell'HEAP un array di n interi
 if(arr == NULL){ //Verifichiamo che l'allocazione sia avvenuta correttamente
     printf("FAILED ALLOCATION");
     exit(-1);
 }
  
  srand(time(0)); //Avviamo il seme con time()
  
  //Riempiamo ogni cella dell'array con valori pseudocasuali
  //rand() % (b - a + 1) + a; dove b = 100 e a = 1;
    for(int i= 0; i < n; i++) *(arr + i) = rand() % (100 - 1 + 1) + 1;  // *(arr + i) <=> arr[i]
  
  //Stampiamo l'array
  for(int i = 0; i < n; i++) printf("%d ", *(arr + i));
  printf("\n");
  
  //Inizializziamo i valori di media e massimo
  double media = 0; //Inzialmente sarà uguale a zero per evitare di contenere valori spazzatura
  int massimo = *arr; //Impostiamo il massimo momentanemante come primo elemento (Rircorda che il nome di un array è il primo elemento)

  for(int *p = arr; p < arr + n; p++) media += *p; //Sommiamo tutti i valori dentro la variabile media
  media = media / n; //Dividiamo il valore di 'media' per il numero di elementi
  printf("Media: %.2f\n", media);
  
  for(int *p = arr; p < arr + n-1; p++){ //Cicliamo tutto l'array
    if(*p > massimo){ //Se trovimamo in elemento maggiore del massimo...
      massimo = *p; //...diventa il nuovo masissimo
    }
  }
  printf("Massimo: %d\n", massimo);

  free(arr); //Liberiamo l'array allocato dinamicamente nell'HEAP
  return 0;
}