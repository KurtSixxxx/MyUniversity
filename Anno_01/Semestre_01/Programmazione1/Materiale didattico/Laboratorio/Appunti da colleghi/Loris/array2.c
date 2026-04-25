#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
inizializzare una matrice N × M con numeri in virgola mobile
 scelti a caso;
 calcolare e stampare il prodotto di un numero scelto a caso
 (es: 3.542) con la matrice;
 definire una ulteriore matrice quadrata N × N, in cui
 N =min(N,M). ES: per una matrice 8x9 le dimensioni della
 nuova matrice saranno 8x8;
 riempire la nuova matrice con i corrispondenti elementi della
 prima matrice.*/

int main(){
    float N;
    float M;
    float molt;
    srand(time(0));

    printf("Inserire il primo valore N:\n");  //inserimento dei due valori da parte dell'utente
    scanf("%f", &N);
    if(N<0){                         //controllo dei due valori inseriti
        printf("Errore! Il numero deve essere maggiore di 1:\n");
        printf("Inserire un numero maggiore di 1:\n");
        scanf("%f", &N);
    }

    printf("Inserire il secondo valore M:\n");
    scanf("%f", &M);
    if(M<0){
        printf("Errore! Il numero deve essere maggiore di 1:\n");
        printf("Inserire un numero maggiore di 1:\n");
        scanf("%f", &M);
    }

    float **matrice= (float*)malloc(sizeof(float)*N); //allocazione dinamica
    for(int i=0;i<N;i++){
        matrice[i]=(float*)malloc(sizeof(float)*M);
        for(int j=0;j<M;j++){
            matrice[i][j]=(float)rand()/RAND_MAX;
            printf("\nMatrice[%d][%d]=%.3f", i, j, matrice[i][j]);
        }
    }

    printf("\nInserire un numero per moltiplicarlo con la matrice:"); //prodotto
    scanf("%f", &molt);
    printf("\nMatrice moltiplicata:");
    for (int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            matrice[i][j]*=molt;
            printf("\n%.3f", matrice[i][j]);
        }
        printf("\n");
    }
    
    float min = N<M ? N:M;                            //calcolo del minimo
    float **matrice2= (float*)malloc(sizeof(float)*min);
    for(int i=0;i<min;i++){
        matrice2[i]=(float*)malloc(sizeof(float)*min);
        for(int j=0;j<min;j++){   
            matrice2[i][j]=(float)rand()/RAND_MAX;
            printf("\nNuova matrice[%d][%d]=%.3f", i, j, matrice2[i][j]);
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            matrice[i][j]=matrice2[i][j];
            printf("\nElementi della prima matrice nella seconda matrice: [%d][%d]=%.3f", i, j, matrice[i][j]);
        }
    }
}