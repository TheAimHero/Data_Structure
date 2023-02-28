//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <map>
using namespace std;

/*
3
Ceiran 1
Fyfemail.com
Conar 3
Bluemail.com Dustinmail.com Danialmail.com
Aliekber 4
Dilrajmail.com Butalimail.com Ehsanmail.com Aleksandrmail.com
*/

// } Driver Code Ends

class DisjointSet
{
  public:
  vector<int> size, parent;

  DisjointSet(int n)
  {
    size.resize(n + 1);
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
      size[i] = 1;
    }
  }
  int findUPar(int node)
  {
    if (parent[node] == node)
      return node;
    return parent[node] = findUPar(parent[node]);
  }
  void unionBySize(int u, int v)
  {
    int upu = findUPar(u);
    int upv = findUPar(v);
    if (upu == upv)
      return;
    if (size[upu] < size[upv])
    {
      parent[upu] = upv;
      size[upv] += size[upu];
    }
    else
    {
      parent[upv] = upu;
      size[upu] += size[upv];
    }
  }
};

class Solution
{
  public:
  vector<vector<string>> mergeDetails(vector<vector<string>>& details)
  {
    int size = details.size();
    DisjointSet ds(size);
    map<string, int> map_mail_node;
    for (int i = 0; i < size; i++)
    {
      for (int j = 1; j < details[i].size(); j++)
      {
        string mail = details[i][j];
        if (map_mail_node.find(mail) == map_mail_node.end())
          map_mail_node[mail] = i;
        else
        {
          ds.unionBySize(map_mail_node[mail], i);
        }
      }
    }
    vector<string> merged_mail[size];
    for (auto it : map_mail_node)
    {
      int node = ds.findUPar(it.second);
      string mail = it.first;
      merged_mail[node].push_back(mail);
    }
    vector<vector<string>> res;
    for (int i = 0; i < size; i++)
    {
      if (merged_mail[i].size() == 0)
        continue;
      sort(merged_mail[i].begin(), merged_mail[i].end());
      vector<string> temp;
      temp.push_back(details[i][0]);
      for (auto it : merged_mail[i])
      {
        temp.push_back(it);
      }
      res.push_back(temp);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

//{ Driver Code Starts.
int main()
{
  int n;
  cin >> n;
  vector<vector<string>> adj;

  for (int i = 0; i < n; i++)
  {
    vector<string> temp;
    string s;
    cin >> s;
    temp.push_back(s);
    int x;
    cin >> x;

    for (int j = 0; j < x; j++)
    {
      string s1;
      cin >> s1;
      temp.push_back(s1);
    }
    adj.push_back(temp);
  }

  Solution obj;
  vector<vector<string>> res = obj.mergeDetails(adj);
  sort(
      res.begin(),
      res.end(),
      [](const vector<string>& a, const vector<string>& b)
      { return a[0] <= b[0]; });
  cout << "[";
  for (int i = 0; i < res.size(); ++i)
  {
    cout << "[";
    for (int j = 0; j < res[i].size(); j++)
    {
      if (j != res[i].size() - 1)
        cout << res[i][j] << ","
             << " ";
      else
        cout << res[i][j];
    }
    if (i != res.size() - 1)
      cout << "], ";
    else
      cout << "]";
  }
  cout << "]"
       << "\n";
}

// } Driver Code Ends
