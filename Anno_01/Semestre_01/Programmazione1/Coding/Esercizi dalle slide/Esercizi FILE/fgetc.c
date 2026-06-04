#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    FILE *fp = fopen("testo.txt", "r");
    
    int ch;
    int countMaiuscole = 0; 
    int countSpazi = 0;
    int countRighe = 0;
    
    if(fp == NULL){
        perror("ERRORE: ");
        exit(-1); 
    }else{ 
        printf("File aperto con successo.\n");
    } 
    
    while ((ch = fgetc(fp)) != EOF){
         if (isupper(ch)) countMaiuscole++;
         if (ch == ' ') countSpazi++;
         if (ch == '\n') countRighe++;
        } 
        
        printf("Maiuscole: %d\n", countMaiuscole);
        printf("Spazi: %d\n", countSpazi);
        printf("Righe: %d\n", countRighe);
        
        fclose(fp);
        printf("File chiuso.\n");
        
        return 0;
    
}