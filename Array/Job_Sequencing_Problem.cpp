#include <bits/stdc++.h>
using namespace std;

/*
6
1 6 30 2 6 50 3 6 20 4 1 10 5 5 50 6 4 50
6 210
*/

struct Job {
  int id;     // Job Id
  int dead;   // Deadline of job
  int profit; // Profit if job is over before or on deadline
};

bool compProfit(Job e1, Job e2) { return e1.profit > e2.profit; }
bool compDeadlien(Job j1, Job j2) { return j1.dead < j2.dead; }

class Solution {
public:
  vector<int> JobScheduling(Job arr[], int n) {
    vector<int> arr_deadline(
        (max_element(arr, arr + n, compDeadlien)->dead) + 1, -1);
    sort(arr, arr + n, compProfit);
    int ans = 0, count = 0;
    for (int i = 0; i < n; i++) {
      Job current_job = arr[i];
      for (int j = current_job.dead; j > 0; j--) {
        if (arr_deadline[j] == -1) {
          ans += current_job.profit;
          count++;
          arr_deadline[j] = 1;
          break;
        }
      }
    }
    return {count, ans};
  }
};

int main() {
  int n;
  cin >> n;
  Job arr[n];
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    arr[i].id = x;
    arr[i].dead = y;
    arr[i].profit = z;
  }
  Solution ob;
  vector<int> ans = ob.JobScheduling(arr, n);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}
