/*
1. Inserisci valori in una matrice 3x3 e stampa la matrice.
2. Calcola la somma di ogni riga e la somma di ogni colonna in una matrice 3x3.
3. Trova il valore massimo in una matrice 4x4.
4. Data una matrice 3x3, stampa la diagonale principale (es. elementi [0][0], [1][1], [2][2]).
5. Verifica se una matrice 3x3 è simmetrica (cioè a[i][j] == a[j][i]).
*/

#include <stdio.h>
#include <stdbool.h>
int main(){
   
   int inserito;
   int arr[3][3];
   
   //Inserisci i valori di una matrice
   for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
         printf("Inserisci un elemento: ");
         scanf("%d", &inserito);
         arr[i][j] = inserito;
      }
   }
   
   //Stampa la matrice
   for(int i = 0; i < 3; i++){
      printf("\n");
      for(int j = 0; j < 3; j++){
         printf("%d|", arr[i][j]);
      }
   }
   
   //Calcola la somma di ogni riga e la somma di ogni colonna in una matrice 3x3
      for(int i = 0; i < 3; i++){
         int sommaRiga = 0;
         int sommaColonna = 0;
            for(int j = 0; j < 3; j++){
               sommaRiga += arr[i][j];   // riga i
               sommaColonna += arr[j][i]; // colonna i
      }
      printf("Somma riga %d = %d\n", i, sommaRiga);
      printf("Somma colonna %d = %d\n", i, sommaColonna);
   }

   
    // 3. Stampa la diagonale principale in diagonale
    printf("\nDiagonale principale:\n");
    for (int i = 0; i < 3; i++) {
        // stampa spazi per "spostare" il numero
        for (int s = 0; s < i * 3; s++) {
            printf(" ");
        }
        // stampa l'elemento della diagonale
        printf("%d\n", arr[i][i]);
      }

   //Controlliamo se la matrice è simmetrica
   bool simmetrica = true; 
   for(int i = 0; i < 3 && simmetrica; i++){
      for(int j = 0; j < 3; j++){
         if(arr[i][j] != arr[j][i]){
            simmetrica = false;
            break; 
         }
      }
   }

   if(simmetrica){
      printf("\nLa matrice è simmetrica.\n");
   }else{
      printf("\nLa matrice NON è simmetrica.\n");
   }

   //Trova il valore massimo in una matrice 4x4.
      int arr1[4][4];
      int num;
      
      //Riempiamo l'array
      for(int i = 0; i < 4; i++){
         for(int j = 0; j < 4; j++){
            printf("Inserisci un valore: ");
            scanf("%d", &num);
            arr1[i][j] = num;
         }
      }
      
      //Ora lo stampiamo
      for(int i = 0; i < 4; i++){
         printf("\n");
         for(int j = 0; j < 4; j++){
            printf("%d|", arr1[i][j]);
         }
      }
      
      //infine troviamo il massimo
      int max = arr1[0][0];
      for(int i = 0; i < 4; i++){
         for(int j = 0; j < 4; j++){
            if(max < arr1[i][j]){
               max = arr1[i][j];
            }
         }
      }
      
      printf("\n");
      printf("\nMassimo = %d", max);
   
   
   return 0;
    }
