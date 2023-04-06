#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minDist(int a[], int n, int x, int y) {
    int min_dist = INT_MAX;
    int right = -1, left = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == x)
        right = i;
      if (a[i] == y)
        left = i;
      if (right != -1 && left != -1) {
        min_dist = min(min_dist, abs(right - left));
      }
    }
    return min_dist == (right == -1 || left == -1) ? -1 : min_dist;
  }
};

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int x, y;
  cin >> x >> y;
  Solution obj;
  cout << obj.minDist(a, n, x, y) << endl;
  return 0;
}
