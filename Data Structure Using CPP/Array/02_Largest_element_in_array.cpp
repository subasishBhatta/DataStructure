//
// Created by CHINTOO on 13-06-2021.
// This is the problem to find the largest element in the array
// This method finds the largest element in the array with time complexity O(n) and space complexity O(1)
//


#include "iostream"
using namespace std;

int largest(const int *arr, int n)
{
    int res = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[res])
            res = i;
    }
    return res+1;
}

int main()
{
    int arr[8] {12, 32, 223, 45, 65, 178, 98, 10};

    int ind = largest(arr, 8);
    cout << "The largest element in the array is at position " << ind
    << " and the value is " << arr[ind-1] << endl;

    return 0;
}
