#include <iostream>
using namespace std;
double expo(int b, int l)
{
    static double p = 1, f = 1, total = 0;
    if (l == 0)
    {
        return 1;
    }
    else
    {
        total = expo(b, l - 1);
        p *= b;
        f *= l;
        return total + (p / f);
    }
}
int main()
{
    int x = expo(2, 5);
    cout << x;
    return 0;
}