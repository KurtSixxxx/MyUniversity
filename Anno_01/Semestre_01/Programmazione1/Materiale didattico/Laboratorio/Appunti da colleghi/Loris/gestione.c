#include <stdio.h>

int main(){
    /*putchar("\n a");ha lo scopo di stampare il carattere in codice ASCII e lo restituisce in output come intero, ma questo nel compito non viene utilizzato*/

    /*printf("esempio di prova"); ha lo scopo di stampare e mettere in output il suo contenuto per come si trova
    può anche mostrare il contenuto di altri variabili dimostrate prima, come ad esempio %d (per i numeri interi), %c (per i caratteri)
    %f per i numeri in virgola mobile, %s (per le stringhe)*/
    printf ("\nLa somma 10+5 risulta %d", 10+5);
    printf ("\nLa somma %d+%d risulta %d", 34, 92, 34+92);

    puts("Hello world"); /* stampa la stringa e si preferisce solo quando non si hanno da inserire specifiche di conversione %d es.*/

    /*esistono vari tipi di sequenze di escape, dimostrazione omessa al momento*/

    /* Ci sono varie specifiche di conversione:
    quelle che interessano di più sono %2d per dimostrare solo i primi due numeri o %3d se ne vogliamo 3, nel caso dei numeri in virgola mobile
    basta fare %.3f se si vogliono in output solo i primi 3 numeri dopo la virgola*/
}

