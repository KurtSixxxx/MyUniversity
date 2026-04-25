#include <iostream>

using namespace std;

template <class H> void quickSort(H arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      H pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i < j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}


int main(){
	int A[]={7,9,1,2,8,4,10,3,5,12,15,11,23,6};
	int size=sizeof(A)/sizeof(A[0]);

	for(int i=0; i<size; i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;

	quickSort(A, 0, size-1);

	for(int i=0; i<size; i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}