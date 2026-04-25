#include <stdio.h>
#include <stdlib.h>

int main(){
    int codice;
    printf("Inserisci il codice: ");
    scanf("%d", &codice);

    FILE *file_handle = fopen("mio_file.txt", "w");

    if(file_handle == NULL){
        perror("ERRORE: ");
        exit(1);
    }else{
        printf("File aperto con successo.\n");
    }

    fprintf(file_handle, "%d", codice);
    printf("Hai scritto '%d' nel file 'mio_file.txt'\n", codice);

    fclose(file_handle);
    printf("File chiuso.");

    return 0;
}