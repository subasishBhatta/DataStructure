//
// Created by CHINTOO on 13-06-2021.
// Here we are reversing an array
// Here time complexity is O(n/2)=O(n) and space complexity is O(1)
//

#include "iostream"
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void reverse_array(int *arr, int n)
{
    int l = 0;
    int r = n-1;
    while (l < r)
    {
        swap(arr[l], arr[r]);
        l++;
        r--;
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
    int arr[9] {12, 32, 223, 45, 65, 178, 98, 10, 555};
    display(arr, 9);
    reverse_array(arr, 9);
    display(arr, 9);

    return 0;
}

