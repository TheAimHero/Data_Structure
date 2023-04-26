#include <bits/stdc++.h>
using namespace std;
/*
21
99
0 0 1 1 0 0 0 1 1 0 0 0 0 0 0 0 1 1 1 0 0 0 1 1 1 1 1 0 0 0 0 0 0 1 1 0 0 0 0 0
0 0 1 1 1 1 1 0 0 0 0 1 1 1 0 0 0 0 0 0 1 1 1 0 0 0 1 1 1 1 1 0 0 0 1 1 1 1 1 0
0 0 0 1 1 1 0 0 0 0 0 0 1 1 1 0 0 0 0
*/
class Solution {
public:
  bool is_possible_to_get_seats(int n, int m, vector<int> &s) {
    for (int i = 0; i < m; i++) {
      if (s[i] != 1 && s[max(i - 1, 0)] == 0 && s[min(m - 1, i + 1)] == 0 &&
          n != 0) {
        s[i] = 1;
        n--;
      }
    }
    return !n ? true : false;
  }
};

int main() {

  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<int> seats(m);
  for (int i = 0; i < m; i++) {
    cin >> seats[i];
  }
  Solution obj;
  if (obj.is_possible_to_get_seats(n, m, seats)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
