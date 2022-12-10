#include <iostream>
using namespace std;
int fib(int l)
{

    if (l <= 1)
    {
        return l;
    }
    return (fib(l - 1) + fib(l - 2));
}
int main()
{
    int r = fib(5);
    cout << r;
    return 0;
}