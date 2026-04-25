/*realloc puntatore = realloc(puntatore_esistente, dimensione_nuova); puntatore_esistente è un puntatore al blocco di memoria che 
si desidera modificare, e dimensione_nuova è la nuova dimensione del blocco di memoria in byte Ad esempio, se hai allocato un array 
di 10 interi con malloc e ora vuoi aumentare la sua dimensione a 15 interi, puoi usare: p = realloc(p, 15 * sizeof(int));*/
#include <stdio.h>
#include <stdlib.h>//serve per l'allocazione dinamica della memoria

void printArray(int a[], int dim);//non restituisce alcun valore
	/*allocazione statica,se volessi aggiungere un altro elemento al mio array non potrei farlo o meglio si potrebbe fare ma dovrei dichiarare un altro array di dimensione superiore,
	copiare gli elementi dell'array e avrei uno spreco di memoria,la vita dell'array statico ha vita all'interno del blocco*/
int main (){
	int a[]={1,2,3,4};
	int dim_a=4;
	printf("Array statico di %d elementi: ",dim_a);
	printArray(a,dim_a);

	int numElem = 10;
	int *p; 
	// Verifica dell'allocazione
	if ((p = (int *) calloc(numElem,sizeof(int))) == NULL) {
		fprintf(stderr, "Errore durante l'allocazione di memoria.\n");
	return 1; // Termina il programma con codice di errore
	}

	for(int i=0; i<numElem; ++i){//questo è un ciclo che inizializza ogni elemento dell'array dinamico con il valore dell'indice
		p[i]=i;
	}

	printf("Array dinamico con calloc: \n");
	printArray (p,numElem);//stampa l'array dinamico p,viene richiesto l'array e la dimensione
	
	numElem=15;
	p= (int*)realloc(p, numElem* sizeof (int) );
	for(int i =0; i <numElem ; ++i){
		p[i]=i;
	}
	printf("Dimensione modificata con realloc: ");
	printArray(p,numElem);
	free(p); // Libera la memoria allocata

	return 0;
} 

void printArray(int a[],int dim){
	for(int i=0 ; i<dim ; ++i){
		printf("%d\t",a[i]);
	}
}
