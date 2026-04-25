/*
Il programma dovra stampare l’importo totale dell’ordine aggiornato in base alle seguenti specifiche:
A Se l’importo dell’ordine e’ minore o uguale a 100 euro, applica uno sconto del 10%.

B Se l’importo dell’ordine e’ maggiore di 100 euro e minore o uguale a 1000 euro, allora
    B1 se l’utente possiede la tessera cliente applica uno sconto del 20%
        B2 se l’utente non possiede la tessera cliente:
            B21 se ad uno o piu’ articoli e’ stato applicato un prezzo promozionale, applica uno sconto del 15%;
            B22 altrimenti applica uno sconto del 18%;

C Se l’importo dell’ordine e’ maggiore di 1000 euro applica uno sconto del 30% alla differenza tra l’importo totale dell’ordine e 1000 euro. 

Applica gli sconti previsti al punto B sui rimanenti 1000 euro.
*/

#include <stdio.h>
#include <stdbool.h>

#define  SCONTO_A 0.10
#define  SCONTO_B1 0.20
#define  SCONTO_B21 0.15
#define  SCONTO_B22 0.18
#define  SCONTO_C 0.30
#define  YES 'Y'
#define  NO 'N'

int main(){
    float importo = 0;
    int scelte[100];
    int scelta;
    int i = 0;
    char continua = 'Y';
    char risposta;
    bool tessera;
    bool almenoUnoPromo = false;

    printf(" ________   ___  ___   ________   ________   ________   ___   ________    ________     \n");
    printf("|\\   ____\\ |\\  \\|\\  \\ |\\   __  \\ |\\   __  \\ |\\   __  \\ |\\  \\ |\\   ___  \\ |\\   ____\\    \n");
    printf("\\ \\  \\___|_\\ \\  \\\\\\  \\\\ \\  \\|\\  \\\\ \\  \\|\\  \\\\ \\  \\|\\  \\\\ \\  \\\\ \\  \\\\ \\  \\\\ \\  \\___|    \n");
    printf(" \\ \\_____  \\\\ \\   __  \\\\ \\  \\\\\\  \\\\ \\   ____\\\\ \\   ____\\\\ \\  \\\\ \\  \\\\ \\  \\\\ \\  \\  ___  \n");
    printf("  \\|____|\\  \\\\ \\  \\ \\  \\\\ \\  \\\\\\  \\\\ \\  \\___| \\ \\  \\___| \\ \\  \\\\ \\  \\\\ \\  \\\\ \\  \\|\\  \\ \n");
    printf("    ____\\_\\  \\\\ \\__\\ \\__\\\\ \\_______\\\\ \\__\\     \\ \\__\\     \\ \\__\\\\ \\__\\\\ \\__\\\\ \\_______\\\n");
    printf("   |\\_________\\\\|__|\\|__| \\|_______| \\|__|      \\|__|      \\|__| \\|__| \\|__| \\|_______|\n");
    printf("   \\|_________|                                                                        \n");
    printf("                                                                                       \n");
    printf("                                                                                       \n");
    printf(" ________   ________           ________   ________                                     \n");
    printf("|\\   __  \\ |\\   ___  \\        |\\   __  \\ |\\   ____\\                                    \n");
    printf("\\ \\  \\|\\  \\\\ \\  \\\\ \\  \\       \\ \\  \\|\\  \\\\ \\  \\___|                                    \n");
    printf(" \\ \\  \\\\\\  \\\\ \\  \\\\ \\  \\       \\ \\   ____\\\\ \\  \\                                       \n");
    printf("  \\ \\  \\\\\\  \\\\ \\  \\\\ \\  \\       \\ \\  \\___| \\ \\  \\____                                  \n");
    printf("   \\ \\_______\\\\ \\__\\\\ \\__\\       \\ \\__\\     \\ \\_______\n");
    printf("    \\|_______| \\|__| \\|__|        \\|__|      \\|_______|\n");
    printf("                                                                                       \n");
    printf("                                                                                       \n");

    printf("\n");
    printf("___________________________________________________________________________________________________________________________________");
    printf("\n");

    printf("Scegli i prodotti tramite il numero: ");
    printf("\n");
    printf("1. Maglietta | 20 euro  | No promo\n");
    printf("2. Pantaloni | 30 euro  | No promo\n");
    printf("3. Cintura   | 15 euro  | Si promo\n");
    printf("4. Scarpe    | 120 euro | Si promo\n");
    printf("5. Giacca    | 200 euro | No promo\n");
    printf("6. Orologio  | 850 euro | No promo\n");
    printf("7. Borsa     | 500 euro | Si promo\n");
    printf("\n");

    while(continua == 'Y' || continua == 'y'){
            printf("Inserisci una scelta (numero): ");
            scanf(" %d", &scelta);

        scelte[i] = scelta;

    switch(scelta){
        case 1:
        printf("Hai scelto 'maglietta'\n");
        importo += 20;
        break;

        case 2:
        printf("Hai scelto 'pantaloni'\n");
        importo += 30;
        break;

        case 3:
        printf("Hai scelto 'cintura'\n");
        importo += 15;
        almenoUnoPromo = true;
        break;

        case 4:
        printf("Hai scelto 'scarpe'\n");
        importo += 120;
        almenoUnoPromo = true;
        break;
        
        case 5:
        printf("Hai scelto 'giacca'\n");
        importo += 250;
        break;
    
        case 6:
        printf("Hai scelto 'orologio'\n");
        importo += 850;
        break;

        case 7:
        printf("Hai scelto 'borsa'\n");
        importo += 500;
        almenoUnoPromo = true;
        break;

        default:
        printf("Articolo inesistente.\n");
        break;
    }

    i++;

    printf("Vuoi continuare con le scelte? (Y/N)\n");
    scanf(" %c", &continua);
    }

    printf("Al momento la tua spesa equivale a %.2f euro.\n", importo);

    printf("Hai la tessera? (Y/N)\n");
    scanf(" %c", &risposta);
    
    if(risposta == 'Y' || risposta == 'y'){
        tessera = true;
        printf("Conferma di attivazione tessera.\n");
    }else{
        tessera = false;
        printf("Nessuna tessera.\n");
    }


    float tot_scontato;

    if (importo <= 100) {
    tot_scontato = importo * (1 - SCONTO_A);
    } 
    else if (importo > 100 && importo <= 1000) {
    if (tessera) {
        tot_scontato = importo * (1 - SCONTO_B1);
    } else if (almenoUnoPromo) {
        tot_scontato = importo * (1 - SCONTO_B21);
    } else {
        tot_scontato = importo * (1 - SCONTO_B22);
    }
        } 
    else if (importo > 1000) {
    int parte_bassa = 1000;
    int parte_alta = importo - 1000;

    // Sconto 30% sulla parte sopra i 1000
    float sconto_alta = parte_alta * (1 - SCONTO_C);

    // Sconto su 1000 euro secondo le regole del punto B
    float sconto_bassa;
    if (tessera) {
        sconto_bassa = parte_bassa * (1 - SCONTO_B1);
    } else if (almenoUnoPromo) {
        sconto_bassa = parte_bassa * (1 - SCONTO_B21);
    } else {
        sconto_bassa = parte_bassa * (1 - SCONTO_B22);
    }

    tot_scontato = sconto_alta + sconto_bassa;
}

    printf("Il tuo conto scontato è: %.2f euro\n", tot_scontato);

return 0;
}