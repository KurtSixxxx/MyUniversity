/*calloc(allocazione dinamica) int *p=calloc(numElem,dim) Numero di elementi,dimensione di ogni elemento(singolarmente)
Ad esempio, per allocare memoria per un array di 10 interi utilizzando calloc, puoi utilizzare il seguente codice: int *p = (int *) calloc(10, sizeof(int));*/
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

	free(p); // Libera la memoria allocata

	return 0;
} 

void printArray(int a[],int dim){
	for(int i=0 ; i<dim ; ++i){
		printf("%d\t",a[i]);
	}
}
/*malloc va a riservare un determinato numero di celle della memoria dinamica e se ne frega di ciò che c'è dentro,nel caso della calloc va a riserva un'area di memoria e prima di 
restituire il nostro puntatore alla prima cella(il nostro array)va ad azzerare ogni cella
calloc inizializza ogni byte della memoria allocata a zero prima di restituire un puntatore alla memoria,richiede due argomenti: il numero di elementi da allocare e 
la dimensione di ogni elemento. Nel tuo codice, numElem è il numero di elementi e sizeof(int) è la dimensione di ogni elemento.*/

