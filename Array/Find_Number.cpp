#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  long long findNumber(long long N) {
    long long v[] = {9, 1, 3, 5, 7};
    vector<int> vec;
    long ans = 0;
    while (N > 0) {
      vec.push_back(N % 5);
      if (N % 5 == 0) {
        N--;
      }
      N /= 5;
    }
    reverse(vec.begin(), vec.end());
    for (auto i : vec) {
      cout << i << " ";
    }
    long long matter = 0;
    for (auto i : vec) {
      matter = matter * 10 + v[i];
    }

    return matter;
  }
};

int main() {
  Solution s;
  long long n;
  cin >> n;
  cout << s.findNumber(n) << "\n";
  return 0;
}
