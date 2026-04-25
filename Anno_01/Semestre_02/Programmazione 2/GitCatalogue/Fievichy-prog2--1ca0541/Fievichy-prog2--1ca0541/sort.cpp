//Bubble sort
void bubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1;j++) {
            if(arr[j] > arr[j+1]){
                int tmp=arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= tmp;
            }
        }
    }
}

//Selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
            minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

//Insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            } else {
                break;
            }
        }
    }
}

//Merge sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int n) {
    if (l < n) {
        int m = l + (n - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, n);
        merge(arr, l, m, n);
    }
}

//Quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    int tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
