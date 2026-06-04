/*Codificare una funzione in C che prenda in input due array di caratteri. FATTO
La funzione restituisca un risultato intero che rappresenta il confronto lessicografico tra le due stringhe (siano s1 ed s2 le due stringhe):
-1 se s1 < s2; FATTO
1 se s1 > s2; FATTO
0 se s1 = s2; FATTO

NB: Specificare opportunamente tipo ed eventuali qualificatori dei parametri formali: i parametri formali dovranno/potranno essere (char *) oppure (char *)? ?????
Perchè?
NB2: Per il calcolo della lunghezza della stringhe, usare la funzione del precedente esercizio. FATTO
*/

#include <stdio.h>

int controllo_lessicografico(const char *s1, const char *s2) {
    int i = 0;

    while((s1[i] != '\0') && (s2[i] != '\0')){
        if(s1[i] < s2[i]){
            return -1;
                }else if(s1[i] > s2[i]){
                    return 1;
                    }
                    i++;
    }
    return 0;
}

int main(){
    int valore;

    char e[] = "cane";
    char f[] = "gatto"; 
    valore = controllo_lessicografico(e, f);
    printf("%d\n", valore); //output atteso 1

    char a[] = "cane"; 
    char b[] = "cane"; 
    valore = controllo_lessicografico(a, b);
    printf("%d\n", valore); //output atteso 0

    char c[] = "gatto";
    char d[] = "cane"; 
    valore = controllo_lessicografico(c, d);
    printf("%d\n", valore); //output atteso -1

    char x[] = "casa";
    char z[] = "case"; 
    valore = controllo_lessicografico(x, z);
    printf("%d\n", valore); //output atteso 1

    return 0;
}