#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int valoreAssolutoMatrice(int n, int a[n][n]){
        //Dichiariamo 2 array 1D dove salvare i valori delle medie
        int d1[n];
        int d2[n];
        //Dichiariamo una variabile 'mediaD1' dove fare la media della diagonale principale e facciamo la stessa cosa per la diagonale secondaria
        double mediaD1 = 0, mediaD2 = 0;
        //Dichiariamo due variabili "valoriD1" e "valoriD2" dove raccogliamo i valori raccolti da ogni diagonale
        int valoriD1 = 0, valoriD2 = 0;
        //Troviamo la diagonale principale
        for(int i = 0; i < n; i++){
            valoriD1 = 0; //Qui la azzero per evitare problemi di calcolo
            if(i == i){
                d1[i] = a[i][i];
                valoriD1 += d1[i];
            }
        }

        //Troviamo la diagonale secondaria
        for(int i = 0; i < n; i++){
            valoriD2 = 0;
            d2[i] = a[i][n - 1 - i]; //Formula per trovare solo i valori della diagonale secondaria
            valoriD2 += d2[i];
        }
        /*(double)mediaD1 = valoriD1 / n; //calcoliamo la media della diagonale principale
        (double)mediaD2 = valoriD2 / n; //calcoliamo la media della diagonale secondaria*/

        mediaD1 = valoriD1 / n; //calcoliamo la media della diagonale principale
        mediaD2 = valoriD2 / n; //calcoliamo la media della diagonale secondaria

        double differenza = mediaD1 - mediaD2; //facciamo la differenza

        //Ora ci occupiamo del valore assoluto
        int risultato = 0;
       if(differenza < 0){ 
		risultato = -differenza; 
	    } else {
		risultato = differenza;
        }

    return risultato;
}


int main(){
    srand(time(0));

    int n = 5;
    int a[n][n];
    //range 2-10
    for(int i = 0; i < 5; i++){
        a[i] = rand()%(10 - 2 + 1) + 2;
    }

    int valore_assoluto = valoreAssolutoMatrice(n, a);
    printf("%d", valore_assoluto);

    return 0;
}