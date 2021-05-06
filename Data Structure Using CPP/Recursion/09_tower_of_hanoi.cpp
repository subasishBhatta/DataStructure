//
// Created by CHINTOO on 06-05-2021.
//

#include "iostream"
#include "string"
using namespace std;
static int count;

void TOH(int n, const string& s1, const string& s2, const string& s3)
{
    if (n == 0)
        return;
    TOH(n-1, s1, s3, s2);
    cout << "Move the disc from tower " << s1 << " to tower " << s3 << endl;
    count++;
    TOH(n-1, s2, s1, s3);
}

int main()
{
    int n = 4;
    string s1{'A'};
    string s2{'B'};
    string s3{'C'};
    TOH(n, s1, s2, s3);
    cout << "The no of steps in this problem with no of disc = " << n << " is " << count << endl;

    return 0;
}
