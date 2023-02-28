#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
  void DFS(
      vector<int> ip[],
      vector<int>& visited,
      vector<int>& step,
      vector<int>& adj_low,
      vector<vector<int>>& bridges,
      int parent,
      int node)
  {
    static int timer = 1;
    visited[node] = 1;
    step[node] = adj_low[node] = timer;
    timer++;
    for (auto it : ip[node])
    {
      if (it == parent) continue;
      if (!visited[it])
      {
        DFS(ip, visited, step, adj_low, bridges, node, it);
        adj_low[node] = min(adj_low[node], adj_low[it]);
        if (adj_low[it] > step[node])
        {
          bridges.push_back({ it, node });
        }
      }
      else
      {
        adj_low[node] = min(adj_low[node], adj_low[it]);
      }
    }
  }

  vector<vector<int>> criticalConnections(
      int n,
      vector<vector<int>>& connections)
  {
    vector<int> step(n, 0), adj_low(n, 1e8), visited(n, 0), ip[n];
    vector<vector<int>> bridges;
    for (auto i : connections)
    {
      int node1 = i[0], node2 = i[1];
      ip[node1].push_back(node2);
      ip[node2].push_back(node1);
    }
    DFS(ip, visited, step, adj_low, bridges, -1, 0);
    return bridges;
  }
};
