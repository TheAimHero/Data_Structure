#include <iostream>
using namespace std;
double e(int b, int l)
{
    double s = 1;
    int i;
    double num = 1;
    double den = 1;
    for (int i = 1; i <= l; i++)
    {
        num *= b;
        den *= i;
        s += (num / den);
    }
    return s;
}
int main()
{
    double t = e(2, 2);
    cout << t;
    return 0;
}