#include <stdio.h>

#define DIM 10


int main(){ 

  int A[DIM] = {}; //tutti a zero!
  int B[DIM]= {0}; // tutti a zero! 
  float C[DIM] = {0.2, 0.3, 0.4}; //i restanti saranno inizializzati a zero!

  //array di caratteri
  char c[] = "pippo"; 
  c[3] = 'z'; 
  char d[10] = {'a', 'b'}; // i restanti saranno caratteri '\0', ASCII = 0

  printf("\nc=%s, d=%s\n", c, d);

  for(int i=0; i<10; i++)
    printf("\nd[i]=%c, (int) d[i]=%d", d[i], (int) d[i]);

  int V[DIM] = {1,2,3,4,5}; //V[5], V[6], ...? 

  printf("V[5]=%d", V[5]);

    printf("\n\n");  

  int W[DIM] = {};
  int Z[DIM]; //nessuna inizializzazione!!

  for(int i=0; i<DIM; i++){
    printf("\nW[%d]=%d", i, W[i]);
    printf("\nZ[%d]=%d", i, Z[i]);
  }
}
