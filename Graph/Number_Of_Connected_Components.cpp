#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> store, vector<vector<int>> &visited, int row, int col)
{
  visited[row][col] = 1;
  for (int d_row = -1; d_row <= 1; d_row++)
  {
    for (int d_col = -1; d_col <= 1; d_col++)
    {
      int n_row = row + d_row, n_col = col + d_col;

      if (n_row >= 0 && n_col >= 0 && n_row < store.size() && n_col < store[0].size() && !visited[n_row][n_col] && store[n_row][n_col])
      {
        DFS(store, visited, n_row, n_col);
      }
    }
  }
}

int main()
{
  vector<vector<int>> store = {{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {1, 1, 1, 1}};
  vector<vector<int>> visited(store.size(), vector<int>(store[0].size(), 0));
  int count{};
  for (auto i : store)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << "\n";
  }
  cout << "\n\n";
  for (int i = 0; i < store.size(); i++)
  {
    for (int j = 0; j < store[0].size(); j++)
    {
      if (!visited[i][j] && store[i][j])
      {
        count++; // the dfs needs to be called if there exist a node that is not visited in the first call that is it is yet not visited
        DFS(store, visited, i, j);
      }
    }
  }
  cout << count << "\n";
}
