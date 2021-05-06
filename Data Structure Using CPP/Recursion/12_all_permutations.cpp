//
// Created by CHINTOO on 06-05-2021.
//

#include "bits/stdc++.h"
using namespace std;

void permute(string &s, int i = 0)
{
    if (i == s.length()-1)
    {
        cout << s << " ";
        return;
    }
    for (int j = i; j < s.length(); ++j) {
        swap(s[i], s[j]);
        permute(s, i+1);
        swap(s[j], s[i]);
    }
}

int main()
{
    string str {"ABC"};
    permute(str);
    return 0;
}
