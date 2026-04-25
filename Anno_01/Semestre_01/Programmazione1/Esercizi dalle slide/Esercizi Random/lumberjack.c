#include <stdio.h>
#include <string.h>
int main(){

//Dati in input dell'utente:
float lunghezza; //In metri, o in cm ma si deve convertire in metri
float carico; //Il carico in kg che ogni piano deve sopportare
char ambiente[20];

int zero = 0;
float b_castagno = 0.018;
float b_pino = 0.02;
float p_castagno = 0.02;
float p_pino = 0.022;
float q_castagno = 1.1; //per >100 kg, altrimenti q = 1.0
float q_pino = 1.2; //per >80gk, altrimenti q = 1.0
float q = 1.0;
float s;
float max;

printf("Scegli l'ambiente (Interno/Esterno): ");
scanf("%s", ambiente);
printf("\n");
if(strcmp(ambiente, "esterno") == 0 || strcmp(ambiente, "Esterno") == 0){
    printf("Hai scelto il legno di castagno.\n");
}else if(strcmp(ambiente, "interno") == 0 || strcmp(ambiente, "Interno") == 0){
    printf("Hai scelto il legno di pino.\n");
}else{
    printf("Risposta non valida.\n");
    return 1;
}

printf("\n");

printf("Scegli la lunghezza del tuo scaffale: ");
scanf("%f", &lunghezza);
lunghezza = lunghezza / 100; //conversione da cm a metri
printf("Hai scelto: %.2fm.\n", lunghezza);

printf("\nE infine, scegli il peso del carico che il piano deve sopportare: ");
scanf("%f", &carico);
printf("Hai scelto: %.2fkg.\n", carico);

printf("\nCalcolo...\n");

//Formula: s = [b + max(0, L-1) * p] * q

if((strcmp(ambiente, "esterno") == 0 || strcmp(ambiente, "Esterno") == 0) && carico > 100){
    max = (0 > lunghezza - 1) ? 0 : lunghezza - 1;
    s = (b_castagno + max * p_castagno) * q_castagno;

}else if(((strcmp(ambiente, "esterno") == 0 || strcmp(ambiente, "Esterno") == 0) && carico <= 100)){
    max = (0 > lunghezza - 1) ? 0 : lunghezza - 1;
    s = (b_castagno + max * p_castagno) * q;
}else if(((strcmp(ambiente, "interno") == 0 || strcmp(ambiente, "Interno") == 0) && carico > 80)){
    max = (0 > lunghezza - 1) ? 0 : lunghezza - 1;
    s = (b_pino + max * p_pino) * q_pino;
}else if(((strcmp(ambiente, "interno") == 0 || strcmp(ambiente, "interno") == 0) && carico <= 80)){
    max = (0 > lunghezza - 1) ? 0 : lunghezza - 1;
    s = (b_pino + max * p_pino) * q;
}
printf("Lo spessore del ripiano sara': %.3f", s);

return 0;
}