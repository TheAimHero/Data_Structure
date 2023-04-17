#include <bits/stdc++.h>
using namespace std;

/*
3
11 22 2
19 4 90
*/
class Solution {
public:
  long long solve(int N, vector<int> &A, vector<int> &B) {
    vector<vector<int>> A_check(2), B_check(2);
    int sum = 0;

    for (int i = 0; i < N; i++) {
      sum += (A[i] - B[i]);
      A_check[A[i] % 2].push_back(A[i]);
      B_check[B[i] % 2].push_back(B[i]);
    }
    if (sum || A_check[1].size() != B_check[1].size()) {
      return -1;
    }

    for (int i = 0; i < 2; i++) {
      sort(A_check[i].begin(), A_check[i].end());
      sort(B_check[i].begin(), B_check[i].end());
    }

    long long ans = 0;

    for (int i = 0; i < A_check[0].size(); i++) {
      ans += abs(A_check[0][i] - B_check[0][i]);
    }
    for (int i = 0; i < A_check[1].size(); i++) {
      ans += abs(A_check[1][i] - B_check[1][i]);
    }

    return ans / 4;
  }
};

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  Solution obj;
  long long res = obj.solve(N, A, B);
  cout << res << endl;
}
