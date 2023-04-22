#include <bits/stdc++.h>
#include <fstream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> SortBinaryArray(vector<int> a) {
    int cnt0 = 0, cnt1 = 0;
    for (auto i : a) {
      if (i == 0) {
        cnt0++;
      } else {
        cnt1++;
      }
    }
    vector<int> ans;
    for (int i = 0; i < cnt0; i++) {
      ans.push_back(0);
    }
    for (int i = 0; i < cnt1; i++) {
      ans.push_back(1);
    }
    return ans;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> binArray(n);
  for (int i = 0; i < n; i++)
    cin >> binArray[i];
  Solution ob;
  vector<int> result = ob.SortBinaryArray(binArray);
  for (int i = 0; i < n; i++)
    cout << result[i] << " ";

  cout << endl;
  return 0;
}
