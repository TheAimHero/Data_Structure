#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // We have to make groups such that there is no consecutive character 3 times
  // in a row that means we can make groups of two for the largest number
  int solve(int a, int b, int c) {
    // suppose a=11, b=5, c=2
    // then we can form groups of 2 with the number which is the max amongst the
    // three i.e. a in our case
    // then the groups become
    // aa|aa|aa|aa|aa|a
    // then we need to have at least enough characters to replace the |
    // that means if b+c (remaining character length) is greater than or equal
    // to the number of | then the max length of the stirng can be a+b+c
    // else it will be -1
    vector<int> arr{a, b, c};
    sort(arr.begin(), arr.end());
    int max_length = (arr[2] % 2) + (arr[2] / 2);
    if (arr[1] + arr[0] >= max_length - 1) {
      return a + b + c;
    }
    return -1;
  }
};

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  Solution ob;
  int ans = ob.solve(a, b, c);

  cout << ans << "\n";
  return 0;
}
