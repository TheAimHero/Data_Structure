#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> removeDuplicate(vector<int> &arr, int n) {
    unordered_map<int, int> hash;
    vector<int> ans;
    for (auto i : arr) {
      if (hash[i] == 1) {
        continue;
      } else {
        hash[i] = 1;
        ans.push_back(i);
      }
    }
    return ans;
  }
};

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  Solution obj;
  vector<int> result = obj.removeDuplicate(A, N);
  for (int i = 0; i < result.size(); i++)
    cout << result[i] << " ";
  cout << endl;
}

// } Driver Code Ends
