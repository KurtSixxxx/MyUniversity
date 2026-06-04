/*1) Definire alcune variabili intere con nomi a piacimento: 
    - short 
    - unsigned int 
    - long
    
    a) assegnare alcuni valori a piacimento, stampare tali valori 
    mediante la funzione di libreria printf() e gli specificatori 
    di formato %hd, %u, %ld rispettivamente. 

    b) codificare istruzioni che permettano di aggiornare le variabili per ottenere overflow (sommare opportuni valori). In particolare: 
      - overflow positivo per lo short 
      - overflow per la variabile unsigned 
      - overflow negativo per la variabile long 

    c)  stampare dunque i risultato con la funzione printf e gli 
      specificatori di formato citati in precedenza.

2) Definire una variabile float x ed una double y. 
  Inserire istruzioni tali che: 
   a) alla variabile x sia assegnato il valore 10882000; 
   b) alla variabile y sia assegnato il prodotto di x per 
   il letterale 1.23456*10^100, quest'ultimo 
    espresso in notazione scientifica

3) Stampare le variabili x e y mediante una istruzione printf: 
   a) in notazione scientifica (specificatore %e/%E) 
   b) inoltre specificando di stampare 6 cifre dopo la virgola  

4) Moltiplicare x per un numero in virgola mobile tale che 
   si ottenga un overflow negativo. Stampare il risultato
   mediante una istruzione printf (e specificatore di formato %f) 

5) Moltiplicare y per un numero tale che si ottenga un overflow positivo. 
   Stampare il risultato mediante una istruzione printf (e specificatore di
    formato %f). 

6) Definire due variabili intere con valori vicini o uguali al massimo numero rappresentabile. 
   a) Sommare le due variabili assegnando il risultato ad una terza variabile intera, stampare il risultato; 
   b) Sommare le due variabili assegnando il risultato ad una variabile di tipo long, e stampare il risultato; 

7) Consultare la documentazione relativa al file header limits.h, stampare quindi il range (valore minimo e valore massimo) del tipo "long long"; 

8) Stampare il valore restituito dall'operatore sizeof per il tipo long ed il tipo "long long"; 

9) Calcolare e stampare il valore delle seguenti espressioni in VIRGOLA MOBILE
   a) sin^2(x) + cos^2(y), x e y variabili con valore a piacere
   b) definire tre variabili in virgola mobile che rappresentano 
   la misura di due cateti di un triangolo rettangolo. Calcolare 
   l'ipotenusa del triangolo; 
   c) Dato il valore del r di un cerchio, calcolare circonferenza e 
   area del cerchio; usare la costante M_PI definita nel file header math.h (non fa parte della libreria standard ma molte "extensioni" la introducono)
   d) (2+3)/2 * 7/4 + 8.8. Impiegare eventuali espressioni di type-cast, senza cambiare i letterali, al fine di ottenere un risultato senza alcuna perdita di informazioni;  
   e) Sia x un numero in virgola mobile a piacere. Stampare il risultato dell'espressione x/0 - x/0; 
   f) e, e^100, e^300, e^400; 
   g) sia x un valore in virgola mobile, x<1. Sia y un valore in virgola mobile, y>1. Stampare x^10, x^100, x^300, y^10, y^100, y^300.*/

   #include <stdio.h>
   #include <limits.h>
   #include <math.h>

   int main(){
    short a = 32767;
    unsigned int b = UINT_MAX;
    long c = LONG_MIN;

    printf("Stampo a: %hd\n", a);
    printf("Stampo b: %u\n", b);
    printf("Stampo c: %ld\n",c);
    //Stampa con overflow
    printf("Stampo a con overflow: %hd\n", a + 1); 
    printf("Stampo b con overflow: %u\n", b + 1);
    printf("Stampo c con overflow: %ld\n", c -1);

    float x = 10882000;
    double y = x * 1.23456e100;
    printf("Float in notazione scientifica minuscola: %.6e\n", x);
    printf("Float in notazione scientifica maiuscola: %.6E\n", x);
    printf("Double in notazione scientifica minuscola: %.6e\n", y);
    printf("Double in notazione scientifica maiuscola: %.6E\n", y);

    printf("X moltiplicato al fine di overlow negativo: %f\n", x * -1e32);
    printf("Y moltiplicato al fine di overlow positivo: %f\n", y * 1e308);

    int grande = 2136373536;
    int uguale = 2147483647;
    int risultato1 = grande + uguale;
    long risultato2 = grande + uguale;
    printf("Interi sommati in int: %d\n", risultato1);
    printf("Interi sommati in long: %ld\n", risultato2);

    printf("Massimo valore del tipo long long: %lld\n", LLONG_MAX);
    printf("Sizeof Long: %zu\n", sizeof(long));
    printf("Sizeof LongLong: %zu\n", sizeof (long long));

   /*
   g) sia x un valore in virgola mobile, x<1. Sia y un valore in virgola mobile, y>1. Stampare x^10, x^100, x^300, y^10, y^100, y^300.*/

   int x1 = 10, y2 = 23;
   double risultato = pow(sin(x1), 2) + pow(cos(y2), 2);
   double c1 = 12.5, c2 = 5.6;
   double ipotenusa = sqrt(c1 * c1 + c2 * c2);
   int r = 8;
   double circonferenza = 2 * r * M_PI;
   double area = M_PI * r * r;

   printf("Risultato di seno e coseno: %.5f\n", risultato);
   printf("Ipotenusa: %f\n", ipotenusa);
   printf("Circonferenza: %.5f\n", circonferenza);
   printf("Area: %.5f\n", area);

   double typecast = (double)(2+3)/2 * 7/4 + 8.8;
   printf("Type-Cast: %f\n", typecast);

   double xx = 34.42;
   printf("X in virgola mobile: %f\n", xx/0 - xx/0);

    printf("e: %.10f\n", M_E);
    printf("e^100: %e\n", exp(100));
    printf("e^300: %e\n", exp(300));
    printf("e^400: %e\n", exp(400));

double x_1 = 0.5;
double y_1 = 1.5;
printf("x^10: %.10e\n", pow(x_1, 10));
printf("x^100: %.10e\n", pow(x_1, 100));
printf("x^300: %.10e\n", pow(x_1, 300));
printf("y^10: %.10e\n", pow(y_1, 10));
printf("y^100: %.10e\n", pow(y_1, 100));
printf("y^300: %.10e\n", pow(y_1, 300));

   return 0;
   }