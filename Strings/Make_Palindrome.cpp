#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool makePalindrome(int n, vector<string> &arr) {
    map<string, int> m;
    for (auto i : arr) {
      string rev = i;
      reverse(i.begin(), i.end());
      if (m.find(rev) != m.end()) {
        m[i]--;
        if (m[i] == 0) {
          m.erase(i);
        }
      } else {
        m[i]++;
      }
    }
    if (m.size() == 0) {
      return true;

    } else if (m.size() == 1) {
      string cur = m.begin()->first;
      string rev = cur;
      reverse(rev.begin(), rev.end());
      return rev == cur;
    }
    return false;
  }
};

int main() {
  int n;
  cin >> n;
  vector<string> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Solution ob;
  if (ob.makePalindrome(n, arr))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
