#include <bits/stdc++.h>
using namespace std;
/*
3 3
H H H
H W H
H H H

5 5
H N H H H
N N H H W
W H H H H
H H H H H
H H H H H

5 5
H N H H H
N N . H W
W H H H H
H H H H H
H H H H H

4 5
. . W . W
N W N N W
H . . H N
N N N . W
*/
class Solution {
public:
  vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c) {
    int max_row = c.size(), max_col = c[0].size();
    vector<int> arr_row{-1, 0, 1, 0}, arr_col{0, 1, 0, -1};
    vector<vector<int>> visited(max_row, vector<int>(max_col, 1e9));
    queue<pair<int, int>> q;
    for (int i = 0; i < max_row; i++) {
      for (int j = 0; j < max_col; j++) {
        char ch = c[i][j];
        if (ch == 'W') {
          q.push({i, j});
          visited[i][j] = 0;
        }
      }
    }

    while (!q.empty()) {
      int cur_row = q.front().first, cur_col = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int n_row = cur_row + arr_row[i], n_col = cur_col + arr_col[i];
        if (n_row >= 0 && n_col >= 0 && n_row < max_row && n_col < max_col) {
          if (c[n_row][n_col] != 'N' &&
              visited[cur_row][cur_col] + 1 < visited[n_row][n_col]) {
            visited[n_row][n_col] = 1 + visited[cur_row][cur_col];
            q.push({n_row, n_col});
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (c[i][j] == '.')
          visited[i][j] = 0;
        else if (visited[i][j] == 1e9 && c[i][j] == 'N')
          visited[i][j] = 0;
        else if (visited[i][j] == 1e9 && c[i][j] == 'H')
          visited[i][j] = -1;
        else
          visited[i][j] = 2 * visited[i][j];
      }
    }
    return visited;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> c(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c[i][j];
    }
  }
  Solution ob;
  vector<vector<int>> res = ob.chefAndWells(n, m, c);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}
