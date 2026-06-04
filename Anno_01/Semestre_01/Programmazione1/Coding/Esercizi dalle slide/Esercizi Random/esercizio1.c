/*
Codificare in linguaggio C un programma che stampi a ritroso la sequenza di caratteri da ’a’ a ’z’, ma non le vocali.
Codificare due versioni differenti nelle quali si fa uso del costrutto for e del costrutto while rispettivamente.

Estendere l’esercizio precedente in modo da conservare tutti i caratteri in un array di caratteri.
Infine, stampare la lunghezza della stringa contenuta in esso con la funzione di libreria strlen.
*/

#include <stdio.h>
#include <string.h> //Uso della libreria string per la funzione strlen.
int main(){

    char arr[22]; //Inizializzazione dell'array in cui salvare i caratteri.
    int pos = 0;

    printf("Versione 'for': \n");
    for(char c = 'z'; c >= 'a'; c--){ //Inizializzazione del for
       if(c == 'a'||c == 'e'||c == 'i'||c == 'o'||c == 'u'){ //Esclusione delle vocali dalla lista
          continue;                                          //Se il carattere è una vocale continua (ignorala)
       }
       arr[pos] = c;
       pos++;

      printf("%c\t", c);                                     //Stampa il carattere
    }

    arr[pos] = '\0'; //Serve a dire a 'strlen' dove termina la stringa.

    printf("\n");
    printf("Stampa dei caratteri nell'array: \n"); 
    for(int i = 0; i < pos; i++){                    //Stampa dell'array
        printf("%c ", arr[i]);
    }

    printf("\n");
    printf("Array: %s\n", arr);
    printf("Lunghezza della stringa: %zu", strlen(arr));
    

    return 0;
}