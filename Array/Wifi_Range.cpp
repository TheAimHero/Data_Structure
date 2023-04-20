#include <bits/stdc++.h>
#include <vector>
using namespace std;
/*
7 2
0111000
*/
class Solution {
public:
  bool wifiRange(int n, string s, int x) {
    vector<int> vec(n + 1);
    int index;


    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        vec[i] = 1;
        index = max(0, i - x);
        vec[index]++;
        index = min(n - 1, i + x);
        vec[index + 1]--;
      }
    }


    for (int i = 1; i < n; i++) {
      vec[i] += vec[i - 1];
    }


    for (auto i : vec) {
      if (i <= 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  int N, X;
  string S;
  cin >> N >> X >> S;
  Solution obj;
  cout << obj.wifiRange(N, S, X) << "\n";
  return 0;
}
