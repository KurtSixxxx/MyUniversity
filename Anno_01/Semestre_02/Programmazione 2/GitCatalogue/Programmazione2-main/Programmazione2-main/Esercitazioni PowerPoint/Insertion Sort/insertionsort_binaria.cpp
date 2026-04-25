#include <iostream>
using namespace std;

int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
    {
        return (item > a[low]) ? (low + 1) : low;
    }

    int mid = (low + high) / 2;

    if (item == a[mid])
    {
        return mid + 1;
    }

    if (item > a[mid])
    {
        return binarySearch(a, item, mid + 1, high);
    }

    return binarySearch(a, item, low, mid - 1);
}

void insertionSort(int a[], int n)
{
    int i, loc, j, k, selected;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];

        loc = binarySearch(a, selected, 0, j);

        while (j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}

int main()
{
    int vec[10] = {10, 7, 5, 8, 2, 6, 4, 3, 1, 9};

    cout << "Array non ordinato = [ ";
    for (int c = 0; c < 10; c++)
    {
        cout << vec[c] << " ";
    }
    cout << "]" << endl
         << endl;

    insertionSort(vec, 10);

    cout << "Array ordinato = [ ";
    for (int c = 0; c < 10; c++)
    {
        cout << vec[c] << " ";
    }
    cout << "]";
}