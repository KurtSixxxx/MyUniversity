#include <stdio.h>
#include <float.h>
#define MAX 100
#define MIN 1
#define STRINGA "Messaggio di prova"


int main(){
    /*dichiarazione: tipo_di_dato nome_variabile [=valore che vogliamo dare];
    ne esistono varie, tipo char(%c), unsigned char(%c), short int(%hd), unsigned short int(%hu), int(%d), unsigned int(%u),
    long int(%ld), unsigned long int(%lu), long long int(%lld), unsigned long long int(%llu), float(%f), double(%f), long double(%f)
    e sono disposte in base alla loro grandezza.

    Ci sono vari modi per chiamare una costante:
    la prima è con #define NOME_COSTANTE e Valore;
    la seconda è con const[TIPO][NOME][=valore]*/
    const int lato1 = 5;
    int area, lato2 = 5;
    area = lato1 * lato2;

    printf ("\nL'area del quadrato: %d", area);

    const double numero1 = 12.867;
    double numero2 = 34.53;
    double prodotto;

    prodotto = numero1 * numero2;
    printf("\nIl prodotto: %f", prodotto);
    /*la terza è con enum NOME_IDENTIFICATORE{
        COSTANTE_1 = [=valore];
        COSTANTE_2 = [=valore];
        ecc...
        e serve a numerare gli elementi dati da te
    }
    enum mesi{
        GEN, FEB, MAR, APR, MAG, GIU, LUG, AGO, SET, OTT, NOV, DIC //identificatori
    };
    printf("%s %d", "\nGennaio:", GEN);
    printf("%s %d","\nAprile:", APR);
    printf("%s %d","\nDicembre:", DIC);*/

    enum mesi{
        GEN=1, FEB, MAR,
        APR, MAG, GIU, 
        LUG, AGO, SET, 
        OTT, NOV, DIC //identificatori, se diamo il valore al primo, gli altri si sistemeranno in base al valore dato
    };
    printf("%s %d", "\nGennaio:", GEN);
    printf("%s %d","\nAprile:", APR);
    printf("%s %d","\nDicembre:", DIC);
}