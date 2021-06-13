//
// Created by CHINTOO on 13-06-2021.
// In this pgm we remove the duplicates from a sorted array
// Here the Time complexity = O(n) and space complexity = O(1)
//

#include "iostream"
using namespace std;

int remove_duplicates(int *arr, int n)
{
    int res = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[res-1])
        {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}

void display(int *arr, int n)
{
    cout << "Displaying the array: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[8] {12, 32, 32, 45, 45, 78, 78, 78};
    display(arr, 8);
    int index = remove_duplicates(arr, 8);
    display(arr, index);

    return 0;
}
