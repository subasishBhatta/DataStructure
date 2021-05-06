//
// Created by CHINTOO on 06-05-2021.
//

#include "bits/stdc++.h"
using namespace std;

int rope_cut(int n, int a, int b, int c)
{
    if (n == 0)
    {
        return 0;
    } else if (n < 0)
    {
        return -1;
    }
    int res = max(rope_cut((n-a), a, b, c), max(rope_cut((n-b), a, b, c), rope_cut((n-c), a, b, c)));
    if (res == -1)
        return -1;
    else
        return res+1;
}

int main()
{
    int ans = rope_cut(9,2,2,2);
    cout << "The maximum cut possible is " << ans << endl;
    return 0;
}
