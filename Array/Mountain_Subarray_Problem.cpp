#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                              int q) {
    vector<bool> ans;
    for (auto i : queries) {
      int low = i.first, high = i.second;
      while (low < high && a[low] <= a[low+1]) {
        low++;
      }
      while (low < high && a[low] >= a[low+1]) {
        low++;
      }
      if (low < high) {
        ans.push_back(false);
      } else {
        ans.push_back(true);
      }
    }
    return ans;
  }
};

int main() {
  int n, i, q;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> q;
  vector<pair<int, int>> queries(q);
  for (i = 0; i < q; i++) {
    cin >> queries[i].first >> queries[i].second;
  }
  Solution obj;
  auto v = obj.processQueries(a, n, queries, q);
  for (bool u : v) {
    cout << (u ? "Yes\n" : "No\n");
  }
  return 0;
}
