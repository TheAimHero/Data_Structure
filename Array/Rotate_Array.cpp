#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rotateArr(int arr[], int d, int n) {
    int rotate_steps = d % n;
    if (!n) {
      return;
    }
    reverse(arr, arr + rotate_steps);
    reverse(arr + rotate_steps, arr + n);
    reverse(arr, arr + n);
    return;
  }
};

int main() {
  int n, d;
  cin >> n >> d;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Solution ob;
  ob.rotateArr(arr, d, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
