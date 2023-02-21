#include <array>
#include <bits/stdc++.h>
#include <set>
#include <utility>
#include <vector>
using namespace std;
/*
5 4
1 1 1 1
1 1 0 1
1 1 1 1
1 1 0 0
1 0 0 1
0 1
2 2
*/
class Solution
{
  public:
  void shortest(vector<vector<int>> grid, vector<vector<int>>& distance, set<pair<pair<int, int>, int>> s)
  {
    int row_arr[]{ -1, 0, 1, 0 }, col_arr[]{ 0, 1, 0, -1 };
    int grid_row = grid.size(), grid_col = grid[0].size();
    while (!s.empty())
    {
      pair<pair<int, int>, int> current = *s.begin();
      int current_row = current.first.first, current_col = current.first.second;
      int current_distance = current.second;
      s.erase(s.begin());
      for (int i = 0; i < 4; i++)
      {
        int n_row = current_row + row_arr[i], n_col = current_col + col_arr[i];
        if (n_row >= 0 && n_row < grid_row && n_col >= 0 && n_col < grid_col && grid[n_row][n_col] && distance[n_row][n_col] > current_distance + 1)
        {
          s.erase({ { n_row, n_col }, distance[n_row][n_col] });
          distance[n_row][n_col] = current_distance + 1;
          s.insert({ { n_row, n_col }, distance[n_row][n_col] });
        }
      }
    }
  }

  int shortestPath(vector<vector<int>>& grid, pair<int, int> source, pair<int, int> destination)
  {
    int grid_row = grid.size(), grid_col = grid[0].size();
    vector<vector<int>> distance(grid_row, vector<int>(grid_col, 1e9));
    set<pair<pair<int, int>, int>> s;
    distance[source.first][source.second] = 0;
    s.insert({ { source.first, source.second }, 0 });
    shortest(grid, distance, s);
    int ans = distance[destination.first][destination.second];
    if (ans == 1e9)
    {
      return -1;
    }
    return ans;
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

  pair<int, int> source, destination;
  cin >> source.first >> source.second;
  cin >> destination.first >> destination.second;
  Solution obj;
  cout << obj.shortestPath(grid, source, destination) << endl;
}
