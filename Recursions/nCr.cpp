
#include <iostream>
using namespace std;
int C(int n, int r)
{
    if ((n == r) || (r == 0))
    {
        return 1;
    }
    else
    {

        return C(n - 1, r) + C(n - 1, r - 1);
    }
}
int main()
{
    int result = C(4, 2);
    cout << result;
    return 0;
}