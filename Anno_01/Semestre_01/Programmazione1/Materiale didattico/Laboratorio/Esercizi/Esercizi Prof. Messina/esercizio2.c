// 8) Calcolare e stampare il valore delle seguenti espressioni in VIRGOLA MOBILE
//   a) sin^2(x) + cos^2(y), x e y variabili con valore a piacere
//   b) definire tre variabili in virgola mobile che rappresentano la misura di due cateti di un triangolo rettangolo.
//   Calcolare l'ipotenusa del triangolo; 
//   c) Dato il valore del raggio di un cerchio, calcolare circonferenza e 
//   area del cerchio; usare la costante M_PI definita nel file header math.h (non fa parte della libreria standard ma molte "extensioni" la introducono)
//   d) (2+3)/2 * 7/4 + 8.8. Impiegare eventuali espressioni di type-cast, senza cambiare i letterali, al fine di ottenere un risultato senza alcuna perdita di informazioni;  
//   e) Sia x un numero in virgola mobile a piacere. Stampare il risultato dell'espressione x/0 - x/0; 
//   f) e, e^100, e^300, e^400; 
//   g) sia x un valore in virgola mobile, x<1. Sia y un valore in virgola mobile, y>1. Stampare x^10, x^100, x^300, y^10, y^100, y^300.


#include <stdio.h>
#include <math.h>

int main () {

//ESECUZIONE PUNTO A:
float x = 2.3;
float y = 3.6;

//Utilizzo f alla fine delle funzioni pow e sin per indicare che lavoro con float.
float senQuadro = powf(sinf(x), 2);
float cosQuadro = powf(cosf(y), 2);

printf("sen^2(x) = %.2f\n", senQuadro);
printf("cos^2(y) = %.2f\n", cosQuadro);
//FINE ESECUZIONE PUNTO A.

//ESECUZIONE PUNTO B:
float cateto_A = 1.5;
float cateto_B = 3.2;

float ipotenusa = sqrtf((cateto_A * cateto_A)+(cateto_B * cateto_B));

printf("L'ipotenusa del triangolo rettangolo equivale a: %.2f \n", ipotenusa);
//FINE ESECUZIONE PUNTO B.

//ESECUZIONE PUNTO C:

//Definiamo il raggio a piacere in virgola mobile;
float r = 2.4;

//Calcoliamo l'area con la formula: A=πr 
float area = (M_PI * r);
printf("L'area del cerchio equivale a: %.2f\n", area);

//Calcoliamo la circonferenza con la formula: C=2πr
float circonferenza = (2 * M_PI * r);
printf("La circonfernza del cerchio equivale a: %.2f\n", circonferenza);
//FINE ESECUZIONE PUNTO C.

//ESECUZIONE PUNTO D
int a = (2+3)/2;
int b = 7/4;
float c = 8.8;

float risultato = (float)(a) + (float)(b) + c;
printf("Il risultato del punto D equivale a: %.1f \n", risultato);
//FINE ESECUZIONE PUNTO D

//ESECUZIONE PUNTO E
int x1 = 1234;
int risultato_x1 = (x1/0 - x1/0);

printf("Il risultato di x1/0 - x1/0 equivale a: %d \n", risultato_x1);

double e = exp(1.0);
double e_100 = exp(100);
double e_300 = exp(300);
double e_400 = exp(400);

printf ("Il risultato di e equivale a: %.2f \n", e);
printf ("Il risultato di e_100 equivale a: %.2e \n", e_100);
printf ("Il risultato di e_300 equivale a: %.2e \n", e_300);
printf ("Il risultato di e_400 equivale a: %.2e \n", e_400);

//FINE ESECUZIONE PUNTO E

//ESECUZIONE PUNTO F
float x_minore1 = 0.5;
float y_maggiore1 = 1.5;

    printf("Risultati x^10: %.2e\n", pow(x_minore1, 10));
    printf("Risultati x^100: %.2e\n", pow(x_minore1, 100));
    printf("Risultati x^300: %.2e\n", pow(x_minore1, 300));
    printf("Risultati y^10: %.2e\n", pow(y_maggiore1, 10));
    printf("Risultati y^100: %.2e\n", pow(y_maggiore1, 100));
    printf("Risultati y^300: %.2e\n", pow(y_maggiore1, 300));

//FINE ESECUZIONE E

return 0;

}
