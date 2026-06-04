#include "data.h"
#include <stdio.h>

int confronta_dati(const struct dato *d1, const struct dato *d2){
    if((*d1).value > (*d2).value)
	return 1;
    else if(d1->value < d2->value)
	return -1;
    return 0;
}

void printDato(const struct dato *ptr){
    printf(" [%d] ", ptr->value); 
}

void freeData(const struct dato *ptr){
	return; // nulla da deallocare nel caso specifico (un int) 				
}

void copyData(const struct dato *src, struct dato *dst){
  memcpy(dst, src, sizeof(struct dato));  
}
