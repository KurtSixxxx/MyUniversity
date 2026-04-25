/*Chiedere all'utente di inserire un numero da 1 a 7 che rappresenta un giorno della
settimana e stampare il nome del giorno corrispondente.*/

#include <stdio.h>
int main (){
  
  int numeroGiorno;
  printf("Inserisci un numero da 1 a 7: ");
  scanf("%d", &numeroGiorno);
  
  switch(numeroGiorno){
  case 1:
  
  printf("Lunedì\n");
  break;
  
  case 2:
  printf("Martedì\n");
  break;
  
  
  case 3:
  printf("Mercoledì\n");
  break;
  
  case 4:
  printf("Giovedì\n");
  break;
  
  case 5:
  printf("Venerdì\n");
  break;
  
  
  case 6:
  printf("Sabato\n");
  break;
  
  case 7:
  printf("Domenica\n");
  break;
  
  default:
  printf("Numero non valido\n");
  }
  
  return 0;
  
}