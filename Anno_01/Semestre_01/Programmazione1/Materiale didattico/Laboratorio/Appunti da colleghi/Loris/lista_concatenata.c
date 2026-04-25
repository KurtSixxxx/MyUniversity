#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MSL 30

typedef struct {
    char* input;
    int x; 
    int y;
} params;

typedef struct {
    char nome[MSL];
    char cognome[MSL];
    int age;
} record;

typedef struct nodo {
    record r;
    struct nodo* next;
} nodo;

typedef nodo* lista;

params readinput(int argc, char** argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input> <x> <y>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    params p;
    p.input = argv[1];
    p.x = atoi(argv[2]);
    p.y = atoi(argv[3]);
    if (p.x > p.y) {
        fprintf(stderr, "Y has to be greater than X\n");
        exit(EXIT_FAILURE);
    }
    if (p.x < 10 || p.y < 10 || p.x > 60 || p.y > 60) {
        fprintf(stderr, "x and y must be in range 10-60\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

void inserrecordordinato(nodo** l, record r) {
    nodo* newNode = malloc(sizeof(nodo));
    if (n == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->r = r;
    newNode->next = NULL;
    if (*l == NULL) {
        *l = newNode;
    } else if (strcmp(newNode->r.cognome, (*l)->r.cognome) < 0) {
        newNode->next = *l;
        *l = newNode;
    } else {
        nodo* temp = *l;
        while (temp->next != NULL && strcmp(temp->next->r.cognome, newNode->r.cognome) < 0) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void buildlist(lista* l, const char* input) {
    FILE* fp = fopen(input, "r");
    if (!fp) {
        fprintf(stderr, "File cannot be opened\n");
        exit(EXIT_FAILURE);
    }
    record r;
    while (fscanf(fp, "%s %s %d", r.nome, r.cognome, &r.age) != EOF) {
        inserrecordordinato(l, r); // Aggiorna direttamente la lista passata per riferimento
    }
    fclose(fp);
}

void printrecord(record r) {
    printf("%s %s %d\n", r.nome, r.cognome, r.age);
}

void printlist(lista l) {
    while (l != NULL) {
        printrecord(l->r);
        l = l->next;
    }
}

void removebyage(lista* l, int age) {
    nodo* tmp = *l;
    nodo* prev = NULL;
    while (tmp != NULL) {
        if (tmp->r.age == age) {
            printf("Record trovato e rimosso\n");
            printrecord(tmp->r);
            if (prev == NULL) {
                *l = tmp->next;
            } else {
                prev->next = tmp->next;
            }
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    printf("Record with age %d not found.\n", age);
}

int main(int argc, char** argv) {
    params p = readinput(argc, argv);
    lista l = NULL; // Inizializza la lista a NULL
    buildlist(&l, p.input); // Passa il puntatore a lista per aggiornare la lista
    printf("\n **** Lista originale  *** \n");
    printlist(l);

    int rimuovoage =  40;
    removebyage(&l, rimuovoage);
    printf("\n ***  Lista dopo la rimozione del record con eta' %d\n", rimuovoage);
    printlist(l);
}