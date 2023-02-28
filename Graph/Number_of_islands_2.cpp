//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <vector>
using namespace std;
/*
4
5
4
1 1
0 1
3 3
3 4
*/
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
// User function Template for C++
class Solution
{
  public:
  vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators)
  {
    // to traverse the adjacent blocks in the grid in all four directions
    int count{}, row_arr[]{ -1, 0, 1, 0 }, col_arr[]{ 0, 1, 0, -1 };
    // keep track of the visited blocks in the grid
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<int> ans;
    Disjoint_Set dj(n * m - 1);
    for (auto i : operators)
    {
      int row = i[0], col = i[1];
      if (visited[row][col])
      {
        ans.push_back(count);
        continue;
      }
      visited[row][col] = 1;
      count++;
      for (int i = 0; i < 4; i++)
      {
        int n_row = row + row_arr[i], n_col = col + col_arr[i];
        if (n_row < n && n_col < m && n_row >= 0 && n_col >= 0)
        {
          int node_number = row * m + col, n_node_number = n_row * m + n_col;
          if (visited[n_row][n_col])
          {
            if (dj.Find_parent(node_number) != dj.Find_parent(n_node_number))
            {
              dj.Union_By_Size(node_number, n_node_number);
              count--;
            }
          }
        }
      }
      ans.push_back(count);
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a;

  for (int i = 0; i < k; i++)
  {
    vector<int> temp;
    for (int j = 0; j < 2; j++)
    {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    a.push_back(temp);
  }

  Solution obj;
  vector<int> res = obj.numOfIslands(n, m, a);

  for (auto x : res) cout << x << " ";
  cout << "\n";
}

// } Driver Code Ends
