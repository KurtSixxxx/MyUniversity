#include "sorting.h" // prototipi delle tre funzioni di ordinamento
#include "utils.h" // print_array, gem_array, swap 

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#define L 20

// Per un output meno prolisso, vedi simbolo DEBUG in sorting.h (porre a 0) 

/* La seguente funzione riceve un puntatore a funzione 
* che prende in input un array di int (i dati da ordinare) ed 
* un unsigned che rappresenta la lunghezza dell'array. 
* Il secondo parametro e' il nome della funzione di ordinamento
* per esigenze di output. 
*/ 
void do_sort(void (*sorting_func)(int *data, unsigned len), const char *sort_name){
	
	int *array = gen_array(L, 5, 100);

	printf("\n"); 
	printf("\n ** RANDOM ARRAY for %s ** ", sort_name); 
	print_array(array, L); 

	printf("\n ** running %s.. ** ", sort_name); 
	sorting_func(array, L); 
	
	printf("\n ** RESULT (%s): ** ", sort_name); 
	print_array(array, L); 
}


int main(){

	srand(time(NULL)); 

	// Test dei tre algoritmi di ordinamento mediante la funzione do_sort(). 
	do_sort(bubble_sort, "BUBBLE SORT"); 

	do_sort(selection_sort, "SELECTION SORT"); 

	do_sort(insertion_sort, "INSERTION SORT"); 

}
