#include <bits/stdc++.h>
using namespace std;
/*
3
*/
class Solution {
public:
  long long int minOperations(int N) {
    long long int ans = 0;
    int target = (1 + (2 * (N - 1) + 1)) / 2;
    for (int i = N / 2; i >= 0; i--) {
      ans += ((2 * i) + 1 - target);
    }
    return abs(ans);
  }
};

int main() {
  int n;
  cin >> n;
  Solution ob;
  cout << ob.minOperations(n) << endl;
  return 0;
}
