// Chiedere all'utente di inserire un numero intero N e stampare la tabella di moltiplicazione da 1 a N utilizzando un ciclo for annidato.

#include <stdio.h>

int main (){

int N;

printf("Inserisci un numero intero: ");
scanf("%d", &N);

for (int riga = 1; riga <= N; riga++){
    for (int colonna = 1; colonna <= N; colonna++){
    printf("%d * %d = %d\n", riga, colonna, riga * colonna);
}
printf("\n");
}

return 0;
}