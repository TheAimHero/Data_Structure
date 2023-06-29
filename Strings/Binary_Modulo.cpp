#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int modulo(string s, int m) {
    int cur = 1, ans = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '1') { ans += cur; }
      ans %= m;
      cur *= 2;
      cur %= m;
    }
    return ans % m;
  }
};

int main() {
  string s;
  int m;
  cin >> s >> m;
  Solution a;
  cout << a.modulo(s, m) << endl;
  return 0;
}
