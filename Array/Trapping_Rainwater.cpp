#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <iterator>
#include <vector>

using namespace std;
/*
7
8 8 2 4 5 5 1
*/
class Solution {
public:
  long long trappingWater(int arr[], int n) {
    vector<int> rmax(n), lmax(n);
    rmax[n - 1] = arr[n - 1];
    lmax[0] = arr[0];
    for (int i = 1; i < n; i++) {
      rmax[n - i - 1] = max(rmax[n - i], arr[n - i - 1]);
      lmax[i] = max(lmax[i - 1], arr[i]);
    }
    for (int i = 0; i < n; i++) {
      cout << rmax[i] << " " << lmax[i] << "\n";
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += max(0, min(lmax[i], rmax[i]) - arr[i]);
    }
    return sum;
  }
};

int main() {

  int n;

  // size of array
  cin >> n;

  int a[n];

  // adding elements to the array
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  Solution obj;
  // calling trappingWater() function
  cout << obj.trappingWater(a, n) << endl;

  return 0;
}
// } Driver Code Ends
