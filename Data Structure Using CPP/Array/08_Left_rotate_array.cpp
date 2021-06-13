//
// Created by CHINTOO on 13-06-2021.
// Here we left rotate the array by d places
// Here there are 3 methods and each method has different time and space complexity
//

#include "bits/stdc++.h"
using namespace std;

void reverse(int *arr, int l, int r){
    while(l < r){
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

// First method (Shift by one place) (Also called a naive approach)
// Then Apply it for d times
// Time Complexity = O(n*d), Space Complexity = O(1)
void left_rotate_1(int *arr, int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; ++i) {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}


// Second method - (Copy all the content that we have to rotate in another array)
// Later shift the array and paste all the content at the end of the array
// Here Time complexity = O(d+n-d+d) = O(n+d) = O(n)
// Here Space complexity = O(d)
void left_rotate_2(int *arr, int n, int d) {
    int temp[n];
    for (int i = 0; i < d; ++i) {
        temp[i] = arr[i];
    }
    for (int i = d; i < n; ++i) {
        arr[i-d] = arr[i];
    }
    for (int i = 0; i < d; ++i) {
        arr[n-d+i] = temp[i];
    }
}


// Third method - (Here we first reverse the part which we want to shift, then reverse the next part)
// And finally we reverse the entire array
// Here the Time complexity = O(d + n-d + n) = O(2n) = O(n)
// Space Complexity = O(1)
void left_rotate_3(int * arr, int n, int d)
{
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
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
    int arr[8] {12, 32, 14, 45, 65, 51, 35, 10};
    display(arr, 8);
    int d{};
    cout << "Enter the no of places you want to rotate the array:" << endl;
    cin >> d;
//    for (int i = 0; i < d; i++)
//    {
//        left_rotate_1(arr, 8);
//    }
//    display(arr, 8);

//    left_rotate_2(arr, 8, d);
//    display(arr, 8);

    left_rotate_3(arr, 8, d);
    display(arr, 8);


    return 0;
}

