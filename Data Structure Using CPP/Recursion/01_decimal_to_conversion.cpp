//
// Created by CHINTOO on 26-04-2021.
//

#include "iostream"
using namespace std;

void conversion(int n)
{
    if (n == 0)
    {
        return;
    }
    conversion(n/16);
//    cout << n%8;
    int x = n%16;
//    if (x == 10)
//        cout << 'A';
//    else if (x == 11)
//        cout << 'B';
//    else if (x == 12)
//        cout << 'C';
//    else if (x == 13)
//        cout << 'D';
//    else if (x == 14)
//        cout << 'E';
//    else if (x == 15)
//        cout << 'F';
//    else
//        cout << x;
}

int main()
{
    int n;
    cout << "Enter a number whose binary value you want to find:" << endl;
    cin >> n;
    conversion(n);

    return 0;
}
