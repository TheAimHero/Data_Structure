// fill the grid with a diffrent color (old_color --> new_color)
#include <iostream>
#include <vector>

using namespace std;

void Flood_Fill(vector<vector<int>>& store, int row, int col, int new_color)
{
  int old_color = store[row][col];
  store[row][col] = new_color;
  static int max_row = store.size(), max_col = store[0].size(), row_arr[]{ -1, 0, 1, 0 }, col_arr[]{ 0, 1, 0, -1 };
  for (int i = 0; i < 4; i++)
  {
    int n_row = row + row_arr[i], n_col = col + col_arr[i];
    if (n_row >= 0 && n_row < max_row && col >= 0 && n_col < max_col && store[n_row][n_col] == old_color)
    {
      Flood_Fill(store, n_row, n_col, new_color);
    }
  }
}

int main()
{
  int new_color = 2;
  vector<vector<int>> store = { { 1, 1, 1 }, { 1, 1, 0 }, { 1, 0, 1 } };
  Flood_Fill(store, 0, 0, new_color);
  for (auto i : store)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << "\n";
  }
  return 0;
}
