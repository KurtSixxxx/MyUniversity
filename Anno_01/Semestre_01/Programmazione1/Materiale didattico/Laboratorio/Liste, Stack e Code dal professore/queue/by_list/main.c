#include "queue.h"
#include "../../common/single_ref_node.h"

#include <stdio.h>

int main(){

    struct queue q; 
    q.head = q.tail = NULL; 

    int array[] = {1,2,3,4,5,6}; 

    struct dato d;

    for(int i=0; i<6; i++){
	d.value  = array[i];
	enqueue(&q, &d); 
	printQueue(&q);
    }

    printQueue(&q);

    for(int i=0; i<6; i++){
	if(dequeue(&q, &d) < 0)
	    fprintf(stderr, "\n Error removing element from the queue..");	    
	else
	    printf("\n\n ** Removed element %d ** \n", d.value);

	printQueue(&q); 
    }
}
