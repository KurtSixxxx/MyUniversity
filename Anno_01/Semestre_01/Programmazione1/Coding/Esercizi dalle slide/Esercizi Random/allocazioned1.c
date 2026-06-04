#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(const char *string){
    
    if(string == NULL){ //Controllo se la stringa è nulla
    return false;
    }

    int len = strlen(string); //prelevo la lunghezza della stringa

    int i = 0, j = len - 1; //inizializzo i contatori da utilizzare nel loop di controllo palindrome
  
    while(i < j){ //finchè i è minore di j
      if(string[i] != string[j]){ //Se la lettera i è diversa dalla lettera j ritorna falso
        return false; //non palindroma
      }
        i++; //Incremento per iterare su tutta la stringa
        j--;
}

return true; //Se è palindroma ritorno true
}

bool palMatrix(char ***mat, int n, int m){ //Funzione che conta il numero di righe e colonne palindrome
    int rowPal[n]; //Contatore di righe
    int colPal[m]; //Contatore di colonne
    for (int i = 0; i < n; i++) rowPal[i] = 0; //Inizializzo le righe
    for (int j = 0; j < m; j++) colPal[j] = 0; //Inizializzo le colonne

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(is_palindrome(mat[i][j])){
          rowPal[i]++;
          colPal[j]++;
        }
      }
    }

for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(rowPal[i] == colPal[j]){
        return true;
        }
    }
}
    return false;
}


int main(){
    int n = 3, m = 3; 
    char ***matrix = malloc(sizeof(char**) * n);

    for(int i = 0; i < n; i++){
        matrix[i] = malloc(sizeof(char*) * m);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrix[i][j] = malloc(sizeof(char) * 8);
        }
    }

char buffer[10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Inserisci la parola per la posizione [%d][%d]: ", i, j);
            scanf("%9s", buffer);
            strcpy(matrix[i][j], buffer);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < m; j++) {
            printf("%s ", matrix[i][j]);
        }
    }
    
    printf("\n");
    printf("\n");
    
    bool risultato = palMatrix(matrix, n, m);
    printf("La matrice contiene un egual numero di stringhe palindrome?\n");
    printf("%s\n", risultato ? "true" : "false");

    for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        free(matrix[i][j]);
    }
    free(matrix[i]);
}
free(matrix);


    return 0;
}