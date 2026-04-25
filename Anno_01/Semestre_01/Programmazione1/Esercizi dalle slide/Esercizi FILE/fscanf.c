#include <stdio.h>
#include <stdlib.h>

int main(){
    int codice;
    
    printf("Apro il file\n");
    FILE *file_handle = fopen("mio_file.txt", "r");

    if(file_handle == NULL){
        perror("ERRORE: ");
        exit(1);
    }else{
        printf("File aperto con successo.\n");
    }

    fscanf(file_handle, "%d", &codice);
    printf("Codice trovato: %d\n", codice);

    fclose(file_handle);
    printf("File chiuso");

    return 0;
}