//Esercizio 2: Allocazine e Liberazione di una Matrice Dinamica

#include <stdio.h>
#include <stdlib.h>

int main(){
    //Dichiaro due variabili intere righe e colonne
    int righe, colonne;

    //Chiedo all'utente di inserire il numero di righe e colonne
    printf("Inserisci il numero di righe e colonne per una matrice.\n");
    printf("Inserisci il numero di righe: \n");
    scanf("%d", &righe);
    printf("Inserisci il numero di colonne: \n");
    scanf("%d", &colonne);

    //Alloco la memoria dinamica
int **matrice = (int**)malloc(righe * sizeof(int*));
if(matrice == NULL){
    printf("L'allocazione non è andata a buon fine.\n");
    return 1;
}

for(int i = 0; i < righe; i++){
    matrice[i] = (int*)malloc(colonne * sizeof(int));
if(matrice[i] == NULL){
    printf("Errore di allocazione per la riga %d.\n", i);
    return 1;
  }  
}

    //Inserisco i valori
printf("Inserisci i valori per la matrice:\n");
for(int i = 0; i < righe; i++){
    for(int j = 0; j < colonne; j++){
        scanf("%d", &matrice[i][j]);
    }
}

    //Stampo la matrice
printf("Matrice inserita:\n");
for(int i = 0; i < righe; i++){
    for(int j = 0; j < colonne; j++){
        printf("[%d]", matrice[i][j]);
    }
    printf("\n");
}

    //Libero la memoria allocata
for(int i = 0; i < righe; i++){
    free(matrice[i]);//Libero ogni riga
}
free(matrice);  //Libero l'array di puntatori

return 0;
}