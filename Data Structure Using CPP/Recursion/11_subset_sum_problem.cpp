//
// Created by CHINTOO on 06-05-2021.
//

#include "iostream"
using namespace std;

int subset_sum(int *arr, int n, int sum)
{
    if (n == 0)
        return (sum == 0)? 1 : 0;
    return subset_sum(arr, n-1, sum) + subset_sum(arr, n-1, sum - arr[n-1]);
}

int main()
{
    int arr[5] = {10, 5, 2, 3, 6};
    int res = subset_sum(arr, 5, 8);
    cout << res;
    return 0;
}
