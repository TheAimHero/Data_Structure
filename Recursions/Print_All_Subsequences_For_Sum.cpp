#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<vector<int>> final;
    void fun(vector<int> ip, vector<int> temp, int index, int key)
    {
        if (index == ip.size())
        {
            if (key == 0)
            {
                final.push_back(temp);
            }
            return;
        }
        temp.push_back(ip[index]);
        fun(ip, temp, index + 1, key -= ip[index]);
        temp.pop_back();
        fun(ip, temp, index + 1, key += ip[index]);
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
    vector<int> ip = {1, 3, 4, 7, 5, 8, -4, -2, -5};
    vector<int> temp;
    a.fun(ip, temp, 0, 7);
    a.display();
    return 0;
}