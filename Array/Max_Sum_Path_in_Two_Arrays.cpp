#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int max_path_sum(int A[], int B[], int l1, int l2) {
    int sum1 = 0, sum2 = 0, i = 0, j = 0;
    while (i < l1 && j < l2) {
      if (A[i] < B[j]) {
        sum1 += A[i];
        i++;
      } else if (A[i] > B[j]) {
        sum2 += B[j];
        j++;
      } else {
        sum1 += A[i];
        sum2 += A[i];
        sum1 = sum2 = max(sum1, sum2);
        while (i < l1 && j < l2 && A[i] == B[j]) {
          i++;
          j++;
        }
      }
    }
    while (i < l1) {
      sum1 += A[i];
      i++;
    }
    while (j < l2) {
      sum2 += B[j];
      j++;
    }
    return max(sum1, sum2);
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  fflush(stdin);
  int a[N], b[M];
  for (int i = 0; i < N; i++)
    cin >> a[i];
  for (int i = 0; i < M; i++)
    cin >> b[i];
  Solution obj;
  int result = obj.max_path_sum(a, b, N, M);
  cout << result << endl;
}
