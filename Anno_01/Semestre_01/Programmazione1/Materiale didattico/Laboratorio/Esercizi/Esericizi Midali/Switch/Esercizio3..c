/*
Chiedere all'utente di inserire un punteggio da 0 a 100 e convertirlo in una lettera di valutazione secondo la seguente tabella:
90-100: A 80-89: B 70-79: C 60-69: D 0-59: F
*/

#include <stdio.h>
int main (){
    
    int punteggio;
    char valutazione;
    
    printf("Inserisci il tuo punteggio: \n");
    scanf("%d", &punteggio);
    
    switch (punteggio / 10){
        
        case 10:
        case 9:
        valutazione = 'A';
        break;
        
        case 8:
        valutazione = 'B';
        break;
        
        case 7:
        valutazione = 'C';
        break;
        
        
        case 6:
        valutazione = 'D';
        break;
        
        default:
        valutazione = 'F';
        break;
        
    }
    
    printf("Il tuo punteggio corrisponde a: %c", valutazione);
    
    return 0;
}