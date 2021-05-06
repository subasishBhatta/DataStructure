//
// Created by CHINTOO on 27-04-2021.
//

#include "iostream"
using namespace std;

int fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return (fibonacci((n-1)) + fibonacci((n-2)));
}

int main()
{
    int num;
    cout << "Enter which fibonacci number you want to find:" << endl;
    cin >> num;

    int res = fibonacci(num);
    cout << "The " << num << " fibonacci number is " << res << endl;

    return 0;
}
