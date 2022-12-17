#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<vector<int>> final;
    int fun(vector<int> ip, int index, int sum, int key)
    {
        int x = 0;
        int y = 0;
        if (index == ip.size())
        {
            if (sum == key)
            {
                return x + y + 1;
            }
            return x + y;
        }
        x = fun(ip, index + 1, sum += ip[index], key);
        y = fun(ip, index + 1, sum -= ip[index], key);
        return x + y;
    }
    void display()
    {
        for (auto i : final)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    solution a;
    vector<int> ip = {1, 3, 4, 7};
    cout << a.fun(ip, 0, 0, 7);
    a.display();
    return 0;
}