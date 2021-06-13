//
// Created by CHINTOO on 13-06-2021.
// Here we are checking if an array is sorted in ascending order or not
// Time complexity = O(n) and space complexity = O(1)
//

#include "iostream"
using namespace std;

bool is_sorted(const int *arr, int n)
{
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i-1]){
            return false;
        }
    }
    return true;
}

int main()
{
    int arr1[8] {12, 32, 223, 45, 65, 178, 98, 10};
    int arr2[8] {12, 32, 223, 345, 465, 578, 698, 910};

    bool ind = is_sorted(arr2, 8);
    cout << (ind ? "Sorted": "Not sorted") << endl;

    return 0;
}

