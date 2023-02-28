#include <bits/stdc++.h>
/*
5 4
baa abcd abca cab cada
*/
using namespace std;

class Solution
{
  public:
  vector<int> Order(
      vector<vector<int>> ip,
      vector<int>& in_order,
      queue<int>& q,
      vector<int>& ans,
      int node)
  {
    while (!q.empty())
    {
      int current = q.front();
      q.pop();
      ans.push_back(current);
      for (auto i : ip[current])
      {
        in_order[i]--;
        if (in_order[i] == 0)
        {
          q.push(i);
        }
      }
    }
    return ans;
  }

  string findOrder(string dict[], int N, int K)
  {
    int node = K;
    vector<vector<int>> ip(node);
    vector<int> in_degree(node);
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < N - 1; i++)
    {
      int min_length = min(dict[i].size(), dict[i + 1].size());
      for (int j = 0; j < min_length; j++)
      {
        int w1 = dict[i][j], w2 = dict[i + 1][j];
        if (w1 != w2)
        {
          ip[w1 - 'a'].push_back(w2 - 'a');
          in_degree[w2 - 'a']++;
          break;
        }
      }
    }
    for (int i = 0; i < node; i++)
    {
      if (in_degree[i] == 0)
      {
        q.push(i);
      }
    }
    string ans_string = "";
    Order(ip, in_degree, q, ans, node);
    for (auto i : ans)
    {
      ans_string = ans_string + char(i + 'a');
    }
    return ans_string;
  }
};

string order;
bool f(string a, string b)
{
  int p1 = 0;
  int p2 = 0;
  for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++)
  {
    p1 = order.find(a[i]);
    p2 = order.find(b[i]);
  }

  if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

  return p1 < p2;
}

int main()
{
  int N, K;
  cin >> N >> K;
  string dict[N];
  for (int i = 0; i < N; i++) cin >> dict[i];

  Solution obj;
  string ans = obj.findOrder(dict, N, K);
  order = "";
  for (int i = 0; i < ans.size(); i++) order += ans[i];

  string temp[N];
  std::copy(dict, dict + N, temp);
  sort(temp, temp + N, f);

  bool f = true;
  for (int i = 0; i < N; i++)
    if (dict[i] != temp[i]) f = false;

  if (f)
    cout << 1;
  else
    cout << 0;
  cout << endl;

  return 0;
}
