#include <stdio.h> 
#include "sorting.h"
#include "utils.h"


void bubble_sort(int *data, unsigned int n){
	short swapped=1;
	unsigned int step=0; 
	while(swapped){
		if(DEBUG)
			printf("\n step=%d", step+1);
		swapped=0;
		for(unsigned i=0; i<n-step-1; i++){
			if(DEBUG){
				printf("\n [");
				for(int k=0; k<n; k++)
					if(k==i)
						printf("[%d ", data[k]);
					else if(k==i+1)
						printf("%d] ", data[k]);
					else
						printf("%d ", data[k]); 

				printf("]");
			}
			if(data[i]>data[i+1]){
				swap(data, i, i+1); 
				swapped=1; 
			}
		}
		step++; // a visit
	}
}

