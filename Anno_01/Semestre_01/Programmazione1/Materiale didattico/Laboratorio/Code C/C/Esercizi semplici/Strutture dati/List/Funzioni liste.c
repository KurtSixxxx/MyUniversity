//**1. Funzione di inserimento**

//Questa funzione permette di inserire un nodo in testa
void list_insert(struct node** head, int new_data) {

  struct node* nuovo = (struct node*)malloc(sizeof(struct node)); //'nuovo' sarà il nuovo nodo, e malloc serve per allocare lo spazio per il nuovo nodo

  if(nuovo == NULL){ //Questa è la classica verifica se l'allocazione è andata a buon fine.
    printf("Errore nell'allocazione della memoria!");
    exit(0); //Questa riga termina il programma in caso di allocazione fallita
  }
  
  nuovo->data = new_data; //Imposta il dato del nuovo nodo
  nuovo->next = (*head); //Questa riga collega il nuovo nodo alla lista esistente, così il nuovo nodo punta al nodo che era precedentemente la testa della lista. In poche parole prende il suo posto.

  (*head) = nuovo; //La testa punta al nuovo nodo, così diventa il primo della lista
}
//In 'struct node** head' viene usato un doppio puntatore per poter modificare il puntatore alla testa della lista e quindi aggiungere nuovi nodi 

//**2. Funzione di stampa**

void printList(struct node *p){ //Void indica che la funzione non restituisce valori. 'p' è un puntatore al nodo1.
    while (p != NULL) { //Il ciclo continua finché p non è NULL. Quando lo è significa che abbiamo raggiunto la fine della lista.

        if(p->next != NULL) //Se p->next non è NULL significa che il nodo corrente non è l'ultimo della lista
        printf("|%d| -> ", p->data); //Quindi stampiamo il |valore| per mostrare che c'è un collegamento con il nodo successivo
        else
        printf("|%d|", p->data); //Se invece p->next è NULL signiffica che siamo all'utlimo nodo della lista. Quindi stampiamo il valore senza freccia dato che non ci sono nodi successivi.

        p = p->next; //Aggiorna p per puntare al nodo successivo della lista,
    }
    //Il ciclo while continua finché ci sono nodi da stampare. Una volta che p diventa NULL (quando non ci sono più nodi), il ciclo termina e la funzione finisce.
}

//**3. Funzione di ricerca**

int list_search(struct node* corrente, int ricercato) { //Ci sono due parametri: Un puntatore al nodo corrente della lista e un valore intero da cercare
//La funzione scorre la lista partendo dal nodo corrente. Se trova un nodo il cui valore corrente->data è uguale al valore che stiamo cercando la funzione resitutisce 1 (vero), altrimenti restituisce 0 (falso)

  while (corrente != NULL) {
    if (corrente->data == ricercato) 
      return 1;                          

    corrente = corrente->next; // Questo comando fa passare al nodo successivo
  }

  // fine while
  return 0;   
}

// Utilizzo della funzione nel codice
// Cerco nodo con dato 34
  nodoCercato = 86;
  if(list_search(head, nodoCercato))
    printf("\nNodo %d trovato!", nodoCercato);
  else                                 
    printf("\nNodo %d NON trovato!", nodoCercato);

  // Cerco nodo con dato 22
  nodoCercato = 90;
  if(list_search(head, nodoCercato))
    printf("\nNodo %d trovato!", nodoCercato);
  else
    printf("\nNodo %d NON trovato!\n", nodoCercato);