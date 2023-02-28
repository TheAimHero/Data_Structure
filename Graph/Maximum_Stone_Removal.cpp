//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Disjoint_Set
{
  private:
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

// } Driver Code Ends
class Solution
{
  public:
  int maxRemove(vector<vector<int>>& stones, int n)
  {
    int max_row = 0, max_col = 0;
    for (auto i : stones)
    {
      max_row = max(max_row, i[0]);
      max_col = max(max_col, i[1]);
    }
    Disjoint_Set dj(max_row + max_col + 1);
    map<int, int> Stone_nodes;
    for (auto i : stones)
    {
      int row = i[0], col = i[1] + max_row + 1;
      dj.Union_By_Size(row, col);
      Stone_nodes[row] = 1;
      Stone_nodes[col] = 1;
    }
    int count{};
    for (auto i : Stone_nodes)
    {
      if (i.first == dj.Find_parent(i.first))
      {
        count++;
      }
    }
    return n - count;
  }
};

//{ Driver Code Starts.

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> adj;

  for (int i = 0; i < n; ++i)
  {
    vector<int> temp;
    for (int i = 0; i < 2; ++i)
    {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    adj.push_back(temp);
  }

  Solution obj;

  cout << obj.maxRemove(adj, n) << "\n";
}
// } Driver Code Ends
