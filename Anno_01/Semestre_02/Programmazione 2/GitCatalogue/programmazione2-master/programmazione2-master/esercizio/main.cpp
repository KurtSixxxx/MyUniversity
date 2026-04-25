#include "Player.hpp"
#include "List.hpp"

#include <fstream>



void printInOrder(int* listOfInt, int len){
	int max = 0;
	int listOfInt1[len] = {0};
	for(int i=0; i<len; i++){
		for(int j=i; j<len; j++){
			if(listOfInt[i] >= listOfInt[j]){
				int temp = listOfInt[i];
				listOfInt[i] = listOfInt[j];
				listOfInt[j] = temp;
			}
		}
	}
	for(int i=0; i<len; i++) cout << listOfInt[i] << " ";
	cout << endl;
	return;
}



int main(){
	ifstream myFile("assets/punteggi.txt");
	List<Player> listOfPlayer;
	while(!myFile.eof()){
			Player p;
			myFile >> p;
			listOfPlayer.add(p);
	}
	//cout << listOfPlayer << endl;
	int listOfInt[] = {1,23,34,0,10,8};
	printInOrder(listOfInt, 6);
	return 0;
}

