

// Ridirezione dello stdout

#include <stdio.h>
#include <iostream>
int main(){

	
	freopen("myfile.txt", "w", stdout); // ridireziono stdout su un file aperto in scrittura
		
	printf("Questa frase e' ridirezionata su un file.\n");
	std::cout << "... anche questa ..." << std::endl;
	std::cout << "... e pure quest'altra!" << std::endl;
	
	fclose(stdout);
	
	//TODO: come ripristino lo stdout su console ??

	// QUESTA FUNZIONA SOLO SU WINDOWS!!!!
	//freopen("con", "w", stdout);
	
	
	std::cout << ".... e questa ??? ...." << std::endl;	
	printf("E questa qui?? \n");

	
	
	return 0;
}