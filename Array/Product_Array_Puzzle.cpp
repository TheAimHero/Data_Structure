#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<long long int> productExceptSelf(vector<long long int> &nums, int n) {
    vector<long long int> prefix(n, 1);
    for (int i = n - 2; i >= 0; i--) {
      prefix[i] = prefix[i + 1] * nums[i + 1];
    }
    // for (auto i : prefix) {
    //   cout << i << " ";
    // }
    // cout << "\n";
    long long int curr_product = 1;
    for (int i = 0; i < n; i++) {
      prefix[i] = prefix[i] * curr_product;
      curr_product *= nums[i];
    }
    return prefix;
  }
};

int main() {
  int n; // size of the array
  cin >> n;
  vector<long long int> arr(n), vec(n);

  for (int i = 0; i < n; i++) // input the array
  {
    cin >> arr[i];
  }
  Solution obj;
  vec = obj.productExceptSelf(arr, n); // function call

  for (int i = 0; i < n; i++) // print the output
  {
    cout << vec[i] << " ";
  }
  cout << endl;
  return 0;
}
