#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    void subsets(vector<int> ip, vector<int> temp, vector<vector<int>> *ans, int index)
    {
        if (index == ip.size())
        {
            ans->push_back(temp);
        }
        for (int i = index; i < ip.size(); i++)
        {
            if (ip[i] == ip[i - 1] && i != index)
            {
                continue;
            }
            temp.push_back(ip[i]);
            subsets(ip, temp, ans, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> call(vector<int> ip)
    {
        sort(ip.begin(), ip.end());
        vector<int> temp;
        vector<vector<int>> ans;
        subsets(ip, temp, &ans, 0);
        return ans;
    }
};

int main()
{
    solution a;
    vector<int> ip = {1, 2, 2};
    vector<vector<int>> ans = a.call(ip);
    cout << "[";
    for (auto i : ans)
    {
        cout << " [ ";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "], ";
    }
    cout << "]";
    return 0;
}
