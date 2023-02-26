#include <bits/stdc++.h>
using namespace std;

// 3 2
// 0 1
// 1 2

class Solution
{
  public:
  // a graph can be Bipartite only if the cycle existing in the graph (if any) consist of even number of nodes
  // if the cycle contain odd number of nodes then the graph can never be Bipartite
  // therefore this algorithm can be used to check if the cycle in the graph is even or odd node cycle
  bool Bipartite(vector<int> adj[], vector<int>& node_color, int node)  // a Bipartite graph is a graph which can be colored with two colors in such a way that no two adjacent nodes have the same color
  {
    queue<int> q;  // to implement the bfs algorithm
    q.push(node);  //
    node_color[node] = 0;
    while (!q.empty())
    {
      int current_node = q.front();
      q.pop();
      for (auto i : adj[current_node])  // traverse all the adjacent nodes in the adjacency list
      {
        if (node_color[i] == -1)  // if the node is not already colored
        {
          node_color[i] = !node_color[current_node];  // color it with the opposite color of the parent node
          q.push(i);
        }
        else
        {
          if (node_color[i] == node_color[current_node])  // if the node is already colored and with the same color as the adjacent node then it is not a Bipartite graph therefore return false
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
    for (int i = 0; i < V; i++)  // to compensate for multiple components
    {
      if (node_color[i] == -1)  // only if the node is not already colored that is the node has been visited
      {
        if (Bipartite(adj, node_color, i) == false)  // if the Bipartite function returns a false for any iteration then the algorithm can be terminatied instantly as the graph is not Bipartite
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
