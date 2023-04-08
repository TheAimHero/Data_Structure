#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  // the following method is only valid when the value of elements in the array
  // is less than the size of array ( for all a[i]<(n-1) ). If that is not the
  // case then we can use a map or hash
  vector<int> duplicates(int arr[], int n) {
    for (int i = 0; i < n; i++) {
      int index = arr[i] % n;
      arr[index] += n;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (arr[i] % n >= 2) {
        ans.push_back(arr[i]);
      }
    }
    if (ans.size()) {
      return ans;
    }
    return {-1};
  }
};

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  Solution obj;
  vector<int> ans = obj.duplicates(a, n);
  for (int i : ans)
    cout << i << ' ';
  cout << endl;
  return 0;
}
