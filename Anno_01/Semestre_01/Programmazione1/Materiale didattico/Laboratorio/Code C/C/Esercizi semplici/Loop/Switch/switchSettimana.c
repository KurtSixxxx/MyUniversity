#include <stdio.h>
#include <locale.h>

int main (){

setlocale (LC_ALL, "it_IT.UTF8");
int giornoX;

printf("Inserire un numero, sarà convertito al giorno corrispondente: ");
scanf("%d", &giornoX);

switch (giornoX){

case 1:
printf("Lunedì");
break;

case 2:
printf("Martedì");
break;

case 3:
printf("Mercoledì");
break;

case 4:
printf("Giovedì");
break;

case 5:
printf("Venerdì");
break;

case 6:
printf("Sabato");
break;

case 7:
printf("Domenica");
break;

default:
printf("Valore non valido");
}

    return 0;
}