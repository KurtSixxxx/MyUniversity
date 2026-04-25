#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    //allocazione dinamica di un array
    int N = 3;
    float *M=malloc(sizeof(float)*N);
    for (int i=0; i<N; i++){
        printf("Inserisci un numero:");
        scanf("%f", &M[i]);  //da non dimenticare & perché stiamo parlando di interi/float/double comunque numeri
    }

    //allocazione dinamica di una matrice
    int a = 3;
    int b = 4;
    int **N=malloc(sizeof(int*)*a);  //doppio puntatore perché si tratta di una matrice
    for (int i=0; i<a; i++){
        N[i]=malloc(sizeof(int)*b);
        for(int j=0; j<b; j++){
            N[i][j]=i+j+1;
            printf("%d", N[i][j]);
        }
        printf("\n");
    }
    
    //allocazione dinamica di una stringa
    int N=5;
    char **M=malloc(sizeof(char*)*N); //creazione dei blocchi ove inserire le stringhe/caratteri di stringhe
    for(int i=0;i<N;i++){
        M[i]=malloc(sizeof(char)*21); //il 21 è simbolico, mettiamo in realtà il numero massimo +1 che serve per occupare meno memoria possibile
        scanf("%s", M[i]);
        printf("%s", M[i]);
    }
    free(M);

    //allocazione dinamica di una matrice di stringhe
    char ***A=malloc(sizeof(char**)*n);   
    for(int i=0;i<n;i++){
        A[i]=malloc(sizeof(char*)*m);
        for(int j=0;j<m;j++){
            A[i][j]=
            printf("A[%d][%d]=%s\n", i, j, A[i][j]);
        }
    }

    free(A);
}