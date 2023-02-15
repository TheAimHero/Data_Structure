#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
// find the time to rot all the oranges in the grid
// if all the oranges could not be rot then return -1
using namespace std;

int Rot(vector<vector<int>>& store, int ini_row, int ini_col, int rotten)
{
  queue<vector<int>> q;
  for (int i = 0; i < store.size(); i++)
  {
    for (int j = 0; j < store[0].size(); j++)
    {
      if (j == 2)
      {
        q.push({ i, j, 0 });
      }
    }
  }
  int arr_row[]{ -1, 0, 1, 0 }, arr_col[]{ 0, 1, 0, -1 }, max_time{};
  while (!q.empty())
  {
    int row = q.front()[0], col = q.front()[1], time = q.front()[2];
    max_time = max_time >= time ? max_time : time;
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int n_row = row + arr_row[i], n_col = col + arr_col[i];
      if (n_row >= 0 && n_row < store.size() && n_col >= 0 && n_col < store[0].size() && store[n_row][n_col] == 1)
      {
        q.push({ n_row, n_col, time += 1 });
        store[n_row][n_col] = rotten;
      }
    }
  }
  return max_time;
}

int main()
{
  vector<vector<int>> store{ { 0, 1, 2 }, { 0, 1, 1 }, { 2, 1, 1 } };  // 1 represent normal oranges and 2 represent rotten oranges
  int time = Rot(store, 0, 0, 2);
  for (auto i : store)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << "\n";
  }
  cout << time << "\n";
  return 0;
}
