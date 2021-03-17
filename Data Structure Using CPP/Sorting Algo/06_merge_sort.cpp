//
// Created by CHINTOO on 13-03-2021.
// Here this is the code for merge sort algorithm
//

#include "iostream"
using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k = low;
    int B[high+1];
    i = low;
    j = mid+1;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            B[k] = arr[i];
            i++;
            k++;
        } else
        {
            B[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i <= mid)
    {
        B[k] = arr[i];
        i++;
        k++;
    }
    while(j <= high)
    {
        B[k] = arr[j];
        j++;
        k++;
    }
    for (int l = low; l <= high; ++l) {
        arr[l] = B[l];
    }
}

void merge_sort(int * arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
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

    merge_sort(arr, 0, size-1);

    cout << "\nThe values in the array after sorting in ascending order:" << endl;
    printArray(arr, size);

    return 0;
}

