//
// Created by CHINTOO on 11-03-2021.
// This is an example of selection sort
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

void selection_sort(int *arr, int n)
{
    int min;
    for (int i = 0; i < n-1; ++i) {
        min = i;
        for (int k = i+1; k < n; ++k) {
            if (arr[k] < arr[min])
            {
                min = k;
            }
        }
        exchange(arr[min], arr[i]);
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

    selection_sort(arr, size);

    cout << "\nThe values in the array after sorting in ascending order:" << endl;
    printArray(arr, size);

    return 0;
}

