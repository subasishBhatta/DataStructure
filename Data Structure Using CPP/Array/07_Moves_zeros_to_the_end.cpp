//
// Created by CHINTOO on 13-06-2021.
// In this program we are given an array containing a lot of zeros
// Our task is to move all the zeros to the end of the array
// Time complexity = O(), Space complexity = O()
//


#include "bits/stdc++.h"
using namespace std;

void zeros_end(int *arr, int n)
{
    int count {0};
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0)
        {
            swap(arr[count], arr[i]);
            count++;
        }
    }
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
    int arr[8] {12, 32, 0, 45, 65, 0, 0, 10};
    display(arr, 8);
    zeros_end(arr, 8);
    display(arr, 8);

    return 0;
}

