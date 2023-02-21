#include <bits/stdc++.h>
using namespace std;

// 3 2
// 0 1
// 1 2

class Solution
{
  public:
  bool Bipartite(vector<int> adj[], vector<int>& node_color, int node)
  {
    queue<int> q;
    q.push(node);
    node_color[node] = 0;
    while (!q.empty())
    {
      int current_node = q.front();
      q.pop();
      for (auto i : adj[current_node])
      {
        if (node_color[i] == -1)
        {
          node_color[i] = !node_color[current_node];
          q.push(i);
        }
        else
        {
          if (node_color[i] == node_color[current_node])
          {
            return false;
          }
        }
      }
    }
    return true;
  }
  bool isBipartite(int V, vector<int> adj[])
  {
    vector<int> node_color(V, -1);
    for (int i = 0; i < V; i++)
    {
      if (node_color[i] == -1)
      {
        if (Bipartite(adj, node_color, i) == false)
        {
          return false;
        }
      }
    }
    return true;
  }
};

int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    Solution obj;
    bool ans = obj.isBipartite(V, adj);
    if (ans)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}
