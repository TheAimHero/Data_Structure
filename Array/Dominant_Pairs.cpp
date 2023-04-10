#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <iterator>
using namespace std;

class Solution {
public:
  int dominantPairs(int n, vector<int> &arr) {
    sort(arr.begin(), arr.begin() + n / 2, greater<int>{});
    sort(arr.begin() + n / 2, arr.end(), greater<int>{});
    int pair = 0;
    int i = 0, j = n / 2, count = 0;
    while ((i < n / 2) && (j < n)) {
      if (arr[i] >= arr[j] * 5) {
        count += n - j;
        i++;
      } else {
        j++;
      }
    }
    return count;
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
  cout << ob.dominantPairs(n, arr) << endl;
}
