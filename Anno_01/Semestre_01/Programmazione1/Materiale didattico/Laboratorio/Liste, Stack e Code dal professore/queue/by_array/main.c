#include "circularQueue.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    struct circularQueue q; 

    initQueue(&q, 20);

    int toInsert[9]= {1,2,3,45,6,5,4,34,21};

    for(unsigned short i=0; i<9; i++){
	printf("\n Trying to insert element %d..", toInsert[i]);
	if(enqueue(&q, toInsert[i])<0)
	    return -1;
 
	printQueue(&q);
    }


    int dato; 
      
    for(unsigned short i=0; i<5; i++){
	if(dequeue(&q, &dato)!=DEQUEUE_OK)
	    return -1; 
	else
	    printf("\n Removed from the head: %d", dato);

	printQueue(&q);
    }

    printf("\n Removing all the remaining elements..");
    while(dequeue(&q, &dato)!=DEQUEUE_OK || !isEmpty(&q));

    printQueue(&q);   

}
