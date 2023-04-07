#include <algorithm>
#include <bits/stdc++.h>
#include <future>
using namespace std;

class Solution {
public:
  // Check if a string is a palindrome or not
  bool check_palindrome(string str) {
    int i = 0, j = str.length() - 1;
    while (i < j) {
      if (str[i] != str[j]) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }

  int addMinChar(string str) {
    // if the string is already a palindrome return 0 as no need to add any more
    // characters
    if (check_palindrome(str))
      return 0;

    int len = str.length() - 1;
    // Traverse the stirng in reverse
    for (int i = len; i >= 0; i--) {
      // See if the sub-string from 0-(current_position-1) i.e. len-i-1 is
      // palindromic or not if it is we need to return the length of the string
      // except that string because if insert that stirng in the beginning in
      // reverse order then the given string will also become palindromic
      // BABCB--> |BAB|CB| --> |BC|BABCB --> String now palindromic
      if (check_palindrome(str.substr(0, i))) {
        return len - i + 1;
      }
    }
    // If any of the substring of the original substring is not palindromic then
    // we have to add the whole string except the first letter in reverse order
    // to make the string palindromic
    // ABCD --> |ABCD| --> |BCD|ABCD --> String now palindromic
    return len - 1;
  }
};

int main() {
  string str;
  cin >> str;
  Solution ob;
  cout << ob.addMinChar(str) << endl;
  return 0;
}
