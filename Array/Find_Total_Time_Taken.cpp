#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int totalTime(int n, vector<int> &arr, vector<int> &time) {
    vector<int> hash(n + 1, 0);
    int total_time = 0;
    hash[arr[0]] = 1;
    for (int i = 1; i < n; i++) {
      if (hash[arr[i]] >= 1) {
        total_time += time[arr[i] - 1];
      } else {
        total_time++;
      }
      hash[arr[i]]++;
      cout << total_time << " ";
    }
    return total_time;
  }
};

int main() {
  int n;
  scanf("%d", &n);
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<int> time(n);
  for (int i = 0; i < n; i++) {
    cin >> time[i];
  }
  Solution obj;
  int res = obj.totalTime(n, arr, time);
  cout << res << endl;
}
