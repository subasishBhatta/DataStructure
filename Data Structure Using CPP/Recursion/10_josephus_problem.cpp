//
// Created by CHINTOO on 06-05-2021.
//

#include "iostream"
using namespace std;

int jos(int n, int k)
{
    if (n == 1)
        return 0;
    return (jos(n-1, k)+k) % n;
}

int main()
{
    int res = jos(5, 3);
    cout << "The survivor is " << res << endl;

    return 0;
}
