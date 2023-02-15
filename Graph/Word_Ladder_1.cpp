#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
  public:
  int wordLadderLength(string startWord, string targetWord, vector<string>& wordList)
  {
    unordered_set<string> word_set(wordList.begin(), wordList.end());
    int word_length = startWord.size();
    queue<pair<string, int>> q;
    q.push({ startWord, 1 });
    word_set.erase(startWord);
    while (!q.empty())
    {
      string current = q.front().first;
      int level = q.front().second;
      if (current == targetWord)
      {
        return level;
      }
      q.pop();
      for (int i = 0; i < word_length; i++)
      {
        char original = current[i];
        for (char j = 'a'; j <= 'z'; j++)
        {
          current[i] = j;
          if (word_set.find(current) != word_set.end())
          {
            word_set.erase(current);
            q.push({ current, level + 1 });
          }
        }
        current[i] = original;
      }
    }
    return 0;
  }
};

int main()
{
  int n;
  cin >> n;
  vector<string> wordList(n);
  for (int i = 0; i < n; i++) cin >> wordList[i];
  string startWord, targetWord;
  cin >> startWord >> targetWord;
  Solution obj;
  int ans = obj.wordLadderLength(startWord, targetWord, wordList);
  cout << ans << "\n";
  return 0;
}
