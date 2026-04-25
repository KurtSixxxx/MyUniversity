// Chiedere all'utente di inserire un numero intero N e stampare i primi N numeri naturali utilizzando un ciclo for.

 #include <stdio.h>

 int main (){

    int N;

    printf("Inserire un numero intero: ");
    scanf("%d", &N);

    for ( int i = 1; i <= N; i++) {
        
        printf("%d ", i);

    }

return 0;

 }