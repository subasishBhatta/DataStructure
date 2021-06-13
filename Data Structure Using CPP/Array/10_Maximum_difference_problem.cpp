//
// Created by CHINTOO on 13-06-2021.
// Here we need to find the maximum difference between arr[j]-arr[i] such that j > i always
//// Naive approach - T.C - O(n*n), S.C - O(1)
//// Efficient approach - T.C - O(n), S.C - O(1)


#include "bits/stdc++.h"
using namespace std;

void display(int *arr, int n)
{
    cout << "Displaying the array: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


// Naive approach - T.C - O(n*n), S.C - O(1)
void naive_difference(const int *arr, int n)
{
    int diff = arr[1] - arr[0];
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if ((arr[j]-arr[i]) > diff)
            {
                diff = arr[j]-arr[i];
            }
        }
    }
    cout << "The maximum difference is " << diff << endl;
}

// Efficient approach - T.C - O(n), S.C - O(1)
void max_diff(int * arr, int n)
{
    int diff = arr[1] - arr[0];
    int min_val = arr[0];
    for (int i = 1; i < n; ++i) {
        diff = max(diff, (arr[i]-min_val));
        min_val = min(min_val, arr[i]);
    }
    cout << "The maximum difference is " << diff << endl;
//    cout << "The minimum value is " << min_val << endl;
}

int main()
{
    int arr[8] {8, 3, 1, 5, 10, 9, 11, 7};
    display(arr, 8);
    naive_difference(arr, 8);
    max_diff(arr, 8);

    return 0;
}
