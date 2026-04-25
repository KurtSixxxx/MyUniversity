#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char str[] = "Giulio";
    char buffer[100];

    // Apri un file in modalità scrittura e lettura
    fp = fopen("test.txt", "w+");
    if (fp == NULL) {
        printf("Errore durante l'apertura del file!\n");
        return 1;
    }

    // Scrivi una stringa nel file
    fprintf(fp, "%s", str);

    // Riporta il puntatore all'inizio del file
    fseek(fp, 0, SEEK_SET);

    // Leggi il contenuto del file
    fread(buffer, sizeof(char), sizeof(str), fp);
    printf("Contenuto del file: %s\n", buffer);

    // Sposta il puntatore a 6 byte dall'inizio
    fseek(fp, 2, SEEK_SET);
    
    // Leggi il contenuto dal punto attuale
    fread(buffer, sizeof(char), sizeof(str) - 6, fp);
    printf("Contenuto dal sesto byte: %s\n", buffer);

    fclose(fp); // Chiudi il file
    return 0;
}