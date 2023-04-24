#include <bits/stdc++.h>
using namespace std;
/*
5
4 8 3 5 3

5
4 8 3 1 3
*/
class Solution {
public:
  vector<int> nearestSmallerTower(vector<int> &arr) {
    int n = arr.size();
    stack<int> left, right;
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++) {
      while (!left.empty() && arr[left.top()] >= arr[i]) {
        left.pop();
      }

      if (!left.empty()) {
        ans[i] = left.top();
      }

      left.push(i);
    }

    for (int i = n - 1; i >= 0; i--) {
      while (!right.empty() && arr[right.top()] >= arr[i]) {
        right.pop();
      }

      if (!right.empty()) {

        if (ans[i] != -1) {
          if (abs(ans[i] - i) == abs(right.top() - i)) {
            if (arr[ans[i]] > arr[right.top()])
              ans[i] = right.top();
          } else if (abs(ans[i] - i) > abs(right.top() - i))
            ans[i] = right.top();
        } else
          ans[i] = right.top();
      }

      right.push(i);
    }

    return ans;
  }
};

int main() {

  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  Solution ob;
  vector<int> ans = ob.nearestSmallerTower(v);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}
