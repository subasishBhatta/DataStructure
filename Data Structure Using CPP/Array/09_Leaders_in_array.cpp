//
// Created by CHINTOO on 13-06-2021.
// Leader in an array means all the element present right to this element must be smaller than this element
// [7, 11, 10, 11, 8, 9]
// In the above array second 11 is the leader since all the element right to it is smaller
// Also 9 is the leader since it has no element in its right
// Here the naive approach - (T.C = O(n*n), S.C = O(1))
// Here the efficient approach - (T.C = O(n), S.C = O(1)) - But it will print the leader in reverse order
//

#include "iostream"
using namespace std;

void display(int *arr, int n)
{
    cout << "Displaying the array: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Naive approach - (Time Complexity - O(n^2), Space Complexity - O(1))
void naive_leader(const int *arr, int n)
{
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = i+1; j < n; ++j) {
            if (arr[j] > arr[i])
            {
                flag = true;
            }
        }
        if (!flag)
            cout << arr[i] << " " ;
    }
    cout << endl;
}

// Efficient approach
void leader(int * arr, int n)
{
    int cur_leader = arr[n-1];
    cout << cur_leader << " ";
    for (int i = n-2; i > 0; --i) {
        if (arr[i] > cur_leader)
        {
            cur_leader = arr[i];
            cout << cur_leader << " ";
        }
    }
    cout << endl;
}

int main()
{
    int arr[8] {12, 32, 14, 45, 65, 51, 55, 10};
    display(arr, 8);
    naive_leader(arr, 8);
    leader(arr, 8);

    return 0;
}

