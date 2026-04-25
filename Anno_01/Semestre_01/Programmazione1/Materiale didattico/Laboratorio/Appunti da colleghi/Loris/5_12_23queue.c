#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[31]; // Array di caratteri per memorizzare la stringa
    struct Node* next; // Puntatore al prossimo nodo
};

struct InputParams {
    int argc; // Numero di argomenti della riga di comando
    char** argv; // Array di stringhe contenente gli argomenti della riga di comando
};

// Funzione per leggere l'input da riga di comando
struct InputParams readInput(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct InputParams params = {argc, argv};
    return params;
}

// Funzione per aggiungere una parola alla coda
void enqueueWord(struct Node** head, struct Node** tail, char* stringa) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Unable to allocate memory for new node\n");
        exit(EXIT_FAILURE);
    }

    strncpy(newNode->data, stringa, sizeof(newNode->data));
    newNode->data[sizeof(newNode->data) - 1] = '\0';
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*tail)->next = newNode;
    }

    *tail = newNode;
}

// Funzione per rimuovere una parola dalla coda
char* dequeueWord(struct Node** head, struct Node** tail) {
    if (*head == NULL) {
        return NULL;
    }

    char* stringa = malloc(sizeof((*head)->data));
    if (stringa == NULL) {
        fprintf(stderr, "Unable to allocate memory for string\n");
        exit(EXIT_FAILURE);
    }
    strncpy(stringa, (*head)->data, sizeof((*head)->data));

    struct Node* tmp = *head;
    *head = (*head)->next;
    if (*head == NULL) {
        *tail = NULL;
    }

    free(tmp);
    return stringa;
}

// Funzione per costruire la coda leggendo le parole da un file
void buildQueue(struct Node** head, struct Node** tail, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char stringa[31];
    while (fgets(stringa, sizeof(stringa), file) != NULL) {
        stringa[strcspn(stringa, "\n")] = '\0'; // Remove trailing newline
        enqueueWord(head, tail, stringa);
    }

    fclose(file);
}

// Funzione per costruire un array di stringhe dalla coda
char** buildStringArray(struct Node** head, struct Node** tail, int* size) {
    char** array = NULL;
    char* stringa;
    while ((stringa = dequeueWord(head, tail)) != NULL) {
        printf("%s\n", stringa);
        array = realloc(array, (*size + 1) * sizeof(char*));
        if (array == NULL) {
            fprintf(stderr, "Unable to allocate memory for array\n");
            exit(EXIT_FAILURE);
        }
        array[*size] = stringa;
        (*size)++;
    }
    return array;
}

// Funzione per ordinare l'array di stringhe usando bubble sort
void bubbleSort(char** array, int size) {
    int i, j;
    for (i = 0; i < size-1; i++) {      
        for (j = 0; j < size-i-1; j++) {
            if (strcmp(array[j], array[j+1]) > 0) {
                char* temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

// Funzione per stampare l'array di stringhe
void printArray(char** array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", array[i]);
    }
}

// Funzione principale
int main(int argc, char** argv) {
    struct InputParams params = readInput(argc, argv);

    struct Node* head = NULL;
    struct Node* tail = NULL;
    buildQueue(&head, &tail, params.argv[1]);

    int size = 0;
    char** array = buildStringArray(&head, &tail, &size);

    bubbleSort(array, size);

    printArray(array, size);

    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}