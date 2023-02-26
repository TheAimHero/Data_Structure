#include <bits/stdc++.h>
using namespace std;
/*
6 5
0 3 9
0 4 2
0 5 2
1 3 5
2 3 10
*/
class Disjoint_Set
{
  private:
  vector<int> parent, rank, size;

  public:
  Disjoint_Set(int nodes)
  {
    parent.resize(nodes + 1);
    rank.resize(nodes + 1, 0);
    size.resize(nodes + 1, 1);
    for (int i = 0; i <= nodes; i++)
    {
      parent[i] = i;
    }
  }

  int Find_parent(int node)
  {
    if (parent[node] == node)
    {
      return node;
    }
    return parent[node] = Find_parent(parent[node]);
  }

  void Union_By_Rank(int node1, int node2)
  {
    int ultimate_parent_node1 = Find_parent(node1);
    int ultimate_parent_node2 = Find_parent(node2);
    if (ultimate_parent_node1 == ultimate_parent_node2) return;
    if (rank[ultimate_parent_node1] > rank[ultimate_parent_node2])
    {
      parent[ultimate_parent_node2] = ultimate_parent_node1;
    }
    else if (rank[ultimate_parent_node1] < rank[ultimate_parent_node2])
    {
      parent[ultimate_parent_node1] = ultimate_parent_node2;
    }
    else
    {
      parent[ultimate_parent_node2] = ultimate_parent_node1;
      rank[ultimate_parent_node1]++;
    }
  }

  void Union_By_Size(int node1, int node2)
  {
    int ultimate_parent_node1 = Find_parent(node1);
    int ultimate_parent_node2 = Find_parent(node2);
    if (ultimate_parent_node1 == ultimate_parent_node2) return;
    if (size[ultimate_parent_node1] > size[ultimate_parent_node2])
    {
      parent[ultimate_parent_node2] = ultimate_parent_node1;
      size[ultimate_parent_node1] += size[ultimate_parent_node2];
    }
    else
    {
      parent[ultimate_parent_node2] = ultimate_parent_node1;
      size[ultimate_parent_node1] += size[ultimate_parent_node2];
    }
  }
};

class Solution
{
  public:
  int spanningTree(int V, vector<vector<int>> adj[])
  // node1 is the index node two is at adj[i][0] and weight is at adj[i][1]
  {
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < V; i++)
    {
      for (auto it : adj[i])
      {
        int node1 = i, node2 = it[0], weight = it[1];
        edges.push_back({ weight, { node1, node2 } });
      }
    }
    Disjoint_Set dj(V);
    sort(edges.begin(), edges.end());
    int mst_weight{};
    for (auto it : edges)
    {
      int node1 = it.second.first, node2 = it.second.second, weight = it.first;
      if (dj.Find_parent(node1) != dj.Find_parent(node2))
      {
        dj.Union_By_Size(node1, node2);
        mst_weight += weight;
      }
    }
    return mst_weight;
  }
};

//{ Driver Code Starts.

int main()
{
  int V, E;
  cin >> V >> E;
  vector<vector<int>> adj[V];
  int i = 0;
  while (i++ < E)
  {
    int u, v, w;
    cin >> u >> v >> w;
    vector<int> t1, t2;
    t1.push_back(v);
    t1.push_back(w);
    adj[u].push_back(t1);
    t2.push_back(u);
    t2.push_back(w);
    adj[v].push_back(t2);
  }

  Solution obj;
  cout << obj.spanningTree(V, adj) << "\n";

  return 0;
}

// } Driver Code Ends
