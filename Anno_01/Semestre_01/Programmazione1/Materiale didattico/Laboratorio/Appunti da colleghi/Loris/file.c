#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    FILE *f=fopen("input.txt", "a");
    if(f==NULL){
        fprintf(stderr, "Errore ! Il file non esiste");
        exit(EXIT_FAILURE);
    }
    int n=5;
    int m=6;
    srand(time(NULL));

    int **A=malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        A[i]=malloc(sizeof(int)*m);
        for(int j=0;j<m;j++){
            A[i][j]=rand()%10;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            fprintf(f, "%d ", A[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
}