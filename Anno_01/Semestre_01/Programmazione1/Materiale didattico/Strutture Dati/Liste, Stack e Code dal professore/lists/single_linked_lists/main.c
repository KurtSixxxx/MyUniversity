#include "single_linked_list.h"
#include "../../common/single_ref_node.h"

#include <stdio.h>

int main(){

    struct nodo * head = NULL; 

    struct dato my_data; 

    int inputData[5] = {10, 12, 2, 34, 1};

    for(unsigned short i=0; i<5; i++){
	printf("\n Trying to add data: [%d]", inputData[i]);
	my_data.value = inputData[i]; 
	insertNodo(&my_data, &head);    
    }

    printList(head); 

    int deleteData[3] = {7, 10, 34};

    for(unsigned short i=0; i<3; i++){
	printf("\n Trying to delete data: [%d]", deleteData[i]);
	my_data.value = deleteData[i];
	deleteNodo(&my_data, &head);
    }

    printList(head); 





}
