//
// Created by CHINTOO on 13-06-2021.
// Here we use the most efficient way to find the second largest element in the array
// There is another naive approach to find the same where we need to traverse the array twice,
// Once to find the largest and another time to find the second largest (T.C - O(n), S.C - O(n))
// But in this method we only traverse once and find the second largest
// Time complexity in this approach - O(n) and space complexity - O(1)
//


#include "iostream"
using namespace std;

int second_largest(const int * arr, int n)
{
    int res = -1;
    int large = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[large])
        {
            res = large;
            large = i;
        } else if (arr[i] != arr[large])
        {
            if (res == -1 || arr[i] > arr[res])
            {
                res = i;
            }
        }
    }
    return res+1;

}

int main()
{
    int arr[8] {12, 32, 223, 45, 65, 178, 98, 10};

    int ind = second_largest(arr, 8);
    cout << "The Second largest element in the array is at position " << ind
         << " and the value is " << arr[ind-1] << endl;

    return 0;
}

