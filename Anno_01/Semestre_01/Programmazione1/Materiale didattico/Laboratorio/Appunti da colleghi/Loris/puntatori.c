#include <stdio.h>
#include <stdlib.h>

int main(){
    int x = 7;
    int *ptr=&x;
    printf("%d\n", x);     //puntatore ad elemento
    printf("%p\n", &x);    //puntatore alla cella
    printf("%p\n", ptr);   //puntatore alla cella
    printf("%d\n", *ptr);  //puntatore ad elemento

    printf("\n");

    int y[4]={2,4,8,10};     //vari puntatori di array
    printf("%p\n", y);
    printf("%p\n", &y[0]); //puntatore alla cella di memoria del primo elemento
    printf("%p\n", &y[1]);
    printf("%p\n", &y[2]);
    printf("%p\n", &y[3]);
    printf("%d\n", y[0]);  //puntatore al primo elemento, scrivere y[0] o *y è la stessa cosa, perché entrambi puntano al primo elemento
    printf("%d\n", *y);
    printf("%d\n", y[1]);
    printf("%d\n", y[2]);
    printf("%d\n", y[3]);
}