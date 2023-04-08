#include <bits/stdc++.h>
#include <vector>
using namespace std;
/*
7
-3 -1 -19 0 6 -13 12
*/
class Solution {
public:
  vector<int> makeBeautiful(vector<int> arr) {
    vector<int> ans;
    if (arr.size() <= 1) {
      return arr;
    }
    for (int i = 0; i < arr.size(); i++) {
      if (ans.size() != 0 && ((arr[i] >= 0 && ans[ans.size() - 1] < 0) ||
                              (arr[i] < 0 && ans[ans.size() - 1] >= 0))) {
        ans.pop_back();
      } else {
        ans.push_back(arr[i]);
      }
    }
    return ans;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  Solution obj;
  vector<int> res = obj.makeBeautiful(arr);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << "\n";
}
// } Driver Code Ends
