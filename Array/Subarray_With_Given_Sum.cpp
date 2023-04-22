#include <bits/stdc++.h>
using namespace std;
/*
42 468
135 101 170 125 79 159 163 65 106 146 82 28 162 92 196 143 28 37 192 5 103 154
93 183 22 117 119 96 48 127 172 139 70 113 68 100 36 95 104 12 123 134
*/
class Solution {
public:
  vector<int> subarraySum(vector<int> arr, int n, long long s) {
    int start = 0;
    for (int i = 0; i < n; i++) {
      s -= arr[i];
      while (s < 0) {
        s += arr[start];
        start++;
      }
      if (s == 0) {
        return {start + 1, i + 1};
      }
    }
    return {-1};
  }
};

int main() {
  int n;
  long long s;
  cin >> n >> s;
  vector<int> arr(n);
  // int arr[n];
  const int mx = 1e9;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Solution ob;
  vector<int> res;
  res = ob.subarraySum(arr, n, s);

  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;

  return 0;
}
