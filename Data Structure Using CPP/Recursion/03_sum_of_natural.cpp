//
// Created by CHINTOO on 27-04-2021.
//

#include "iostream"
using namespace std;

long nat_sum(int n)
{
    if (n == 0)
        return 0;
    return n + nat_sum(n-1);
}

int main()
{
    int num = 10;
    cout << "The sum of first " << num << " natural number is " << nat_sum(num) << endl;

    return 0;
}
