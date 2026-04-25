#include <stdio.h>

#define DIM 10
#define N 3
#define M 4

int main(){ 

  int A[DIM][DIM]; //matrice quadrata DIM x DIM elementi

  for(int i=0; i<DIM; i++)
    for(int j=0; j<DIM; j++)
      printf("\nA[%d][%d]=%d", i, j, A[i][j]);

  printf("\n\n"); 

  int B[DIM][DIM] = {0}; //tutti gli elementi a zero!

  for(int i=0; i<DIM; i++)
    for(int j=0; j<DIM; j++)
      printf("\nB[%d][%d]=%d", i, j, B[i][j]);

  printf("\n\n"); 

  int C[N][M] = {1,2,3,4,5,6,7,8,9,10,11,12};

  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      printf("\nC[%d][%d]=%d", i, j, C[i][j]);

  printf("\n\n"); 

  int D[N][M] = {1,2,3,4,5}; //inizializzazione parziale

  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      printf("\nD[%d][%d]=%d", i, j, D[i][j]);

  printf("\n\n"); 
    
  //int E[][] = {1,2,3,4,5,6,7,8,9,10,11,12};  ??? 
  //NO! Il compilatore non riesce a calcolare le dimensioni 

  //OK
  int F[][M] =   {1,2,3,4,5,6,7,8,9,10,11,12};  // 3x 4

  int G[][M] = {1,2,3,4,5,6,7,8,9,10};  //quante righe? 3x4 

  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      printf("\nF[%d][%d]=%d / G[%d][%d]=%d", i, j, F[i][j], i, j, G[i][j]);

}
