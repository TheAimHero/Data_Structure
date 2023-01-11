#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int Enclaves(std::vector<std::vector<int>> store)
{
  int ini_row = store.size(), ini_col = store[0].size();
  std::vector<std::vector<int>> visited(ini_row, std::vector<int>(ini_col, 0));
  std::queue<std::pair<int, int>> q;
  int arr_row[]{ -1, 0, +1, 0 }, arr_col[]{ 0, +1, 0, -1 }, count{};
  for (int row = 0; row < ini_row; row++)
  {
    if (store[row][0])
    {
      q.push({ row, 0 });
      visited[row][0] = 1;
    }
    if (store[row][ini_col - 1])
    {
      q.push({ row, ini_col - 1 });
      visited[row][ini_col] = 1;
    }
  }
  for (int col = 1; col < ini_col - 2; col++)
  {
    if (store[0][col])
    {
      q.push({ 0, col });
      visited[0][col] = 1;
    }
    if (store[ini_row - 1][col])
    {
      q.push({ ini_row - 1, col });
      visited[ini_row - 1][col] = 1;
    }
  }
  while (!q.empty())
  {
    int row = q.front().first, col = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int n_row = row + arr_row[i], n_col = col + arr_col[i];
      if (n_row >= 0 && n_row < ini_row && n_col >= 0 && n_col < ini_col && !visited[n_row][n_col] && store[n_row][n_col])
      {
        q.push({ n_row, n_col });
        visited[n_row][n_col] = 1;
      }
    }
  }
  for (int row = 0; row < ini_row; row++)
  {
    for (int col = 0; col < ini_col; col++)
    {
      if (store[row][col] && !visited[row][col])
      {
        count++;
      }
    }
  }
  return count;
}

int main()
{
  std::vector<std::vector<int>> store{ { 1, 0, 0, 0 }, { 1, 0, 1, 0 }, { 1, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 1, 0, 0 } };
  std::cout << Enclaves(store) << "\n";
  return 0;
}
