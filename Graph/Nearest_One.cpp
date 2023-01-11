#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

vector<vector<int>> Distance(vector<vector<int>>& store, int row, int col)
{
  vector<vector<int>> visited(store.size(), vector<int>(store[0].size()));
  vector<vector<int>> distance_matrix(store.size(), vector<int>(store[0].size()));
  queue<array<int, 3>> q;
  for (int i = 0; i < store.size(); i++)
  {
    for (int j = 0; j < store[0].size(); j++)
    {
      if (store[i][j] == 1)
      {
        q.push({ i, j, 0 });
        visited[i][j] = 1;
      }
    }
  }
  int arr_row[] = { -1, 0, +1, 0 }, arr_col[] = { 0, 1, 0, -1 };
  while (!q.empty())
  {
    int row = q.front()[0], col = q.front()[1], distance = q.front()[2];
    q.pop();
    distance_matrix[row][col] = distance;
    for (int i = 0; i < 4; i++)
    {
      int n_row = row + arr_row[i], n_col = col + arr_col[i];
      if (n_row >= 0 && n_row < store.size() && n_col >= 0 && n_col < store[0].size() && !visited[n_row ][n_col])
      {
        q.push({ n_row, n_col, distance + 1 });
        visited[n_row][n_col] = 1;
      }
    }
  }

  return distance_matrix;
}

int main()
{
  vector<vector<int>> store = { { 0, 1, 0 }, { 0, 0, 1 }, { 0, 1, 0 } };
  vector<vector<int>> distance_matrix = Distance(store, 0, 0);
  for (auto i : distance_matrix)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << "\n";
  }
  return 0;
}
