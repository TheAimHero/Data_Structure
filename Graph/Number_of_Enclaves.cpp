#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// 4 4
// 0 0 0 0
// 1 0 1 0
// 0 1 1 0
// 0 0 0 0

class Solution
{
  public:
  void BFS(vector<vector<int>>& grid, vector<vector<int>>& visited, queue<pair<int, int>> q)
  {
    int arr_row[]{ -1, 0, 1, 0 }, arr_col[]{ 0, 1, 0, -1 };  // template array to traverse all 4 direction around a element in a matrix
    int max_row = grid.size(), max_col = grid[0].size();
    while (!q.empty())
    {
      int row = q.front().first, col = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++)  // try in all four direction
      {
        int n_row = row + arr_row[i], n_col = col + arr_col[i];
        if (n_row >= 0 && n_row < max_row && n_col >= 0 && n_col < max_col && grid[n_row][n_col] && !visited[n_row][n_col])  // check if the index is in bound and if it is then check if there is land at that index and it is not already visited
        {
          visited[n_row][n_col] = 1;  // mark the land as visited we don't want to visit here again
          q.push({ n_row, n_col });  // push in queue will traverse from there later
        }
      }
    }
  }

  int numberOfEnclaves(vector<vector<int>>& grid)
  {
    int ip_row = grid.size(), ip_col = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> visited(ip_row, vector<int>(ip_col, 0));
    // we only take the land at the edges because if we want to jump of the edge we have to reach the land at the edge for that we check for any land that is connected to the edge by performing a bfs/dfs from the land at the edge
    for (int i = 0; i < ip_row; i++)  // traverse only the edge of the matrix the two horizontal sides
    {
      if (!visited[i][0] && grid[i][0])
      {
        q.push({ i, 0 });  // add these indexes to perform bfs from
        visited[i][0] = 1;
      }
      if (!visited[i][ip_col - 1] && grid[i][ip_col - 1])
      {
        q.push({ i, ip_col - 1 });  // add these indexes to perform bfs from
        visited[i][ip_col - 1] = 1;
      }
    }

    for (int i = 0; i < ip_col; i++)  // traverse only the edge of the matrix only the two vertical sides
    {
      if (!visited[0][i] && grid[0][i])
      {
        q.push({ 0, i });  // add these indexes to perform bfs from
        visited[0][i] = 1;
      }
      if (!visited[ip_row - 1][i] && grid[ip_row - 1][i])
      {
        q.push({ ip_row - 1, i });  // add these indexes to perform bfs from
        visited[ip_row - 1][i] = 1;
      }
    }
    BFS(grid, visited, q);
    int count{};
    for (int i = 0; i < ip_row; i++)
    {
      for (int j = 0; j < ip_col; j++)
      {
        if (!visited[i][j] && grid[i][j])  // if the land is not visited then it means there is no way the land connects to the edge of the matrix so this land is an enclave
        {
          count++;
        }
      }
    }
    return count;
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }
  Solution obj;
  cout << obj.numberOfEnclaves(grid) << endl;
}
