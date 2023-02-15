#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void Safe(vector<int> ip[], queue<int> q, vector<int> in_degree, vector<int>& ans)
{
  while (!q.empty())
  {
    int current = q.front();
    q.pop();
    ans.push_back(current);
    for (auto i : ip[current])
    {
      in_degree[i]--;
      if (!in_degree[i])
      {
        q.push(i);
      }
    }
  }
}

int main()
{
  int node, edges;
  cin >> node >> edges;
  vector<int> store[node], rev_store[node];
  vector<int> in_degree(node, 0), ans;
  queue<int> q;
  for (int i = 0; i < edges; i++)
  {
    int u, w;
    cin >> u >> w;
    store[u].push_back(w);
  }

  for (int i = 0; i < node; i++)
  {
    for (auto j : store[i])
    {
      rev_store[j].push_back(i);
      in_degree[i]++;
    }
  }
  for (int i = 0; i < node; i++)
  {
    if (in_degree[i] == 0)
    {
      q.push(i);
    }
  }
  Safe(rev_store, q, in_degree, ans);
  sort(ans.begin(), ans.end());
  for (auto r : ans)
  {
    cout << r << " ";
  }
  cout << "\n";
  return 0;
}
