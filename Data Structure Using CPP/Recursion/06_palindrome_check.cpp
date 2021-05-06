//
// Created by CHINTOO on 27-04-2021.
// This function will check whether a string is palindrome or not
//

#include "iostream"
#include "string"
using namespace std;

bool chk_palindrome(string &s, int st, int la)
{
    if (st >= la)
        return true;
    return (s.at(st) == s.at(la)) && chk_palindrome(s, st+1, la-1);
}

int main()
{
    string str = "cabdbac";

    bool res = chk_palindrome(str, 0, str.size()-1);
    if(res)
    {
        cout << "The string is palindrome" << endl;
    } else
    {
        cout << "Not palindrome" << endl;
    }

    return 0;
}
