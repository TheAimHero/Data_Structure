#include <bits/stdc++.h>
using namespace std;
/*
3 4
0 1 1 0
1 1 0 0
0 0 1 1
*/
class Solution
{
  public:
  vector<vector<int>> nearest(vector<vector<int>> grid)
  {
    int max_row = grid.size(), max_col = grid[0].size(), row_arr[]{ -1, 0, 1, 0 }, col_arr[]{ 0, 1, 0, -1 };
    vector<vector<int>> visited(max_row, vector<int>(max_col, 0)), distance(max_row, vector<int>(max_col, 1e9));
    queue<array<int, 3>> q;  // stores --> row,col,distance

    for (int row = 0; row < max_row; row++)
    {
      for (int col = 0; col < max_col; col++)
      {
        if (grid[row][col])
        {
          q.push({ row, col, 0 });
          visited[row][col] = 1;
          distance[row][col] = 0;
        }
      }
    }
    while (!q.empty())
    {
      int current_row = q.front()[0], current_col = q.front()[1], current_distance = q.front()[2];
      q.pop();
      for (int i = 0; i < 4; i++)
      {
        int n_row = current_row + row_arr[i], n_col = current_col + col_arr[i];
        if (n_row >= 0 && n_col >= 0 && n_row < max_row && n_col < max_col && !visited[n_row][n_col])
        {
          q.push({ n_row, n_col, current_distance + 1 });
          distance[n_row][n_col] = current_distance + 1;
          visited[n_row][n_col] = 1;
        }
      }
    }
    return distance;
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }
  Solution obj;
  vector<vector<int>> ans = obj.nearest(grid);
  for (auto i : ans)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << "\n";
  }

  return 0;
}
