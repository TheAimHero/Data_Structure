#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  // we cannot use the modulo operation directly because it will no be a time
  // effecient process
  int xmod11(string x) {
    // initially the remainder will be zero as the first digit will have no
    // remainder
    int rem = 0, current = 0;
    for (int i = 0; i < x.length(); i++) {
      // to find the current digits to be processed we will put the remainder in
      // ten's place and form the number to be processed
      current = rem * 10 + int(x[i] - '0');
      // now that we have the number to be processed we will modulo it by 11
      // which will give us the remainder which will be processed with the next
      // digit of the number
      rem = current % 11;
    }
    return rem;
  }
};

int main() {
  string x;
  cin >> x;
  Solution ob;
  int ans = ob.xmod11(x);
  cout << ans << endl;
  return 0;
}
