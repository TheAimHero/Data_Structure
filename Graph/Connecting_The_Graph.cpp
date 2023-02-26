//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
6 5
0 1
0 2
0 3
1 2
1 3
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
  int Solve(int n, vector<vector<int>>& edge)
  {
    Disjoint_Set dj(n);
    int extra_edge{}, components{};
    for (auto i : edge)
    {
      int node1 = i[0], node2 = i[1];
      if (dj.Find_parent(node1) == dj.Find_parent(node2))
      {
        extra_edge++;
        continue;
      }
      dj.Union_By_Size(node1, node2);
    }
    for (int i = 0; i < n; i++)
    {
      if (dj.parent[i] == i)
      {
        components++;
      }
    }
    return extra_edge >= components - 1 ? components - 1 : -1;
  }
};

//{ Driver Code Starts.

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj;

  for (int i = 0; i < m; ++i)
  {
    vector<int> temp;
    for (int j = 0; j < 2; ++j)
    {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    adj.push_back(temp);
  }

  Solution Obj;
  cout << Obj.Solve(n, adj) << "\n";

  return 0;
}
// } Driver Code Ends
