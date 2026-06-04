#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node{
    int data;
    struct node* next;
} Nodo;

void decodeParameters(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr, "[ERR]: Il numero di parametri richiesti è pari a 2.\n");
        exit(-1);
    }

    char* inputExtension = strstr(argv[1], "txt");
    if(inputExtension == NULL){
        fprintf(stderr, "[ERR]: Il file in input non ha l'estensione corretta. (.txt)\n");
        exit(-1);
    }

    if(strlen(argv[1]) > 100){
        fprintf(stderr, "[ERR]: La lunghezza massima del nome del file in input è pari a 100 caratteri.\n");
        exit(-1);
    }

    printf("Valori presi in input:\n");
    printf("Nome file in input: %s \t Numero totale di argomenti: %d", argv[1], argc);
}

int isEmpty(Nodo *top){
    return top == NULL;
}

void push(Nodo **top, int value){
    Nodo *new = malloc(sizeof(Nodo));
    if(new == NULL){
        fprintf(stderr, "[ERR]: Fallimento nel processo di allocazione nodo nello stack.\n");
        return;
    }

    if(isEmpty(*top)){
        new->data = value;
        new->next = NULL;
        *top = new;
        return;
    }

    new->next = *top;
    new->data = value;
    *top = new;
}

int pop(Nodo **top){
    if(isEmpty(*top)){
        fprintf(stderr, "[ERR]: Stack vuoto.\n");
        return -1;
    }

    Nodo *tmp = *top;
    int value = tmp->data;
    *top = tmp->next;
    free(tmp);
    return value;
}

void printStack(Nodo *top){
    if(isEmpty(top)){
        fprintf(stderr, "[ERR]: Errore nel processo di apertura file.\n");
        return;
    }

    Nodo *curr = top;
    printf("---STACK---\n");
    while(curr != NULL){
        printf("[ %d ]\n", curr->data);
        curr = curr->next;
    }
    printf("---NULL---\n");

}

void readFile(const char *fileName, Nodo **top){
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL){
        fprintf(stderr, "[ERR]: Fallimento nel processo di apertura file.\n");
        exit(-1);
    }

    int variable;
    while(fscanf(fp, "%d", &variable) == 1){
        push(top, variable);
        variable = 0;
    }

    fclose(fp);
}

double getMean(Nodo **top){
    double m = 0;
    int count = 0;

    while(!isEmpty(*top)){
        m += pop(top);
        count++;
    }

    if(count == 0) return 0;

    return m/count;
}

int countElem(Nodo *top){
    int count = 0;

    Nodo *curr = top;
    while(curr != NULL){
        count++;
        curr = curr->next;      
    }

    return count;
}

void fillP(const char *fileName, Nodo **top, int m){
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL){
        fprintf(stderr, "[ERR]: Fallimento nel processo di apertura file.\n");
        exit(-1);
    }

    int firstElem = 0; //Il primo valore letto viene inserito nella pila P.
    fscanf(fp, "%d", &firstElem);
    push(top, firstElem);

    //Dal secondo valore in poi:
    int x = 0;
    while((fscanf(fp, "%d", &x) == 1)){
        if(x > m){ //se il valore letto x > m
        push(top, x); //viene inserito nella pila
        x = 0; //e azzeriamo per evitare valori spazzatura
    }else{ //altrimenti
        int y = pop(top); //viene estratto l'elemento in cima
        push(top, (x + y)/2); // viene inserito nella pila il valore: (x + y) / 2
        }
    }
    fclose(fp);
}


int* transferP(Nodo *top, int N){
    int *arr = malloc(sizeof(int) * N);
    if(arr == NULL){
        fprintf(stderr, "[ERR]: Allocazione array fallita.\n");
        exit(-1);
    }
    
    Nodo *tmp = top;
    int i = 0;
    while(tmp != NULL){
        arr[i] = tmp->data;
        i++;
        tmp = tmp->next;
    }

    return arr;
}

int* sort(int arr[], int N){ //Buubble Sort con sentinella
    for(int i = 0; i < N - 1; i++){
        bool sentinella = 0;
            for(int j = 0; j < N - i - 1; j++){
                if(arr[j] > arr[j+1]){
                    int tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                    sentinella = 1;
                }
            }
        if(sentinella == 0) break;
    }

    return arr;
}

void printArr(int arr[], int N){
    for(int i = 0; i < N; i++) printf("%d\n", arr[i]);
}


int main(int argc, char* argv[]){
    printf("\n==========PUNTO A==========\n");
    decodeParameters(argc, argv);
    Nodo *top = NULL;
    readFile("input2.txt", &top);
    printf("\n==========PUNTO B==========\n");
    printf("Contenuto della pila.\n");
    printStack(top);
    printf("\n==========PUNTO C==========\n");
    double m = getMean(&top);
    printf("Media dei valori in P: %.2f", m);
    printf("\n==========PUNTO D==========\n");
    fillP("input2.txt", &top, m);
    printStack(top);
    int N = countElem(top);
    int* arrP = transferP(top, N);
    arrP = sort(arrP, N);
    printf("\n==========PUNTO E==========\n");
    printArr(arrP, N);
    
}

//  cd "C:\Users\giuli\Desktop\Desktop\Universita\1Anno\PrimoSemestre\Programmazione1\Esame Dicembre\Svolgimento prove d'esame\Esami con Date + txt"
//  gcc -Wall 29-03-2024.c -o prova2903
//  .\prova2903 input2.txt