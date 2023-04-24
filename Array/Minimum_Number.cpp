#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumNumber(int n, vector<int> &arr) {
    int gc = arr[0];
    int min_ele = *min_element(arr.begin(), arr.end());
    for (int i = 1; i < n; i++)
      gc = __gcd(gc, arr[i]);
    if (gc == min_ele)
      return min_ele;
    return 1;
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
  cout << ob.minimumNumber(n, arr) << endl;
}
