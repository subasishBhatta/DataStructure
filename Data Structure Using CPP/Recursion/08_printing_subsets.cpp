//
// Created by CHINTOO on 06-05-2021.
//

#include "iostream"
#include "string"
using namespace std;

void sub_set(string &s, const string& curr, int index)
{
    if (index == s.length())
    {
        cout << curr << " ";
        return;
    }
    sub_set(s, curr, index+1);
    sub_set(s, curr+s[index], index+1);
}

int main()
{
    string str = "ABC";
    string curr;
    sub_set(str, curr, 0);

    return 0;
}
