#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    bool fun(vector<int> ip, vector<int> temp, int index, int sum, int key, bool b)
    {

        if (!b)
        {
            if (index == ip.size())
            {
                return false;
            }
            temp.push_back(ip[index]);
            sum += ip[index];
            if (sum == key)
            {
                display(temp);
                return true;
            }
            if (fun(ip, temp, index + 1, sum, key, b))
            {
                return true;
            }
            sum -= ip[index];
            temp.pop_back();
            if (fun(ip, temp, index + 1, sum, key, b))
            {
                return true;
            }
            return false;
        }
    }
    void display(vector<int> temp)
    {
        for (auto i : temp)
        {

            cout << i << " ";
        }
        cout << endl;
    }
};
int main()
{
    solution a;
    vector<int> ip = {1, 3, 4, 7};
    vector<int> temp;
    a.fun(ip, temp, 0, 0, 7, 0);
    return 0;
}