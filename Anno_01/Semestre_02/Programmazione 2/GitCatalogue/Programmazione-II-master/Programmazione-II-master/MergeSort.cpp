#include <iostream>

using namespace std;

template <class H> void MergeSort(H *V, int left, int right){
	
	if(left==right){
		return;
	}

	int middle=(left+right)/2;

	MergeSort(V, left, middle);
	MergeSort(V, middle+1, right);

	int i=left;
	int j=left;
	int k=middle+1;
	H B[20];

	while(j<=middle && k<=right){
		if(V[j]<=V[k]){
			B[i]=V[j];
			j++;
		}
		else{
			B[i]=V[k];
			k++;
		}
		i++;
	}
	while(k<=middle){
		B[i]=V[k];
		i++;
		k++;
	}
	while(j<=right){
		B[i]=V[j];
		i++;
		j++;
	}

	for (int h=left; h<=right; h++){
		V[h]=B[h];
	}
}



int main(){
	int A[]={74, 41, 1, 16, 4, 0, 3};
	int size=sizeof(A)/sizeof(A[0]);

	for(int i=0; i<size; i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;

	MergeSort(A, 0, size-1);

	for(int i=0; i<size; i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}