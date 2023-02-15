#include <iostream>
#include <set>
#include <vector>

using namespace std;

// Detect the number of islands all the ones are land and the zeros are water
// the land on left right up and down are connected
// if the shape is same then the islands are considered non distinct

void DFS(vector<vector<int>> ip, vector<vector<int>>& visited, vector<pair<int, int>>& temp_store, int row, int col, int base_row, int base_col)
{
  visited[row][col] = 1;
  static int ip_row = ip.size(), ip_col = ip[0].size(), arr_row[]{ -1, 0, 1, 0 }, arr_col[]{ 0, -1, 0, 1 };
  temp_store.push_back({ row - base_row, col - base_col });  // the difference between the adjacent nodes
  for (int i = 0; i < 4; i++)  // search for land up down left and right
  {
    int n_row = row + arr_row[i], n_col = col + arr_col[i];
    if (n_row >= 0 && n_row < ip_row && n_col >= 0 && n_col < ip[0].size() && !visited[n_row][n_col] && ip[n_row][n_col])  // call for the dfs only if there is land
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
  for (int row = 0; row < ip_row; row++)  // dfs has no way of reaching the land that are not connected so we traverse the input array
  {
    for (int col = 0; col < ip_col; col++)  // and see if the position has land and begin the dfs from there
    {
      if (!visited[row][col] && ip[row][col] == 1)  // if the position is not visited and also it has land then perform Dfs on that position
      {
        vector<pair<int, int>> temp_store;
        DFS(ip, visited, temp_store, row, col, row, col);
        store.insert(temp_store);  // the temp_store vector will contain only one island and the set will store only one distinct island
      }
    }
  }
  cout << store.size();
  return 0;
}
