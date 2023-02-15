#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
  public:
  vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList)
  {
    int word_length = beginWord.size();  // store the length of the beginWord
    unordered_set<string> word_set(wordList.begin(), wordList.end());  // use a unordered_set to keep track of the words which are used and words which are still remaining
    queue<vector<string>> q;  // for bfs
    vector<string> used_on_level;  // keep the list of words to be deleted from word_set after entering next level
    vector<vector<string>> ans;
    used_on_level.push_back(beginWord);  // the first word i.e. the beginWord word is used on level one
    q.push({ beginWord });  // queue initialisation
    int level{};  // variable to keep track of the level we are on
    while (!q.empty())
    {
      vector<string> current = q.front();
      string current_word = *current.crbegin();
      if (current_word == endWord)  // we found the word we have to transform beginWord to
      {
        if (ans.size() == 0)  // is this the first sequence
        {
          ans.push_back(current);
        }
        else if (ans[0].size() == current.size())  // if it is not the first sequence then check if the sequence has the same level
        {
          ans.push_back(current);  // if yes only then push it to the ans array
        }
      }
      q.pop();
      if (current.size() > level)
      {
        level++;  // if the current vector contains more words than the level that means we have moved up a level
        for (auto i : used_on_level)
        {
          word_set.erase(i);  // delete all the words used on the previous level
        }
      }
      for (int i = 0; i < word_length; i++)
      {
        char original = current_word[i];
        for (char j = 'a'; j <= 'z'; j++)
        {
          current_word[i] = j;
          if (word_set.count(current_word) > 0)
          {
            current.push_back(current_word);  // if the word exist in the word_set then push it in current vector
            q.push(current);  // and push the current vector in the queue
            used_on_level.push_back(current_word);  // and show that the word has been used on the current level
            current.pop_back();  // we still have to check for other possibilites so we pop the current vector and continue with the other possibilites
          }
        }
        current_word[i] = original;  // we have to reset the word after checking for all possibilites at index i and check for the next index if available
      }
    }
    return ans;
  }
};

bool comp(vector<string> a, vector<string> b)
{
  string x = "", y = "";
  for (string i : a)
    x += i;
  for (string i : b)
    y += i;

  return x < y;
}

int main()
{
  int n;
  cin >> n;
  vector<string> wordList(n);
  for (int i = 0; i < n; i++) cin >> wordList[i];
  string startWord, targetWord;
  cin >> startWord >> targetWord;
  Solution obj;
  vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
  if (ans.size() == 0)
    cout << -1 << endl;
  else
  {
    sort(ans.begin(), ans.end(), comp);
    for (int i = 0; i < ans.size(); i++)
    {
      for (int j = 0; j < ans[i].size(); j++)
      {
        cout << ans[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
