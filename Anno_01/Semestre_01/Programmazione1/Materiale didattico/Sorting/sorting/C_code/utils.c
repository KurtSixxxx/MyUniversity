#include <stdio.h>
#include <stdlib.h>

void swap(int *data, unsigned i, unsigned j){
	int tmp=data[i];
	data[i]=data[j];
	data[j] = tmp; 
}


void print_array(int *data, int len)
{
	printf("\n ["); 
  for (int k = 0; k < len; k++)
		printf("%d ", data[k]); 
  printf("]");
}

int* gen_array(unsigned length, int a, int b){
	int* ret = malloc(sizeof(int)*(length)); 

	for(unsigned i=0; i<length; i++)
		ret[i] = rand()%(b-a+1) + a; 

	return ret;
}
