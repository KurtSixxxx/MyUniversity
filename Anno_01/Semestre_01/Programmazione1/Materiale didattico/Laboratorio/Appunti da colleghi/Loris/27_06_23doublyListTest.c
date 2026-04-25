#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char stringa[31];
    float value;
    struct Node* next;
    struct Node* prev;
};

struct inputParams{
    int argc;
    char** argv;
};

struct inputParams readInput(int argc, char** argv);

void insertRecord(struct Node** head, char* stringa1, float value1);

void buildList(struct Node** head, char* filename);

void printList(struct Node* head);

int elab(struct Node* head, float f);

int main(int argc, char** argv){

    struct inputParams params = readInput(argc, argv);

    struct Node* head = NULL;

    buildList(&head, params.argv[1]);

    printList(head);

    printf("Numero di record tali che V>=F :%d", elab(head, atof(params.argv[2])));

    return 0;
}

struct inputParams readInput(int argc, char** argv){

    if(argc != 3){
        fprintf(stderr, "Numero di parametri errato! %s", argv[1]);
        exit (-1);
    }

    if(atof(argv[2]) > 20.0 || atof(argv[2]) < 1.0){
        fprintf(stderr, "valori dei parametri errati!");
        exit (-1);
    }

    struct inputParams params = {argc, argv};
    return params;
}

void insertRecord(struct Node** head, char* stringa1, float value1){

    struct Node* tmp = (struct Node *)malloc(sizeof(struct Node));
    if(tmp == NULL){
        puts("Impossibile allocare memoria");
        exit(-1);
    }
    strncpy(tmp->stringa, stringa1, sizeof(tmp->stringa));
    tmp->stringa[sizeof(tmp->stringa) -1] = '\0';
    tmp->value = value1;
    tmp->next = NULL;
    tmp->prev = NULL;

    if(*head == NULL || strcmp((*head)->stringa, stringa1) > 0){

        tmp->next = *head;
        if(*head != NULL){
            (*head)->prev = tmp;
        }
        *head = tmp;
    }else{
        
        struct Node* current = *head;
        while(current->next != NULL && strcmp(current->next->stringa, stringa1) < 0){
            current = current->next;
        }

        tmp->next = current->next;
        if(current->next != NULL){
            current->next->prev = tmp;
        }
        current->next = tmp;
        tmp->prev = current;
    }

}

void buildList(struct Node** head, char* filename){

    FILE* fptr = fopen(filename, "r");
    if(fptr == NULL){
        puts("Impossibile accedere al  file");
        exit(-2);
    }

    char stringa[31];
    float value;

    while(fscanf(fptr, "%f", &value) != EOF && fgets(stringa, sizeof(stringa), fptr) != NULL){
        stringa[strcspn(stringa, "\n")] = '\0';
        insertRecord(head, stringa, value);
    }
    fclose(fptr);
}

void printList(struct Node* head){
    
    struct Node* tmp  = head;
    while(tmp != NULL){
        printf("%s %f\n", tmp->stringa, tmp->value);
        tmp = tmp->next;
    }
    puts("");
}

int elab(struct Node* head, float f){

    int count = 0;
    struct Node* tmp = head;

    while(tmp != NULL){
        if(tmp->value >= f){
            count++;
        }
        struct Node* tmp1 = tmp;
        tmp = tmp->next;
        free(tmp1);
    }
    return count;
}
