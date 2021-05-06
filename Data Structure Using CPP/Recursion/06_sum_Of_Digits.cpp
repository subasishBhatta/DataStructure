//
// Created by CHINTOO on 27-04-2021.
// This is a program to calculate the sum of digits using recursion
//

#include "iostream"
using namespace std;

int digit_sum(int n)
{
    if (n == 0)
        return 0;
    return (n%10) + digit_sum(n/10);
}

int main()
{
    int x = 1;
    cout << "The sum of digits is " << digit_sum(x) << endl;

    return 0;
}
