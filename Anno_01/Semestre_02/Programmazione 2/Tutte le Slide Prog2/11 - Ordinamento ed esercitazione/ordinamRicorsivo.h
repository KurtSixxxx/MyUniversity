/*
Implementazioni di mergesort e quicksort
*/
#include<iostream>
void scambia(int& a, int& b){
	int aux=a;
	a=b;
   	b=aux;
}



//Ordina a[sinistra:destra]
void quicksort(int a[], int sx, int dx){
    // il caso base (sx>=dx) si controlla nel while
   	//if(sx>=dx) return;

	int i=sx; //Indice che parte da sinistra
	int j=dx; //Indice che parte da destra

    int pivot = a[(sx+dx)/2];
    // partizionamento
	while (i<=j) {
    //trovo i primi (i,j) che violano l'ordine rispetto pivot
		while (a[i]<pivot) i++;
		while (a[j]>pivot) j--;
		if (i<=j){
		// Scambia solo se indice sinistro minore del destro
			scambia(a[i],a[j]);
			i++; j--;
			}
		}
    /*qui ho esaminato tutti quelli a dx e sx del pivot
      e mi trovo nella condizione i>j (sono uscito dal while)
      [sx..............dx]
             ^     ^
           <-j      i->
      j potrebbe aver raggiunto sx  */
    if(j > sx) // se ci sono ancora elementi a sinistra da ordinare
        quicksort(a,sx,j);
    // i potrebbe aver raggiunto dx
	if(i < dx) //se ci sono ancora elementi a destra da ordinare
        quicksort(a,i,dx);

}



//Ordina a[0:n-1]
void quicksort(int a[], int n){
	quicksort(a, 0, n-1);
}



/*
merge dei due sottoarray:
a[left....center]
a[cent+1....right]
sapendo che entrambi sono ordinati
*/
// VERSIONE MODIFICATA PER GESTIRE DIM VARIABILE
int DIM = -1;
void merge(int a[], int left, int center, int right)
{
	int i=left, j=center+1, k=left;
	int b[DIM]; //array di appoggio (puo dare problemi se DIM e' troppo grande)
	
	/* Soluzione alternativa
	 in questo modo ci mette di piu e genera una eccezione bad_alloc dopo una certa dimensione
	stabilita dal compilatore - le best practices suggeriscono gli array dinamici in questi casi */
//	int *b;
//	b = new int[DIM]; //array di appoggio 


	/*scorro i da sx a dx
      scorro j da center+1 a dx
      aggiungo a b[] il minore tra a[i] e a[j]*/
	while((i<=center) && (j<=right))
	{
		if (a[i] <= a[j])		{
			b[k]=a[i];
			i++;
		}
		else		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	/* qui uno dei due sottoarray e'
	   stato svuotato. Inserisco gli
	   elementi del restante sottoarray
	*/
    while(i<=center){
		b[k]=a[i];
		i++;
		k++;
	}
    while(j<=right)	{
		b[k]=a[j];
		j++;
		k++;
	}
	//riverso il contenuto di b[] in a[]
    for(k=left;k<=right;k++)
    	a[k]=b[k];
}


void mergesort(int a[], int left, int right)
{
    if(DIM<(right-left+1)){
	  //  std::cout << "set DIM = " << (right +1) << std::endl; //check
	    DIM = right-left+1;
	    }
	    
	if (left< right)
	{
		int center=(left+right)/2;
		mergesort(a,left,center);
		mergesort(a,center+1,right);
		merge(a,left,center,right);
	}
}

