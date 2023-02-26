#include <bits/stdc++.h>
using namespace std;
/*
10 9
2 1 1 1 2 1 2 0 2
1 2 1 1 2 1 1 2 2
2 2 1 2 2 1 1 2 1
1 0 2 0 1 2 2 1 0
2 0 0 2 2 2 2 0 2
2 1 1 1 2 0 2 1 2
2 2 1 1 0 0 1 2 2
0 2 0 2 2 2 2 2 1
2 0 2 0 1 2 2 2 2
1 1 1 2 0 1 2 2 2
3
*/
class Solution
{
  public:
  int orangesRotting(vector<vector<int>>& grid)  // changing the grid array in place
  {
    queue<pair<pair<int, int>, int>> q;  //{ {row,col},time }
    int fresh_count{}, max_row = grid.size(), max_col = grid[0].size(), max_time{}, row_arr[]{ -1, 0, 1, 0 }, col_arr[]{ 0, 1, 0, -1 };
    for (int row = 0; row < max_row; row++)
    {
      for (int col = 0; col < max_col; col++)
      {
        if (grid[row][col] == 2)
        {
          q.push({ { row, col }, 0 });  // if the orange at the position is rotten then mark the position as a starting point for the bfs algorithm by pushing it in the queue
        }
        else if (grid[row][col] == 1)  // if the orange is fresh then increase the fresh_count
        {
          fresh_count++;
        }
      }
    }
    while (!q.empty())
    {
      pair<pair<int, int>, int> current = q.front();
      int current_row = current.first.first, current_col = current.first.second, current_time = current.second;
      q.pop();
      for (int i = 0; i < 4; i++)  // traverse over all the adjacent position in the matrix
      {
        int n_row = current_row + row_arr[i], n_col = current_col + col_arr[i];  // calculate the neighbouring indexes
        if (n_row >= 0 && n_col >= 0 && n_row < max_row && n_col < max_col && grid[n_row][n_col] == 1)  // check the neighbouring indexes are in bounds or not
        {
          fresh_count--;  // if the node can be reached during the bfs then reduce the fresh orange count
          q.push({ { n_row, n_col }, current_time + 1 });  // mark the orange as rotten and push it in the queue to mark it as a starting point for the bfs
          grid[n_row][n_col] = 2;  // mark the orange as rotten at that position
        }
        max_time = max(max_time, current_time);  // calculate the max_time it took to rot the orange (if they can be rot)
      }
    }
    return fresh_count ? max_time : -1;  // return the max_time only if all the oranges were rotten if not return -1
                                         // we can find out if all the oranges are rotten by looking at the fresh_count if it is zero then all the oranges are rotten
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
  int ans = obj.orangesRotting(grid);
  cout << ans << "\n";

  return 0;
}
