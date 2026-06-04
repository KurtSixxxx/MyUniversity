#include <stdio.h>
#include <math.h>

int main(){

int p = 0;
printf("Inserire un numero qualunque p: ");
scanf("%d", &p);
if(p < 1){
    fprintf(stderr, "Il numero p non può essere minore di 1.\n");
    return 1;
}else if(p >= 1){
    ceil(p);
}

int arr1[p];
int arr2[p];
int arr3[p];
int i = 0;

printf("Array 1:\n ");
for(i = 0; i < p; i++){
    printf("Inserisci un valore: ");
    scanf("%d", &arr1[i]);
}
printf("\n");
i = 0;
printf("Array 2:\n ");
while(i < p){
    printf("Inserisci un valore: ");
    scanf("%d", &arr2[i]);
    i++;
}
printf("\n");
i = 0;
printf("Array 3:\n ");
do{
    printf("Inserisci un valore: ");
    scanf("%d", &arr3[i]);
    i++;
}while(i < p);
printf("\n");
i = 0;
printf("Stampa array 1:\n ");
for(i = 0; i < p; i++){
    printf("%d ", arr1[i]);
}
printf("\n");
i = 0;
printf("\nStampa array 2:\n ");
while(i < p){
    printf("%d ", arr2[i]);
    i++;
}
printf("\n");
i = 0;
printf("\nStampa array 3:\n ");
do{
    printf("%d ", arr3[i]);
    i++;
}while(i < p);
printf("\n");

return 0;
}