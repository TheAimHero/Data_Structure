#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

class Solution {
public:
  // Using a space of O(n)
  int FindMaxSum(int arr[], int n) {
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return arr[0];
    }
    int left[n];
    left[0] = arr[0];
    left[1] = arr[1];
    for (int i = 2; i < n; i++) {
      left[i] = max(left[i - 1], left[i - 2] + arr[i]);
    }
    return left[n - 1];
  }

  // Without using any auxiliary space
  int FindMaxSum1(int arr[], int n) {
    // If the size of the array is 1 then return the first element of the array
    // as the thief can only rob a single house
    if (n == 1) {
      return arr[0];
    }
    // The initial choice that the thief gets is to rob the first house or to
    // skip the first house and start  robbing from the second house
    int rob1 = arr[0], rob2 = 0;
    for (int i = 1; i < n - 1; i++) {
      // We have to find the max of the house right before the thief or two
      // houses after the thief as that will decide what houses the thief can
      // rob in the future. And for this purpose we will use a greedy approach
      int temp = max(rob1 + arr[i], rob2);
      rob1 = rob2;
      rob2 = temp;
    }
    return rob2;
  }
};

int main() {
  int n;
  cin >> n;
  int a[n];

  for (int i = 0; i < n; ++i)
    cin >> a[i];
  Solution ob;
  cout << ob.FindMaxSum(a, n) << endl;
  return 0;
}
