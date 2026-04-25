/*malloc(allocazione dinamica) int *p=malloc(numElem*dim) Numero di elementi*dimensione di ogni elemento in byte(cioè dimensione totale in byte)
Ad esempio, per allocare memoria per un array di 10 interi utilizzando malloc, puoi utilizzare il seguente codice:
int *p = (int *) malloc(10 * sizeof(int));*/
/*variabili statiche=il contenuto può essere modificato,ciò che non può essere modificato è il tipo e la dimensione che occupa in memorianella memoria dinamica posso decidere
quanta memoria voglio allocare durante l'esecuzione,quando si riferisce a memoria statica si riferisce allo stack,mentre quando si parla di memoria dinamica si riferisce all'heap,
la memoria statica ha due problemi=1)consumo di memoria nel caso di esigenze inferiori(es. ho un array di dimensione 10 ma ho solo due elementi quindi me ne basterbbe uno da due),
2)posso avere anche il contrario,la dinamica mi permette di accorciare o allungare l'array*/
#include <stdio.h>
#include <stdlib.h>//serve per l'allocazione dinamica della memoria

void printArray(int a[], int dim);//non restituisce alcun valore
	/*allocazione statica,se volessi aggiungere un altro elemento al mio array non potrei farlo o meglio si potrebbe fare ma dovrei dichiarare un altro array di dimensione superiore,copiare
	gli elementi dell'array e avrei uno spreco di memoria,la vita dell'array statico ha vita all'interno del blocco*/
int main (){
	int a[]={1,2,3,4};
	int dim_a=4;
	printf("Array statico di %d elementi: ",dim_a);
	printArray(a,dim_a);

	int numElem = 10;
	int *p; 
//malloc vuole un solo parametro,ovvero,il numero di byte
	// Verifica dell'allocazione
	if ((p = (int *) malloc(numElem * sizeof(int))) == NULL) {
	/* Il risultato di malloc viene assegnato a un puntatore a interi p dopo essere stato convertito in un puntatore a interi utilizzando un cast (int *).Il cast non è strettamente 
	necessario in C, ma alcuni compilatori potrebbero richiederlo  per disattivare l'avviso di conversione implicita da void* a int*.*/
		fprintf(stderr, "Errore durante l'allocazione di memoria.\n");
	return 1; // Termina il programma con codice di errore
	}

	for(int i=0; i<numElem; ++i){//questo è un ciclo che inizializza ogni elemento dell'array dinamico con il valore dell'indice
		p[i]=i;
	}

	printf("Array dinamico con malloc: \n");
	printArray (p,numElem);//stampa l'array dinamico p,viene richiesto l'array e la dimensione

	free(p); // Libera la memoria allocata

	return 0;
} 

void printArray(int a[],int dim){
	for(int i=0 ; i<dim ; ++i){
		printf("%d\t",a[i]);
	}
}
/*Il malloc richiede un argomento che specifica la dimensione della memoria da allocare in byte. 
Pertanto, numElem * sizeof(int) viene utilizzato per calcolare la dimensione richiesta in byte, dove numElem è il numero di elementi dell'array e sizeof(int) 
restituisce la dimensione di un intero in byte. Il malloc restituisce un puntatore a void, che rappresenta l'indirizzo di memoria della memoria allocata.
La verifica if ((p = (int *) malloc(numElem * sizeof(int))) == NULL) verifica se l'allocazione di memoria ha avuto esito positivo.  Se malloc non è in grado di allocare 
la memoria richiesta, restituisce un puntatore NULL.*/ 
/*malloc va a riservare un determinato numero di celle della memoria dinamica e se ne frega di ciò che c'è dentro,nel caso della calloc va a riserva un'area di memoria e prima di 
restituire il nostro puntatore alla prima cella(il nostro array)va ad azzerare ogni cella*/
