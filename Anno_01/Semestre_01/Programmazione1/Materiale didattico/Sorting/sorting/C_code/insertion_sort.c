#include "sorting.h"
#include "utils.h"
#include <stdio.h>

void insertion_sort(int *A, unsigned int len)
{
    int key, j;
    int scambi = 0;
    int count = 0;

    for (int i = 1; i < len; i++) {
			key = A[i];
			j = i - 1;
		while (key < A[j] && j >= 0) {
	    A[j + 1] = A[j];
	    scambi++;
	    count++;
	    j--;
		}
		A[j + 1] = key;
		if(DEBUG){
			printf("\n [ [");
			for(int k=0; k<len; k++)
				if(k==i)
					printf("%d] ", A[k]);	
				else 
					printf("%d ", A[k]);
			printf("]");
		} 

  }

	if(DEBUG)
  	printf("\n insertion_sort, #iter=%d, #writes=%d \n", count, scambi);
}
