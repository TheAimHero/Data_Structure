#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> Order(vector<vector<int>> ip, vector<int>& in_order, queue<int>& q, vector<int>& ans, int node)
{
  while (!q.empty())
  {
    int current = q.front();
    q.pop();
    ans.push_back(current);
    for (auto i : ip[current])
    {
      in_order[i]--;
      if (in_order[i] == 0)
      {
        q.push(i);
      }
    }
  }
  return ans;
}

int main()
{
  int node = 4;  // The number of English letters does the given strings can contain
  vector<string> dict{ "baaa", "abcd", "abca", "cab", "cad" };
  vector<vector<int>> ip(node);
  vector<int> in_degree(node);
  vector<int> ans_vector;
  queue<int> q;
  for (int i = 0; i < dict.size() - 1; i++)  // to compare the given strings and form pairs of letters which come one before the other
  {
    int min_length = min(dict[i].size(), dict[i + 1].size());  // to only compare the smaller word with the bigger word
    for (int j = 0; j < min_length; j++)
    {
      int w1 = dict[i][j], w2 = dict[i + 1][j];  // check the ith word with i-1 th word such that i reaches only the second last word
      if (w1 != w2)  // once the in-equality is found then push that word in the queue and increase the in_degree of the second word
      {
        ip[w1 - 'a'].push_back(w2 - 'a');  // then these pairs can be used to make a directed graph subtract 'a' form the characters to convert them into zero based indexes used for topological sort
        in_degree[w2 - 'a']++;  // also calculate the in_degree of the graph
        break;  // once a in-equality is found no further need to check for another pair we need to find only one pair
      }
    }
  }
  for (int i = 0; i < node; i++)  // to find the nodes which have in_degree as one and push them in the queue used for finding the topological sort
  {
    if (in_degree[i] == 0)
    {
      q.push(i);
    }
  }
  Order(ip, in_degree, q, ans_vector, node);  // find the topological sort
  for (auto i : ans_vector)
  {
    cout << char(i + 'a') << " ";  // convert the elements from ans_vector to char (int-->char)
  }
  cout << "\n";
  return 0;
}
