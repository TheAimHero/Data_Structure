#include <bits/stdc++.h>
using namespace std;
/*
3 8
2 5
2 6 4 3 4 4 5 7
3 1 4 4 8 9 3 2
7 4 2 3 7 8 5 2
*/

/*
9 10
4 5
0 0 0 2 0 2 0 2 0 0
0 0 2 0 2 0 2 0 2 0
0 2 0 0 1 2 0 0 0 2
0 0 2 0 2 0 2 0 2 0
0 2 0 2 0 0 0 2 0 2
0 0 2 0 2 0 2 0 2 0
0 2 0 0 0 2 0 0 0 2
0 0 2 0 2 0 2 0 2 0
0 0 0 2 0 2 0 2 0 0
*/

class Solution {
public:
  // Check if the given indexes are out of bound or not
  bool is_valid(int max_row, int max_col, int row, int col) {
    if (row >= 0 && col >= 0 && row < max_row && col < max_col) {
      return true;
    }
    return false;
  }

  int knightInGeekland(int start_x, int start_y, vector<vector<int>> &arr) {
    // The max row and column of the given matrix
    int max_row = arr.size(), max_col = arr[0].size();
    // Store the indices that are already visited by the knight
    vector<vector<int>> visited(max_row, vector<int>(max_col, 0));
    // Queue for performing bfs
    queue<pair<int, int>> q;
    // Push the starting position of the knight in the queue and mark it as
    // visited
    q.push({start_x, start_y});
    visited[start_x][start_y] = 1;
    // The knight can travel in the following ways (like the knight of chess)
    vector<int> arr_row = {-2, -1, 1, 2, 2, 1, -1, -2};
    vector<int> arr_col = {1, 2, 2, 1, -1, -2, -2, -1};
    // Store the number of coins that the knight has collected at every step
    vector<int> coins;

    // perform bfs
    while (!q.empty()) {
      int q_size = q.size();
      int current_lvl_pts = 0;
      // do some action for the whole level
      for (int i = q.size() - 1; i >= 0; i--) {
        int row = q.front().first, col = q.front().second;
        current_lvl_pts += arr[row][col];
        q.pop();
        // run this for all the eight position the knight can reach
        for (int j = 0; j < 8; j++) {
          int n_row = row + arr_row[j], n_col = col + arr_col[j];
          // go to those position if they are in bounds and not already visited
          if (is_valid(max_row, max_col, n_row, n_col) &&
              !visited[n_row][n_col]) {
            q.push({n_row, n_col});
            visited[n_row][n_col] = 1;
          }
        }
      }
      coins.push_back(current_lvl_pts);
    }
    for (int i = coins.size() - 1; i >= 0; i--) {
      int index = i + coins[i];
      if (index < coins.size()) {
        coins[i] += coins[index];
      }
    }
    int max_num = coins[0], max_index = 0;

    for (int i = 0; i < coins.size(); i++) {
      if (max_num < coins[i]) {
        max_num = coins[i];
        max_index = i;
      }
    }
    return max_index;
  }
};

int main() {
  int n, m, start_x, start_y;
  cin >> n >> m >> start_x >> start_y;
  vector<vector<int>> arr(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  Solution ob;
  cout << ob.knightInGeekland(start_x, start_y, arr) << endl;
}
