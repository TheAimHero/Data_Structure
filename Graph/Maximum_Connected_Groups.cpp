//{ Driver Code Starts
// Initial Template for C++

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
/*
2
1 1
0 1
*/
class Disjoint_Set
{
  public:
  vector<int> parent, rank, size;

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
  int MaxConnection(vector<vector<int>>& grid)
  {
    int max_row = grid.size(), max_col = grid[0].size(), max_total{};
    int row_arr[]{ -1, 0, 1, 0 }, col_arr[]{ 0, 1, 0, -1 };
    Disjoint_Set dj(max_row * max_col);

    for (int row = 0; row < max_row; row++)
    {
      for (int col = 0; col < max_col; col++)
      {
        if (!grid[row][col]) continue;
        for (int i = 0; i < 4; i++)
        {
          int n_row = row + row_arr[i], n_col = col + col_arr[i];
          if (n_row < max_row && n_col < max_col && n_row >= 0 && n_col >= 0)
          {
            if (grid[n_row][n_col])
            {
              int current_node = row * max_col + col;
              int adjacent_node = n_row * max_col + n_col;
              dj.Union_By_Size(current_node, adjacent_node);
            }
          }
        }
      }
    }

    for (int row = 0; row < max_row; row++)
    {
      for (int col = 0; col < max_col; col++)
      {
        if (grid[row][col]) continue;
        set<int> store_Uparent;
        for (int i = 0; i < 4; i++)
        {
          int n_row = row + row_arr[i], n_col = col + col_arr[i];
          if (n_row < max_row && n_col < max_col && n_row >= 0 && n_col >= 0)
          {
            if (grid[n_row][n_col])
            {
              int adjacent_node = n_row * max_col + n_col;
              store_Uparent.insert(dj.Find_parent(adjacent_node));
            }
          }
        }
        int total{};
        for (auto it : store_Uparent)
        {
          total += dj.size[it];
        }
        max_total = max(total + 1, max_total);
      }
    }
    for (int i = 0; i < max_row * max_col; i++)
    {
      max_total = max(max_total, dj.size[dj.Find_parent(i)]);
    }
    return max_total;
  }
};

//{ Driver Code Starts.
int main()
{
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> grid[i][j];
    }
  }

  Solution obj;
  cout << obj.MaxConnection(grid) << "\n";
}

// } Driver Code Ends
