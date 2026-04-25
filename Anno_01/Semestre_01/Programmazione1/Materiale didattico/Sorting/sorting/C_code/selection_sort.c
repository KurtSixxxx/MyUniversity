#include "sorting.h"
#include <stdio.h>
#include "utils.h"

void selection_sort (int array[], unsigned length)
  {
		printf("\n"); 
    int min;

    for (int index = 0; index < length-1; index++){
		//ricerca del minimo
    	min = index;
      for(int i = index+1; i < length; i++)
      	if(array[i] < array[min])  
	      	min = i;

			//OUTPUT 
			if(DEBUG){
				for(int j=0; j<length; j++)
	  			printf("%s%d%s", ((j==index || j==min )? "[" : ""),  array[j], (j==index || j==min ? "] " : " "));
				printf("\n"); 			
			}

			//scambia minimo ed elemento di indice index
    	swap(array, min, index);
   }
 	}
