#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    void subsets(vector<int> ip, int index, int sum, vector<int> *ans)
    {
        if (index == ip.size())
        {
            ans->push_back(sum);
            return;
        }
        subsets(ip, index + 1, sum += ip[index], ans);
        subsets(ip, index + 1, sum -= ip[index], ans);
    }
    vector<int> fun(vector<int> ip)
    {
        vector<int> ans;
        subsets(ip, 0, 0, &ans);
        return ans;
    }
};

int main()
{
    solution a;
    vector<int> ip = {5, 4, 3, 1, 2};
    vector<int> ans = a.fun(ip);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}