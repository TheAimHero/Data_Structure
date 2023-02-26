//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
3
1 0 1
0 1 0
1 0 1
*/
// } Driver Code Ends
// User function Template for C++
class Disjoint_Set
{
  public:
  vector<int> parent, rank, size;

  public:
  Disjoint_Set(int nodes)
  {
    parent.resize(nodes + 1);
    rank.resize(nodes + 1, 1);
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
  int numProvinces(vector<vector<int>> adj, int V)
  {
    Disjoint_Set dj(V);
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        if (adj[i][j] == 1)
        {
          dj.Union_By_Size(i, j);
        }
      }
    }
    int count{};
    for (int i = 0; i < V; i++)
    {
      if (dj.parent[i] == i)
      {
        count++;
      }
    }
    return count;
  }
};

//{ Driver Code Starts.

int main()
{
  int V, x;
  cin >> V;

  vector<vector<int>> adj;

  for (int i = 0; i < V; i++)
  {
    vector<int> temp;
    for (int j = 0; j < V; j++)
    {
      cin >> x;
      temp.push_back(x);
    }
    adj.push_back(temp);
  }

  Solution ob;
  cout << ob.numProvinces(adj, V) << endl;

  return 0;
}
// } Driver Code Ends
