#include <stdio.h>

#define N 5
#define TASSO 0.1 

int main(){

    double capitale = 1000.0; 
    
    unsigned anno=0; 
    unsigned numeroIterazioni=0;
    // A
    while(anno++<N){
        capitale+=capitale*TASSO;
        numeroIterazioni++;
    }

    printf("\n A-Capitale dopo %d anni: %f", anno, capitale); 
    printf("\n A-Numero di iterazioni: %d", numeroIterazioni);

    // B 
    anno = 0; 
    numeroIterazioni=0;
    capitale = 1000.0;  
    
    while(++anno<N){
        capitale+=capitale*TASSO;
        numeroIterazioni++;
    }

    printf("\n B-Capitale dopo %d anni: %f", anno, capitale); 
    printf("\n B-Numero di iterazioni: %d", numeroIterazioni); 

    capitale = 1000.0;
    anno=0; 
    numeroIterazioni=0;
    // C
    while(anno<N){
        capitale+=capitale*TASSO;
        anno++;
        numeroIterazioni++;
    }

    printf("\n C-Capitale dopo %d anni: %f", anno, capitale); 
    printf("\n C-Numero di iterazioni: %d", numeroIterazioni); 
}