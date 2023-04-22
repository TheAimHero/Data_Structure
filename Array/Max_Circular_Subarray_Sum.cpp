#include <bits/stdc++.h>
using namespace std;
/*
7
8 -8 9 -9 10 -11 12

9
-3 -18 -22 -21 -17 16 -14 28 -22
*/
class Solution {
public:
  int circularSubarraySum(int arr[], int n) {
    int min_sum = 1e9, max1 = 1e9;
    for (int i = 0; i < n; i++) {
      max1 = min(arr[i], arr[i] + max1);
      min_sum = min(min_sum, max1);
    }
    int max_sum = -1e9;
    max1 = -1e9;
    for (int i = 0; i < n; i++) {
      max1 = max(arr[i], arr[i] + max1);
      max_sum = max(max_sum, max1);
    }
    if (max_sum < 0)
      return max_sum;

    int total_sum = 0;
    for (int i = 0; i < n; i++) {
      total_sum += arr[i];
    }
    cout << total_sum << " " << min_sum << " " << max_sum << "\n";
    return max(max_sum, total_sum - min_sum);
  }
};

int main() {
  int num;
  cin >> num;
  int arr[num];
  for (int i = 0; i < num; i++)
    cin >> arr[i];
  Solution ob;
  cout << ob.circularSubarraySum(arr, num) << endl;
  return 0;
}
