#include <bits/stdc++.h>
#include <fstream>
using namespace std;
/*
5
4 0 2 1 3
*/
class Solution {
public:
  void arrange(long long arr[], int n) {
    for (int i = 0; i < n; i++) {
      arr[i] *= n;
      // arr[i] += arr[arr[i]] / n;
    }
    for (int i = 0; i < n; i++) {
      arr[i] += arr[arr[i]/n]/n;
    }
    for (int i=0 ; i< n ; i++ ) {
    arr[i]%=n;
    }
  }
};

int main() {
  int n;
  cin >> n;
  long long A[n];

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  Solution ob;
  ob.arrange(A, n);

  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}
