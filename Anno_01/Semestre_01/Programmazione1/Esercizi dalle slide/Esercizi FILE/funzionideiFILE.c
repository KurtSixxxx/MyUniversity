//*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*//
//*                                                         *//
//*         Operazioni sui FILE in linguaggio C             *//
//*         -----------------------------------             *//
//*         Tutte le funzioni utili all'esame               *//
//*                                                         *//
//*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*//

#include <stdio.h>
#include <stdlib.h>

/* MODALITA' DI APERTURA DEI FILE
Principali modalità di apertura (testuali)
"r" (Read): Apre un file esistente in modalità lettura. Se il file non esiste, si verifica un errore. 
"w" (Write): Crea un nuovo file in modalità scrittura. Se il file esiste, il suo contenuto viene cancellato. 
"a" (Append): Apre un file esistente o lo crea se non esiste, e posiziona il punto di scrittura alla fine del file per aggiungere dati.

Modalità combinate (testuali)
"r+": Apre un file sia in lettura che in scrittura. Il file deve esistere. 
"w+": Apre o crea un file in modalità lettura/scrittura, sovrascrivendone il contenuto se esiste. 
"a+": Apre o crea un file (se non esiste) in modalità lettura/scrittura, posizionando il cursore alla fine. 

Modalità binarie
Per lavorare con file binari (che non sono testo, come immagini o dati grezzi), si aggiunge una "b" alle modalità. 
"rb": Apre un file binario in lettura.
"wb": Crea un file binario per la scrittura.
"ab": Apre un file binario o lo crea per aggiungere dati alla fine.
"rb+", "wb+", "ab+": Combinazioni per la lettura/scrittura di file binari.
*/

////----------------------------------------------------------------------------------------------------------------------

//Come creare un file
//  1. fopen()
    FILE *fp = fopen("nomefile.txt" "w");

/*Questo è un esempio di apertura di un file
FILE è il tipo di dato
fp è il puntatore che ci permette di interagire con il file
fopen() è la funzione che ci permette di aprire un file.
Parametri: fopen("nomefile.txt" "modalità di apertura");
"Nome del file" seguito dall'estensione (solitamente .txt o .bin per i file binari)
"modalità di apertura" w, r, a, w+, r+ */

////-----------------------------------------------------------------------------------------------------------------------

// 2. fclose()
    fclose(fp)

/*Tutto qui, si passa solo il puntatore del file e si chiude.*/

////-----------------------------------------------------------------------------------------------------------------------

//  3. fscanf()
    fscanf(fp, "%d", &codice);

/*Questo è un esempio di scansione del testo in un file.
Il file deve essere creato, infatti il programma non funziona se il file non esiste e avviamo in modalità r per poi usare fscanf
ipotizziamo di aver inserito un codice all'interno del file. fscanf scansiona il file e vede se trova il valore inserito in 'codice'.
Parametri: fscanf(puntatore, "%specificatore", &indirizzo variabile);
*/

////-----------------------------------------------------------------------------------------------------------------------

// 4. fprintf()
    fprintf(fp, "Nome: %s \t Ha studiato per '%d' ore\n", nome, ore);

/*Fa quello che fa una solita printf ma lo inserisce in un file
Parametri: fprintf("puntatore, Testo + eventuali specificatori, eventuali varibili da associare agli specificatori")*/

////-----------------------------------------------------------------------------------------------------------------------

// 5. fputs() e fputc()
    char *stringa = "abracadabra";
    char carattere = 'c';

    fputs(stringa, fp); //Scrive una stringa presente in un buffer dentro un file.
                        //Parametri: stringa e puntatore a FILE
    fputc(carattere, fp); //Scrive un carattere dentro un file. 
                        //Parametri: char e puntatore a FILE

////-----------------------------------------------------------------------------------------------------------------------

//6. fgetc() e fgets()
    char buffer[100];
    int countCiao = 0;

    while(fgets(buffer, 100, fp) != NULL){
        if(strstr(buffer, "ciao") != NULL) countCiao++;
    }

    printf("Numbers of 'ciao': %d\n", countCiao);

/*In questo esempio abbiamo usato fgets per vedere quante volte è contenuta la parola 'ciao' in ogni linea del file.
Perchè fgets, con la S, si occupa di esaminare le righe di un file
Il while dice: finché fgets è diverso da NULL cerca i 'ciao' nel file.
Parametri: fgets(nome del buffer, dimensione del buffer, puntatore al file)*/

    int ch;
    while ((ch = fgetc(fp)) != EOF){
         if (isupper(ch)) countMaiuscole++;
         if (ch == ' ') countSpazi++;
         if (ch == '\n') countRighe++;
        } 

/*In questo esempio stiamo usando fgetc() per vedere carattere per carattere del file, fino alla fine (infatti EOF sarebbe EndOfFile), se il carattere corrispondente corrisponde al carattere cercato.
Bisogna chiamare fgetch dentro un intero e passare solo il puntatore al FILE*/

////-----------------------------------------------------------------------------------------------------------------------

// 7. fwrite() e fread()

    struct Contatto rubrica[DIM];

    printf("Inserimento dei contatti...\n");

    for(int i = 0; i < DIM; i++){
        printf("\n");
        printf("Contatto [%d]\n", i + 1);
        rubrica[i].id = i + 1;

        printf("Inserisci il nome: ");
        scanf("%s", rubrica[i].nome);
        

        printf("Inserisci il numero di telefono: ");
        scanf("%s", rubrica[i].numero);
    }
    
    FILE *fp = fopen("filestruct.bin", "wb");
    
    for(int i = 0; i < DIM; i++) fwrite(&rubrica[i], sizeof(struct Contatto), 1, fp); //!

/*In questo esempio volevamo scrivere una serie di struct Contatto e scrivere il contenuto in un file BINARIO. E' molto solito usare questa funzione per i file binari (.bin)
Quindi scrive n elementi, ognuno grande size, presi da ptr, scritti nel file.
Parametri:
fwrite(*ptr, sizeof(), numb of elem, fp);
ptr è il buffer dove i dati saranno scritti, in questo caso una struct chiamata rubrica di tipo struct Contatto
sizeof() è la dimensione di quello che dobbiamo scrivere, in questo caso sizeof(struct Contatto)
numb of elem è naturalmente il numero di elementi di quel tipo che vogliamo scrivere
fp è il puntatore al file.*/

     FILE *fp2 = fopen("filestruct.bin", "rb");

    struct Contatto letti[DIM];
    for(int i = 0; i < DIM; i++) fread(&letti[i], sizeof(struct Contatto), 1, fp2);

    printf("Contatti letti:\n");
    for(int i = 0; i < DIM; i++){
        printf("Contatto [%d] | Nome: %s | Numero: %s\n", letti[i].id, letti[i].nome, letti[i].numero);
    }

/*In questo esempio volevamo leggere dati da un file binario, ossia i dati scritti con la funzione di prima, fwrite.
Abbiamo creato una struct Contatto chiamataa letti di dimenisione [DIM], quindi un array di struct.
E abbiamo iterato per tutte le DIM struct che avevamo, ossia 3.
Abbiamo la stessa sintassi e gli stessi parametri di fwrite ma bbiamo cambiato il puntatore iniziale e quello finale per leggere appunto.*/

////-----------------------------------------------------------------------------------------------------------------------

// 8. fseek()

////-----------------------------------------------------------------------------------------------------------------------

// 8. fseek()
    fseek(fp, 0, SEEK_SET); // Torna all'inizio del file
    fseek(fp, sizeof(struct Contatto) * 2, SEEK_SET); // Salta ai byte del terzo contatto

/*fseek serve per spostare il cursore (puntatore interno) in un file, a una determinata posizione.
Parametri: fseek(puntatore, offset in byte, riferimento);
offset = quanti byte ci spostiamo
riferimento = da dove partiamo a contare
   SEEK_SET → dall’inizio
   SEEK_CUR → dalla posizione attuale
   SEEK_END → dalla fine del file
Esempio classico: saltare direttamente al terzo elemento di un array di struct nel file binario.*/

////-----------------------------------------------------------------------------------------------------------------------

// 9. ftell()
    long posizione = ftell(fp);
    printf("Il cursore si trova al byte numero: %ld\n", posizione);

/*ftell restituisce la posizione corrente del cursore nel file.
Parametri: ftell(puntatore);
Ritorna un numero long che rappresenta la posizione (in byte) dall’inizio del file.*/

////-----------------------------------------------------------------------------------------------------------------------

// 10. rewind()
    rewind(fp);

/*Rewind è un modo veloce per riportare il cursore all’inizio del file.
È equivalente a fseek(fp, 0, SEEK_SET);
Si passa solo il puntatore.*/

////-----------------------------------------------------------------------------------------------------------------------

// 11. feof()
    while (fgetc(fp) != EOF); // legge fino a fine file
    if (feof(fp)) printf("Hai raggiunto la fine del file.\n");

/*feof controlla se abbiamo raggiunto la fine del file.
Parametri: feof(puntatore);
Attenzione! feof va usato DOPO che hai tentato di leggere oltre l’ultima riga.*/

////-----------------------------------------------------------------------------------------------------------------------

// 12. ferror()
    FILE *fp3 = fopen("inesistente.txt", "r");
    if (fp3 == NULL || ferror(fp3)) perror("Errore nell'apertura del file");

/*ferror verifica se si è verificato un errore di input/output sul file.
Parametri: ferror(puntatore); 
Ritorna vero (diverso da zero) se si è verificato un errore.*/

////-----------------------------------------------------------------------------------------------------------------------

// 13. clearerr()
    clearerr(fp);  // Pulisce errori e stato di fine-file (EOF)
    rewind(fp);

/*clearerr resetta i flag di errore ed EOF del file.
Dopo aver raggiunto la fine del file o causato un errore, puoi pulire lo stato con questa funzione.
Parametri: clearerr(puntatore);*/

////-----------------------------------------------------------------------------------------------------------------------

// 14. fflush()
    fprintf(fp, "Messaggio importante\n");
    fflush(fp);  // Scrive subito il contenuto del buffer nel file

/*fflush forza lo svuotamento del buffer in memoria e scrive subito i dati sul file.
Parametri: fflush(puntatore);
Utile quando vogliamo assicurarci che i dati siano davvero scritti nel file, anche se non abbiamo ancora chiamato fclose.*/
