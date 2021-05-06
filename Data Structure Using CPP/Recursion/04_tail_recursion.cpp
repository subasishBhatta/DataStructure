//
// Created by CHINTOO on 27-04-2021.
// This is the explanation of tail recursion
//
/*
 * If we use tail recursion then the code will be faster in modern compiler
 * So if there is a possibility of tail recursion then we must do it.
 * Tail recursion means calling the function at the end, so that the called function
 * doesn't need to add the instruction pointer at the stack i.e. this call is the last instruction of the program
 * After that the program ends. e.g.
 * #include "iostream"
    using namespace std;
    void rev_natural(int n)
    {
        if (n == 0)
        {
            return;
        }
        cout << n << " ";
        natural(n-1);
    }

    int main()
    {
        int n = 10;
        natural(n);

        return 0;
    }
* In the above program we call the function natural at the end so the compiler change it into a statement
 * So it will become faster, Hence we generally prefer tail recursion.
 * Hence sometimes we use tail recursion in some program where it is possible
 * In the below program we make this forcefully tail recursive
 */

#include "iostream"
using namespace std;

void natural(int n, int k)
{
    if (n == 0)
    {
        return;
    }
    cout << k << " ";
    natural(n-1, k+1);
}

int main()
{
    natural(10, 1);
    return 0;
}
