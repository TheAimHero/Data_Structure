#include <bits/stdc++.h>
using namespace std;

int minSteps(string str) {
  int ans = 0, size = str.size();
  // we have to find the number of points where the previous letter is different
  // from the current letter. This will give us the number of letters that has
  // to be removed to make the string a contiguous string of single letter.
  for (int i = 1; i < size; i++) {
    if (str[i] != str[i - 1]) {
      ans++;
    }
  }
  // When we remove a single letter we reduce the difference points by two.
  if (ans % 2) {
    // for odd number of difference points
    return (ans) / 2 + 2;
  }
  // For even number of difference points
  return (ans / 2) + 1;
}

int main() {
  string str;
  cin >> str;
  cout << minSteps(str) << endl;
}
