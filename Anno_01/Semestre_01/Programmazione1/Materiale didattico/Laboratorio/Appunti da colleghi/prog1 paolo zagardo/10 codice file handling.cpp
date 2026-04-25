#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char buffer[100];
    int i = 10;
    char str[] = "Hello, World!";
    size_t result;
    
    // 1. Apertura del file in modalità scrittura (se non esiste viene creato)
    fptr = fopen("filename.txt", "w");
    if (fptr == NULL) {
        perror("Error opening file");
        return -1;
    }

    // 2. Scrittura di una stringa nel file
    fputs(str, fptr);
    fprintf(fptr, "%d.%s\n", i, " Example String");
    fputc('A', fptr);

    // 3. Chiusura del file
    fclose(fptr);

    // 4. Ri-apertura del file in modalità lettura
    fptr = fopen("filename.txt", "r");
    if (fptr == NULL) {
        perror("Error opening file");
        return -1;
    }

    // 5. Lettura di una riga dal file e memorizzazione nel buffer
    if (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        printf("Read line: %s", buffer);
    }

    // 6. Utilizzo di fseek per spostare il puntatore all'inizio del file
    fseek(fptr, 0, SEEK_SET);

    // 7. Lettura di un singolo carattere dal file
    int c = fgetc(fptr);
    if (c != EOF) {
        printf("First character: %c\n", c);
    }

    // 8. Lettura di dati dal file in modalità binaria
    fclose(fptr);
    fptr = fopen("filename.txt", "rb");
    if (fptr == NULL) {
        perror("Error opening file");
        return -1;
    }
    result = fread(buffer, 1, sizeof(buffer) - 1, fptr);
    if (result > 0) {
        buffer[result] = '\0'; // Aggiungi il terminatore di stringa
        printf("Binary read: %s\n", buffer);
    }

    // 9. Utilizzo di rewind per spostare il puntatore all'inizio del file
    rewind(fptr);

    // 10. Utilizzo di fscanf per leggere dati formattati dal file
    int num;
    char str_read[50];
    if (fscanf(fptr, "%d.%s", &num, str_read) == 2) {
        printf("Formatted read: %d %s\n", num, str_read);
    }

    // 11. Chiusura del file
    fclose(fptr);

    return 0;
}

