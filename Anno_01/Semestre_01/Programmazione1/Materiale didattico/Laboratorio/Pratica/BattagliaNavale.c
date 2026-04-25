/* Battaglia Navale */

//Inclusione delle librerie necessarie
#include <stdio.h>  //Normale procedura di inclusione
#include <stdlib.h> //Per la generazione di numeri psuedocasuali e l'utilizzo di funzioni come rand()
#include <time.h>   //Per la generazione del seme con time(NULL)

//Define di alcuni valori necessari: dimensioni massime e minime della tabella, ...
#define MIN_T 1
#define MAX_T 10
#define ACQUA '~'
#define NAVE '#'
#define COLPITO 'X'
#define MANCATO 'O'

/*void file_partita(){
    int scelta;
    switch(scelta)
    {
        case 1:
        
        
    }
}*/

//Qui andranno le funzioni
void menu_principale(char* nome, int* dim){
    
    printf("Benvenuto.\nInserisci il nome per giocare: \n");
    scanf("%s", nome);

    printf("Adesso inseriamo i valori della tabella, ricorda che:\n");
    printf("Minimo '1' \t Massimo '10'\n ");
    printf("Inserisci la dimenione della tabella: ");
    scanf("%d", dim);
    
    if(*dim == MIN_T){
        fprintf(stderr, "Valore non valido, la dimensione '1' non è disposnibile");
        menu_principale(char* nome, int* dim);
    }else if(*dim > MAX_T){
        fprintf(stderr, "Valore non valido, la dimensione successiva a '10' non è disponibile");
        menu_principale(char* nome, int* dim);
    }else if(*dim < MIN_T || *dim > MAX_T){
        fprintf(stderr, "Valore non valido, il range disponibile è [2, 10]");
        menu_principale(char* nome, int* dim);
    }
}

//Fase 1: Chiedere le informazioni all'utente
int main(){

    //Dichiarazione di variabili: nome e dimensine
    char nome[50];
    int dim;



    menu_principale(nome, &dim);  //Chiamata alla funzione menù

    return 0;
}