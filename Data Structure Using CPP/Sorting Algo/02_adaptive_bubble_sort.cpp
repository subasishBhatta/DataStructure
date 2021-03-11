//
// Created by CHINTOO on 11-03-2021.
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

void bubbleSort_adaptive(int *arr, int n)
{
    for (int i = 0; i < n-1; ++i) {
        int isSort {1};
        cout << "Pass number: " << i+1 << endl;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j+1])
            {
                exchange(arr[j], arr[j+1]);
                isSort = 0;
            }
        }
        if (isSort)
        {
            return;
        }
    }
}

//void bubbleSort_descend(int *arr, int n)
//{
//    for (int i = 0; i < n-1; ++i) {
//        for (int j = 0; j < n - i - 1; ++j) {
//            if (arr[j] < arr[j+1])
//            {
//                exchange(arr[j], arr[j+1]);
//            }
//        }
//    }
//}

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

    bubbleSort_adaptive(arr, size);

    cout << "\nThe values in the array after sorting in ascending order:" << endl;
    printArray(arr, size);


//    bubbleSort_descend(arr, size);
//
//    cout << "\nThe values in the array after sorting in descending order:" << endl;
//    printArray(arr, size);


    return 0;
}
