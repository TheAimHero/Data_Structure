//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
  void DFS(vector<int> ip[], vector<int>& visited, stack<int>& s, int node)
  {
    visited[node] = 1;
    for (auto i : ip[node])
    {
      if (!visited[i])
      {
        DFS(ip, visited, s, i);
      }
    }
    s.push(node);
  }

  void DFST(vector<int> ip[], vector<int>& visited, int node)
  {
    visited[node] = 1;
    for (auto i : ip[node])
    {
      if (!visited[i])
      {
        DFST(ip, visited, i);
      }
    }
  }

  int kosaraju(int V, vector<vector<int>>& adj)
  {
    vector<int> ip[V], visited(V, 0), ip_reverse[V];
    stack<int> s;
    for (int i = 0; i < V; i++)
    {
      for (auto it : adj[i])
      {
        ip[i].push_back(it);
      }
    }
    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        DFS(ip, visited, s, i);
      }
    }
    for (int i = 0; i < V; i++)
    {
      visited[i] = 0;
      for (auto it : ip[i])
      {
        ip_reverse[it].push_back(i);
      }
    }
    int scc{};
    while (!s.empty())
    {
      int top_node = s.top();
      s.pop();
      if (!visited[top_node])
      {
        scc++;
        DFST(ip_reverse, visited, top_node);
      }
    }
    return scc;
  }
};

//{ Driver Code Starts.

int main()
{
  int V, E;
  cin >> V >> E;

  vector<vector<int>> adj(V);

  for (int i = 0; i < E; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  Solution obj;
  cout << obj.kosaraju(V, adj) << "\n";

  return 0;
}

// } Driver Code Ends
