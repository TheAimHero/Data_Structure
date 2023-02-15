// shortest distance from source using topological sort (BFS) on directed acyclic graph
// Sample input
 // 5 5 
 // 0 1 2 
 // 2 1 2 
 // 2 4 2 
 // 1 4 8 
 // 1 3 6 

#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
  public:
  void topo_sort(vector<pair<int, int>> edges[], vector<int>& visited, stack<int>& s, int node)
  {
    visited[node] = 1;
    for (auto i : edges[node])
    {
      if (!visited[i.first])
      {
        topo_sort(edges, visited, s, i.first);
      }
    }
    s.push(node);
  }

  vector<int> shortestPath(int N, int M, vector<vector<int>>& edges)
  {
    stack<int> s;
    vector<int> visited(N, 0), distance(N, 100000);
    vector<pair<int, int>> ip[N];
    for (auto i : edges)
    {
      int n1 = i[0], n2 = i[1], wt = i[2];
      ip[n1].push_back({ n2, wt });
    }
    for (int i = 0; i < N; i++)
    {
      if (!visited[i])
      {
        topo_sort(ip, visited, s, i);
      }
    }
    distance[0] = 0;
    while (!s.empty())
    {
      int current = s.top();
      s.pop();
      for (auto i : ip[current])
      {
        int adj_node = i.first, wt = i.second;
        if (distance[current] + wt < distance[adj_node])
        {
          distance[adj_node] = distance[current] + wt;
        }
      }
    }
    for (int i = 0; i < N; i++)
    {
      if (distance[i] == 100000)
      {
        distance[i] = -1;
      }
    }
    return distance;
  }
};

//{ Driver Code Starts.
int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges;
  for (int i = 0; i < m; ++i)
  {
    vector<int> temp;
    for (int j = 0; j < 3; ++j)
    {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    edges.push_back(temp);
  }
  Solution obj;
  vector<int> res = obj.shortestPath(n, m, edges);
  for (auto x : res)
  {
    cout << x << " ";
  }
  cout << "\n";
}

// } Driver Code Ends
