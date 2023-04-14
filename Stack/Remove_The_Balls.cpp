#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int finLength(int N, vector<int> color, vector<int> radius) {
    stack<pair<int, int>> s;
    for (int i = 0; i < N; i++) {
      if (!s.empty() && s.top().first == color[i] &&
          s.top().second == radius[i]) {
        s.pop();
      } else {
        s.push({color[i], radius[i]});
      }
    }
    return s.size();
  }
};

int main() {
  Solution sol;
  int n;
  cin >> n;
  vector<int> color(n), radius(n);
  for (int i = 0; i < n; i++)
    cin >> color[i];
  for (int i = 0; i < n; i++)
    cin >> radius[i];
  int ans = sol.finLength(n, color, radius);
  cout << ans << "\n";
  return 0;
}
