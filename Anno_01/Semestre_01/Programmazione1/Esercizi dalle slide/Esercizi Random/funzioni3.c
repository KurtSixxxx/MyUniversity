//Codifica di una funzione che restituisce tutta la lunghezza della stringa meno gli spazi

#include <stdio.h>

int string_lenght(char *c) { //char *c poteva essere passato anche come char *c perché il nome di uno array è un puntatore costante al primo elemento dello array
    int count = 0; //variabile che conta i caratteri
    for(int i = 0; c[i] != '\0'; i++) { //itera finché c[i] è diverso da \0, quando lo incontra non itera più
        count++; //incrementiamo
        if(c[i] == ' ') { //se incontriamo uno spazio...
            --count;  // Decrementa solo se spazio
        }
    }
    return count;
}

int main(){
    char c[] = {"giulio casella"};
    int risultato = string_lenght(c);
    printf("%d", risultato);

    return 0;
}