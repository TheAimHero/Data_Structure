#include <iostream>
#include <vector>

using namespace std;

void Flood_Fill(vector<vector<int>>& store, int row, int col, int new_color)
{
  int old_color = store[row][col];
  store[row][col] = new_color;
  if (row - 1 >= 0 && store[row - 1][col] == old_color)
  {
    Flood_Fill(store, row - 1, col, new_color);
  }
  if (row + 1 < store.size() && store[row + 1][col] == old_color)
  {
    Flood_Fill(store, row + 1, col, new_color);
  }
  if (col - 1 >= 0 && store[row][col - 1] == old_color)
  {
    Flood_Fill(store, row, col - 1, new_color);
  }
  if (col + 1 < store[0].size() && store[row][col + 1] == old_color)
  {
    Flood_Fill(store, row, col + 1, new_color);
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
