#include <bits/stdc++.h>
using namespace std;
/*
3 3
1 2 2
3 8 2
5 3 5
*/
class Solution
{
  public:
  int MinimumEffort(vector<vector<int>>& heights)
  {
    int grid_row = heights.size(), grid_col = heights[0].size(), arr_row[]{ -1, 0, 1, 0 }, arr_col[]{ 0, 1, 0, -1 };
    vector<vector<int>> effort(grid_row, vector<int>(grid_col, 1e9));
    set<pair<int, pair<int, int>>> s;
    vector<vector<pair<int, int>>> parent(grid_row, vector<pair<int, int>>(grid_col, { 1e9, 1e9 }));
    effort[0][0] = 0;
    s.insert({ 0, { 0, 0 } });
    parent[0][0] = { 0, 0 };  // the starting node
    while (!s.empty())
    {
      pair<int, pair<int, int>> current = *s.begin();
      int current_row = current.second.first, current_col = current.second.second, current_distance = current.first;
      int current_height = heights[current_row][current_col];
      s.erase(s.begin());
      if (current_row == grid_row - 1 && current_col == grid_col - 1)  // if has reached the target with the MinimumEffort that is the distance taken  from the set structure return the distance
      {
        return current_distance;
      }
      for (int i = 0; i < 4; i++)  // Traverse in all the four directions
      {
        int n_row = current_row + arr_row[i], n_col = current_col + arr_col[i];
        if (n_row >= 0 && n_row < grid_row && n_col >= 0 && n_col < grid_col)  // check if the indexes are within bounds
        {
          int n_height = heights[n_row][n_col];  // find the height of the current index from the given heights 2-d array
          int new_effort = max(current_distance, abs(n_height - current_height));  // the new effort will be the max between effort of the parent and the difference between the current node and the parent
          if (effort[n_row][n_col] > new_effort)//if the current effort is greater than the new effort then evaluate the paths forward with this new effort 
          {
            s.erase({ effort[n_row][n_col], { n_row, n_col } });//remove the old effort data if any
            effort[n_row][n_col] = new_effort;//update the effort
            s.insert({ new_effort, { n_row, n_col } });//push the new effort in the set
          }
        }
      }
    }
    return 0;
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> heights;

  for (int i = 0; i < n; ++i)
  {
    vector<int> temp;
    for (int j = 0; j < m; ++j)
    {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    heights.push_back(temp);
  }

  Solution obj;
  cout << obj.MinimumEffort(heights) << "\n";

  return 0;
}
