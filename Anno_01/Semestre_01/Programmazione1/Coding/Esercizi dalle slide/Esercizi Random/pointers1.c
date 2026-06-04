/* Homework H14.1.
 *
 * Dichiarare ed inizializzare tre variabili, un double, uno short unsigned, ed
 * un char, assegnando valori a piacere.
 * Dichiarare altrettante variabili puntatore dello stesso tipo ed assegnare ad
 * essi gli indirizzi delle variabili dichiarate in precedenza.
 * Stampare, mediante la funzione di libreria printf() i valori contenuti
 * all’interno di tali variabili in due modi differenti:
 * i) mediante le variabili stesse e
 * ii) mediante le variabili puntatore.
 * Stampare, mediante printf(), i valori contenuti all’interno dei puntatori
 * (gli indirizzi di memoria).
 */

 #include <stdio.h>

 int main(){
    double d = 13.2;
    unsigned short su = 4;
    char c = 'a';

    double *p_d = &d;
    unsigned short *p_su = &su;
    char *p_c = &c;

    printf("Stampa dei valori\n");
    printf("Stampa dei valori mediante le variabili stesse\n");
    printf("Valore di double mediante variabile: %.1f\n", d);
    printf("Valore di short unsigned mediante variabile: %u\n", su);
    printf("Valore di char mediante variabile: '%c'\n", c);
printf("\n");
    printf("Stampa dei valori mediante i puntatori:\n");
    printf("Valore di double mediante puntatore: %.1f\n", *p_d);
    printf("Valore di short unsigned mediante puntatore: %hu\n", *p_su);
    printf("Valore di char mediante puntatore: %c\n", *p_c);
printf("\n");
    printf("Stampa degli indirizzi\n");
    printf("Stampa degli indirizzi mediante le variabili stesse:\n");
    printf("Indirizzo di double mediante variabile: %p\n", &d);
    printf("Indirizzo di short unsigned mediante variabile: %p\n", &su);
    printf("Indirizzo di char mediante variabile: %p\n", &c);
printf("\n");
    printf("Stampa degli indirizzi mediante i puntatori:\n");
    printf("Indirizzo di double mediante puntatore: %p\n", p_d);
    printf("Indirizzo di short unsigned mediante puntatore: %p\n", p_su);
    printf("Indirizzo di char mediante puntatore: %p\n", p_c);

    return 0;
 }