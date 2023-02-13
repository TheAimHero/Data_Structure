#include <iostream>
#include <set>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> ip, vector<vector<int>>& visited, vector<pair<int, int>>& temp_store, int row, int col, int base_row, int base_col)
{
  visited[row][col] = 1;
  int ip_row = ip.size(), ip_col = ip[0].size();
  temp_store.push_back({ row - base_row, col - base_col });
  int arr_row[]{ -1, 0, 1, 0 }, arr_col[]{ 0, -1, 0, 1 };
  for (int i = 0; i < 4; i++)
  {
    int n_row = row + arr_row[i], n_col = col + arr_col[i];
    if (n_row >= 0 && n_row < ip_row && n_col >= 0 && n_col < ip[0].size() && !visited[n_row][n_col] && ip[n_row][n_col])
    {
      DFS(ip, visited, temp_store, n_row, n_col, row, col);
    }
  }
}

int main()
{
  vector<vector<int>> ip{
    { 1, 1, 0, 1, 1 },
    { 1, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1 },
    { 1, 1, 0, 1, 1 },
  };
  int ip_row = ip.size(), ip_col = ip[0].size();
  vector<vector<int>> visited(ip_row, vector<int>(ip_col, 0));
  set<vector<pair<int, int>>> store;
  for (int row = 0; row < ip_row; row++)
  {
    for (int col = 0; col < ip_col; col++)
    {
      if (!visited[row][col] && ip[row][col] == 1)
      {
        vector<pair<int, int>> temp_store;
        DFS(ip, visited, temp_store, row, col, row, col);
        store.insert(temp_store);
      }
    }
  }
  cout << store.size();
  return 0;
}
