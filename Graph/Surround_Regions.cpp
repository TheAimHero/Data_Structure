#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<char>> store, vector<vector<int>> visited, int row, int col)
{
  static int arr_row[] = { -1, 0, 1, 0 }, arr_col[] = { 0, 1, 0, -1 }, n = store.size(), m = store[0].size();
  for (int i = 0; i < 4; i++)
  {
    int n_row = row + arr_row[i], n_col = col + arr_col[i];
    if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < m && !visited[n_row][n_col])
    {
      visited[n_row][n_col] = 1;
      DFS(store, visited, n_row, n_col);
    }
    else
    {
      return;
    }
  }
}

void Surround(vector<vector<char>>& store)
{
  int ini_row = store.size(), ini_col = store[0].size();
  vector<vector<int>> visited(ini_row, vector<int>(ini_col, 0));
  for (int i = 0; i < ini_row; i++)
  {
    if (!visited[0][i])
    {
      visited[0][i] = 1;
      DFS(store, visited, 0, i);
    }
    if (!visited[ini_row - 1][i])
    {
      visited[ini_row - 1][i] = 1;
      DFS(store, visited, ini_row - 1, i);
    }
  }
  for (int i = 0; i < ini_col; i++)
  {
    if (!visited[i][0])
    {
      visited[i][0] = 1;
      DFS(store, visited, i, 0);
    }
    if (!visited[i][ini_col - 1])
    {
      visited[i][ini_col - 1] = 1;
      DFS(store, visited, i, ini_col);
    }
  }
  for (int i = 0; i < ini_row; i++)
  {
    for (int j = 0; j < ini_col; j++)
    {
      if (!visited[i][j] && store[i][j] == 'O')
      {
        store[i][j] = 'X';
      }
    }
  }
}

int main()
{
  vector<vector<char>> store{ { 'X', 'O', 'O', 'X' }, { 'X', 'X', 'X', 'X' }, { 'X', 'O', 'O', 'X' }, { 'X', 'X', 'X', 'X' } };
  Surround(store);
  for (auto i : store)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << "\n";
  }
}
