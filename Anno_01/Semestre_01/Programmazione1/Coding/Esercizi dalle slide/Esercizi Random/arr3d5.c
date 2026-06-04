/*
Consegna:
- Dichiara un array 3D di dimensione [2][3][3].
- Chiedi all'utente un numero intero N.
- Riempi l'array con i multipli di N, partendo da N e continuando (N, 2N, 3N, ...),
  fino a riempire tutti i 18 spazi.
- Stampa l'array mostrando i valori piano per piano.
  Esempio: se N = 5, l'array conterrà 5, 10, 15, 20, ... fino a 90.
*/

#include <stdio.h>
int main(){
  int a[2][3][3];
  int n;
  printf("Inserire un numero intero N: ");
  scanf("%d", &n);
    
  //Inserire gli elementi
  int cont = 1;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                  a[i][j][k] = n * cont;
                  cont++;
               }
            }
        }

    //Stampare valori:
    for(int i = 0; i < 2; i++){
        printf("Piano %d\n", i+1);
        for(int j = 0; j < 3; j++){
            printf("|");
            for(int k = 0; k < 3; k++){
                printf("%d|", a[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

  return 0;
}