#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*🧩 CONSEGNE – STRUCT + PUNTATORI
🔹 Esercizio 1 — Dichiarazione e utilizzo base
Crea una struct Studente con due campi: nome (stringa di massimo 30 caratteri) ed eta (intero).
Dichiara una variabile di tipo struct Studente, assegnale valori e stampali.
Obiettivo: capire come si accede ai campi di una struct con il punto (.).

🔹 Esercizio 2 — Passaggio per riferimento
Scrivi una funzione:
void stampa_studente(struct Studente *p);
che riceva il puntatore a uno studente e stampi i suoi dati.
Nel main, crea uno studente e passa il suo indirizzo alla funzione.
Obiettivo: imparare a usare l’operatore -> e comprendere la differenza tra s.nome e p->nome.

🔹 Esercizio 3 — Per valore vs per riferimento
Scrivi due funzioni:
void cambia_eta_valore(struct Studente s);
void cambia_eta_riferimento(struct Studente *s);
La prima modifica l’età dentro la funzione, la seconda tramite puntatore.
Verifica che solo la seconda abbia effetto nel main.
Obiettivo: comprendere che la struct passata per valore viene copiata.

🔹 Esercizio 4 — Array statico di struct
Crea un array statico di 3 studenti e riempi i loro dati direttamente nel codice.
Scrivi un ciclo che stampi tutti i nomi e le età.
Obiettivo: abituarsi a trattare array[i].campo.

🔹 Esercizio 5 — Array dinamico di struct
Scrivi una funzione:
struct Studente* crea_classe(int n);
che allochi dinamicamente un array di n studenti, chiedendo all’utente di inserire nome ed età.
Restituisci il puntatore all’array, poi nel main stampalo e libera la memoria.
Obiettivo: esercitarti con malloc, free e -> su array di struct.

🔹 Esercizio 6 — Struct con puntatore interno
Crea una struct Libro con due campi:
char *titolo
int pagine
Alloca dinamicamente la stringa titolo con malloc(50) e chiedi input all’utente.
Stampa il libro e libera la memoria.
Obiettivo: imparare a gestire campi di tipo puntatore dentro una struct.

🔹 Esercizio 7 — Funzione che restituisce una struct allocata
Scrivi:
struct Studente* nuovo_studente(const char *nome, int eta);
che allochi dinamicamente una struct, riempia i campi e restituisca il puntatore.
Nel main, crea più studenti e stampali.
Obiettivo: costruire e restituire struct dinamiche da funzioni.

🔹 Esercizio 8 — Struct dentro struct
Crea:
struct Universita {
    char nome[30];
    struct Studente *studenti;
    int numero_studenti;
};
Alloca studenti dinamicamente, riempi i dati e stampa tutto.
Obiettivo: capire la relazione “contenitore” tra struct.

🔹 Esercizio 9 — Ordinamento di struct
Dato un array di struct Studente, scrivi una funzione:
void ordina_eta(struct Studente *classe, int n);
che ordini gli studenti in base all’età (usa bubble sort o selection sort).
Obiettivo: imparare a scambiare intere struct o i loro campi tramite puntatori.

🔹 Esercizio 10 — Rubrica dinamica
Crea una struct Contatto { char nome[30]; char telefono[15]; }
Scrivi un piccolo programma che:
Allochi dinamicamente un array di contatti;
Permetta di aggiungere nuovi contatti;
Stampi tutti i contatti;
Libera la memoria.
Obiettivo: combinare tutto — input dinamico, array di struct, funzioni, memoria.

🔧 Istruzioni di lavoro
Per ogni esercizio: scrivi il codice, commenta ogni riga come hai fatto finora, spiegando il ragionamento.
Dopo 2–3 esercizi, me li incolli qui. Io te li correggo e ti spiego eventuali errori concettuali o inefficienze.
Quando arriviamo al 10, ti preparo una simulazione d’esame completa (tema a scelta del prof Messina).
*/

//Esercizio 1 — Dichiarazione e utilizzo base
/*struct Studente{
    char nome[10];
    int eta;
};

int main(){
    struct Studente studente1 = {"Giulio", 21};

    printf("Nome: %s\n", studente1.nome);
    printf("Eta: %d\n", studente1.eta);

    return 0;
}*/

//Esercizio 2 - Passaggio per riferimento
/*struct Studente{
    char nome[10];
    int eta;
};

void stampa_studente(struct Studente *p){
    printf("Nome: %s\n", p->nome);
    printf("Eta: %d\n", p->eta);
}

int main(){
    struct Studente s1 = {"Piero", 20};
    stampa_studente(&s1); //Passo l'indirizzo

    return 0;
}*/

//Esercizio 3 - Per valore vs riferimento
/*struct Studente{
    char nome[10];
    int eta;
};

void stampa_studente(struct Studente *p){
    printf("Nome: %s\n", p->nome);
    printf("Eta: %d\n", p->eta);
}

void cambia_eta_valore(struct Studente s){
    s.eta = 13; //13 come valore esempio
}
void cambia_eta_riferimento(struct Studente *s){
    s->eta = 100;
}  

int main(){
    struct Studente s2 = {"Carlo", 5};
    cambia_eta_valore(s2);
    cambia_eta_riferimento(&s2);
    stampa_studente(&s2);
}*/

//Esercizio 4 — Array statico di struct
/*struct Studente{
    char nome[10];
    int eta;
};

int main(){
struct Studente s4[3] = {{"Enrico", 20}, {"Giulio", 21}, {"Paolo", 19}};

for(int i = 0; i < 3; i++){
    printf("Struct numero %d \t", i+1);
    printf("Nome: %s\t", s4[i].nome);
    printf("Eta: %d\n", s4[i].eta);
}

return 0;
}*/

//Esercizio 5 — Array dinamico di struct
/*struct Studente{ //Dichiaro la struct con i suoi due campi
    char nome[10];
    int eta;
};

void stampa_struct(int n, struct Studente *p){ //Funzione di stampa, accetta il numero di strutture da stampare e la struttura da stampare (per riferimento)
    printf("--------------------------------------\n");
    for(int i = 0; i < n; i++){
        printf("Nome: %s\n", p[i].nome);
        printf("Eta: %d\n", p[i].eta);
        if(i == 2) break;
        printf("\n");
    }
    printf("--------------------------------------\n");
}

struct Studente* crea_classe (int n){ //Funzione che alloca n struct
    struct Studente *classe = malloc(sizeof(struct Studente) * n);

    if(classe == NULL){
        printf("Allocazione fallita.\n");
        exit(-1);
    }
    
    for(int i = 0; i < n; i++){
        printf("Inserisci il nome per la struct numero %d: ", i+1);
        scanf("%s", classe[i].nome);
        printf("Inserisci l'eta per la struct numero %d: ", i+1);
        scanf("%d", &classe[i].eta);
               printf("\n");
    }

    return classe;
}

int main(){
    int n = 3;
    struct Studente *s5 = crea_classe(3); //creo un puntatore a struct per chiamare la funzione per 3 struct 
    stampa_struct(3, s5); //Stampo
    free(s5); //libero memoria

return 0;
}
*/

//Esercizio 6 - 
/*struct Libro{
    char *titolo; //E' una stringa
    int pagine; //Il numero di pagine

};

int main(){
    struct Libro mylibro; //dichiariamo una struttura chiamata myLibro
    mylibro.titolo = malloc(sizeof(char) * 50); //allochiamo spazio per una stinga titolo di 50 char nella struttura myLibro

    if(mylibro.titolo == NULL){ //verifica di allocazione
        printf("Allocazione fallita.\n");
        exit(-1);
    }

    printf("Inserisci il titolo: ");
    fgets(mylibro.titolo, 50, stdin); //Per evitare errori con lo spazio di una stringa usiamo fgets, che impone anche un limite
    int len = strlen(mylibro.titolo);
    if(mylibro.titolo[len-1] == '\n'){
        mylibro.titolo[len-1] = '\0';
    }
    printf("Inserisci il numero di pagine: ");
    scanf("%d", &mylibro.pagine); //Memorizziamo il valore intero nel campo pagine

    printf("Titolo: %s \t Numero pagine: %d", mylibro.titolo, mylibro.pagine); //stampiamo tutto
    free(mylibro.titolo); //liberiamo la memoria allocata per la stringa

return 0;
}*/

//Esercizio 7 - Funzione che ritorna puntatore a struct
/*struct Studente{ //Creo la struct Studente che contiene i due campi
    char nome[10];
    int eta;
};

struct Studente* crea_studente(const char *nome, int eta){ //Creo la funzione che prende una stringa costante (quindi non modificabile) e un intero come parametri
    struct Studente* s = malloc(sizeof(struct Studente)); //alloco in memoria lo studente
    if(s == NULL){ //controllo che sia stato allocato
        printf("Allocazione fallita.\n");
        exit(-1);
    }
    strcpy(s->nome, nome); //copio, nel campo nome di s, il nome passato come parametro
    s->eta = eta; //faccio lo stesso con l'eta
    return s; //ritorno il puntatore alla struct
}

int main(){
    struct Studente* s1 = crea_studente("Giulio", 21); //chiamo la funzione per la mia struct
    printf("Studente: '%s' \t Eta: %d", s1->nome, s1->eta); //stampo il contenuto della mia struct. e datp che s1 è un puntatore a struct uso l'arrow operator
    free(s1); //libero la memoria per lo studente allocato
    return 0;
}
*/

//Esercizio 8 - Puntatore a struct dentro un'altra struct
//per comodità, d'ora in poi, preferisco usare typedef
/*typedef struct{
    char nome[10];
    int eta;
}Studente;

typedef struct{
    char nome[30];
    Studente* studenti;
    int numero_studenti;
}Universita;

int main(){
    //Creiamo un array di tipo Studente che contiene 3 studenti 
    Studente studenti[3] = {{"Giulio", 21}, {"Paolo", 20}, {"Cristian", 19}};

    //Ora creiamo un università e inseriamo i nostri 3 studenti
   Universita uni = {"UniCT", studenti, 3};

    printf("Universita\n");
    printf("------------------\n");
    printf("Nome: %s\n", uni.nome);
    printf("Lista degli studenti:\n");
    for(int i = 0; i < 3; i++){
        printf("Studente numero %d:\n", i+1);
        printf("Nome: %s \t", studenti[i].nome);
        printf("Eta: %d\n", studenti[i].eta);
        printf("\n");
    }
    printf("Numero studenti: %d\n", uni.numero_studenti);
    printf("------------------\n");

    return 0;
}*/

//Esercizio 9 — Ordinamento di struct 