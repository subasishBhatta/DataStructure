//
// Created by CHINTOO on 12-03-2021.
// This is an example of Quick Sort Algorithm
//

#include "iostream"
using namespace std;

void exchange(int &p, int &q)
{
    int temp = p;
    p = q;
    q = temp;
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int *arr, int low, int high)
{
     int pivot = arr[low];
     int i = low + 1;
     int j = high;

    do {
        while(arr[i] < pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if (i < j)
        {
            exchange(arr[i], arr[j]);
        }
    } while (i < j);

    exchange(arr[low], arr[j]);
    return j;
}

void quick_sort(int arr[], int low, int high)
{
    int pi;
    if (low < high)
    {
        pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array:" ;
    cin >> size;

    int arr[size];
    cout << "Enter the " << size << " elements into the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "The values in the array before sorting:" << endl;
    printArray(arr, size);

    quick_sort(arr, 0, size-1);

    cout << "\nThe values in the array after sorting in ascending order:" << endl;
    printArray(arr, size);

    return 0;
}
