//
// Created by CHINTOO on 27-04-2021.
// Program to print n natural number in reverse order
//

#include "iostream"
using namespace std;
void rev_natural(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    rev_natural(n-1);
}

int main()
{
    int n = 10;
    rev_natural(n);

    return 0;
}
