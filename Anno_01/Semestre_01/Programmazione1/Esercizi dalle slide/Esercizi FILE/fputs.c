#include <stdio.h>
#include <stdlib.h>

int main(){
    char nome[20];
    int ore;
    char *stringa = "abracadabra";
    char carattere = 'c';

    FILE *fp;
    fp = fopen("studiamo.txt", "a");

    if(fp == NULL){
        perror("ERRORE: ");
        //oppure
        //fprintf(stderr, "Errore nell'apertura del file")
        exit(1);
    }else{
        printf("File aperto con successo.\n");
    }

    while (1){ //Il ciclo while esegue un blocco di codice finché la condizione specificata è vera. Nella sintassi while (1), la condizione è 1. In molti linguaggi di programmazione, il valore 1 è interpretato come "vero" in un contesto booleano. Poiché la condizione 1 è sempre vera, il ciclo non termina mai da solo. 

        printf("Inserisci il nome: ");
        scanf("%s", nome);

        printf("Inserisci quante ore hai studiato: ");
        scanf("%d", &ore);

        printf("\n");

        if(ore <= 0){
            break;
        }

        fprintf(fp, "Nome: %s \t Ha studiato per '%d' ore\n", nome, ore);
    }

    fputs(stringa, fp); //test di fputs: scrive una stringa presente in un buffer dentro un file. Parametri: stringa e puntatore a FILE
    fprintf(fp, "\n");
    fputc(carattere, fp); //test di fputc: scrive un carattere dentro un file. Parametri: char e puntatore a FILE

    fclose(fp);
    printf("File chiuso.");

    return 0;
}