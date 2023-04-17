#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
/*
9
34 8 10 3 2 80 30 33 1
*/
class Solution {
public:
  // Brute Force
  // int maxIndexDiff(int A[], int N) {
  //   int mx = -1e9;
  //   for (int i = N - 1; i >= 0; i--) {
  //     for (int j = 0; j < i; j++) {
  //       if (A[j] <= A[i]) {
  //         mx = max(mx, i - j);
  //         break;
  //       }
  //     }
  //   }
  //   return mx == -1e9 ? 0 : mx;
  // }
  int maxIndexDiff(int a[], int n) {
    int mx = -1e9;
    int lmin[n], rmax[n];
    lmin[0] = a[0];
    rmax[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++) {
      lmin[i] = min(lmin[i - 1], a[i]);
      rmax[n - i - 1] = max(rmax[n - i], a[n - i - 1]);
    }
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (lmin[i] <= rmax[j]) {
          mx = max(mx, j - i);
          j++;
        } else {
          i++;
        }
      }
    return mx;
    }
  };

  int main() {
    int num;
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++)
      cin >> arr[i];
    Solution ob;
    cout << ob.maxIndexDiff(arr, num) << endl;
    return 0;
  }
