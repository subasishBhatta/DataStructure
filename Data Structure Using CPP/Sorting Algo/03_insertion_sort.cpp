//
// Created by CHINTOO on 11-03-2021.
// This is an example of insertion sort
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

void insertion_sort(int *arr, int n)
{
    int key{0}, j{0};
    for (int i = 1; i < n; ++i) {
        key = arr[i];
        j = i-1;
        while (j >=0 and arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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

    insertion_sort(arr, size);

    cout << "\nThe values in the array after sorting in ascending order:" << endl;
    printArray(arr, size);

    return 0;
}
