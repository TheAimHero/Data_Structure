#include <bits/stdc++.h>
using namespace std;
/*
20
0 7 7 9 0 0 5 1 0 6 6 5 8 9 9 9 1 2 4 3
*/
class Solution {
public:
  vector<long long> smallerSum(int n, vector<int> &arr) {
    map<int, long long> m;
    vector<long long> ans{arr.begin(), arr.end()};
    sort(arr.begin(), arr.end());
    m[arr[0]] = 0;
    int sum = 0;
    for (int i = 1; i < n; i++) {
      sum += arr[i - 1];
      // Update the map only if the element is unique i.e. being calculated for
      // the first time
      if (m.find(arr[i]) == m.end()) {
        m[arr[i]] = sum;
      }
    }
    for (int i = 0; i < n; i++) {
      ans[i] = m[ans[i]];
    }
    return ans;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Solution ob;
  vector<long long> ans = ob.smallerSum(n, arr);
  for (int i = 0; i < n; i++) {
    if (i != n - 1) {
      cout << ans[i] << " ";
    } else {
      cout << ans[i] << endl;
    }
  }
  return 0;
}
