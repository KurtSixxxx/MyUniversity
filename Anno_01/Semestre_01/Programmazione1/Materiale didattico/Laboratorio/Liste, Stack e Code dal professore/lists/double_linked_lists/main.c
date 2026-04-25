#include "double_linked_list.h"
#include "../../common/double_ref_node.h"

#include <stdio.h>

int main(){

    struct double_ref_nodo *head = NULL; 

    struct dato my_data; 

    int inputData[5] = {10, 12, 2, 34, 1};

    for(unsigned short i=0; i<5; i++){
	printf("\n Trying to add data: [%d]", inputData[i]);
	my_data.value = inputData[i]; 
	insertNodoDls(&my_data, &head);    
    }

    printListDls(head); 

    int deleteData[3] = {7, 10, 34};

    for(unsigned short i=0; i<3; i++){
	printf("\n Trying to delete data: [%d]", deleteData[i]);
	my_data.value = deleteData[i];
	deleteNodoDls(&my_data, &head);
    }

    printListDls(head); 





}
