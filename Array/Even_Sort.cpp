#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> lexicographicallyLargest(vector<int> &a, int n) {
    int s = a.size(), i = 0;
    // we have to check for the whole array and i jumps to the place of j
    // therefore we cannot use a for loop in this case and have to use a while
    // loop
    while (i < s) {
      int j;
      // find the range until which the sum of adjacent elements is even
      // (constraint)
      for (j = i + 1; j < s && (a[j - 1] % 2 == a[j] % 2); j++) {
      }
      // sort the elements in that range and then reverse those elements
      sort(a.begin() + i, a.begin() + j);
      reverse(a.begin() + i, a.begin() + j);
      // after that search for the next range in which the sorting constraint is
      // valid
      i = j;
    }
    return a;
  }
};

//{ Driver Code Starts.

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &j : a)
    cin >> j;
  Solution s;
  vector<int> b = s.lexicographicallyLargest(a, n);
  for (auto i : b)
    cout << i << " ";
  cout << endl;
  return 0;
}
// } Driver Code Ends
