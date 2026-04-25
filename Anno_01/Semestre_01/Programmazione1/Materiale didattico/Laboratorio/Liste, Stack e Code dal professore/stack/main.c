#include <stdio.h>
#include "stack.h"
#include "../common/single_ref_node.h"
#include "../common/data.h"

int main(){
    
    struct nodo *top = NULL;

    struct dato d;

    int dataToPush[6] = {4,3,6,2,6,9};

    for(unsigned short i=0; i<6; i++){
	d.value = dataToPush[i];
	printf("\n ** Pushing element %d **", d.value);
	push(&top, &d);
	printStack(top); 
    }

    printStack(top); 

    for(int i=0; i<6; i++){
	if(pop(&top, &d)>0){
	    printf("\n ** Removed element %d **", d.value);
	    printStack(top); 
	}
	else
	    printf("\n Error while removing the top of the stack");
    }

//    printStack(top); 
       

}
