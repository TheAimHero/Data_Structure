#include <bits/stdc++.h>
using namespace std;

int max_sum(int A[], int N);

int main() {
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  cout << max_sum(A, N) << endl;
}

int max_sum(int a[], int N) {
  int ans = INT_MIN, a_sum = 0, prev_sum = 0;
  // calculate the total sum of a[i]  and the sum of a[i]*i
  for (int i = 0; i < N; i++) {
    a_sum += a[i];
    prev_sum += a[i] * i;
  }
  for (int i = 0; i < N; i++) {
    // to keep track of the max possible sum of configs
    ans = max(ans, prev_sum);
    // the current sum will be the previous sum + the sum of the array minus the
    // current element that is supposed to be rotated multiplied by the length
    // of the array
    // let suppose the array {8,3,1,2}
    // for S0 --> 8(0)+3(1)+1(2)+2(3) = 11
    // for S1 --> 2(0)+8(1)+3(2)+1(3) = 17 --> S0 + (sum of a[i]) - (N*2)
    // for S1 --> 1(0)+2(1)+8(2)+3(3) = 27 --> S1 + (sum of a[i]) - (N*1)
    // The same goes for other sums as well and we just have to find the max
    prev_sum = prev_sum + a_sum - (N * a[N - 1 - i]);
  }
  return ans;
}
