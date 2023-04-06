#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Array {
public:
  template <class T> static void input(vector<T> &A, int n) {
    for (int i = 0; i < n; i++) {
      scanf("%d ", &A[i]);
    }
  }

  template <class T> static void print(vector<T> &A) {
    for (int i = 0; i < A.size(); i++) {
      cout << A[i] << " ";
    }
    cout << endl;
  }
};

// } Driver Code Ends
class Solution {
  // Not the best possible solution as it uses a space complexity of O(2N). But
  // possible the simplest one
public:
  int equalSum(int N, vector<int> &A) {
    // Calculate the sum to the point before the current point and store it in
    // l_ans and r_ans
    int l_ans = 0, r_ans = 0;
    // Store the sums in those point in arrays so that we can compare it
    // afterwards (already adjust for the one based indexing)
    vector<int> l_prefix(N + 1, 0), r_prefix(N + 1, 0);
    // calculate the sums by going through the array
    for (int i = 0; i < N; i++) {
      l_ans += A[i];
      r_ans += A[N - 1 - i];
      l_prefix[i + 1] = l_ans;
      r_prefix[N - i] = r_ans;
    }
    // Calculate the index at which the sum of left and right side are the same
    for (int i = 1; i < N + 1; i++) {
      if (l_prefix[i] == r_prefix[i]) {
        return i;
      }
    }
    // else return -1 if no such index exist
    return -1;
  }
};

//{ Driver Code Starts.

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  Solution obj;
  int res = obj.equalSum(N, A);

  cout << res << endl;
}

// } Driver Code Ends
