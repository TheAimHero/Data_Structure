#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <utility>
#include <vector>
/*
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
*/
using namespace std;

class Solution
{
  public:
  vector<pair<int, int>> short_path(vector<pair<int, int>> ip[], vector<pair<int, int>>& distance, set<pair<int, int>>& s)
  {
    while (!s.empty())
    {
      pair<int, int> current = *s.begin();
      int current_node = current.first, current_distance = current.second;
      s.erase(s.begin());
      for (auto adj_nodes : ip[current_node])
      {
        int current_adj_node = adj_nodes.first, adj_node_weight = adj_nodes.second;
        if (distance[current_adj_node].first > current_distance + adj_node_weight)
        {
          s.erase({ current_adj_node, distance[current_adj_node].first });
          distance[current_adj_node].first = current_distance + adj_node_weight;
          distance[current_adj_node].second = current_node;
          s.insert({ current_adj_node, distance[current_adj_node].first });
        }
      }
    }
    return distance;
  }

  vector<int> shortestPath(int n, int m, vector<vector<int>>& edges)
  {
    vector<pair<int, int>> distance(n + 1, { 1e9, 0 });
    distance[1] = { 0, 1 };
    vector<pair<int, int>> ip[n + 1];
    set<pair<int, int>> s;
    s.insert({ 1, 0 });
    for (auto i : edges)
    {
      int node1 = i[0], node2 = i[1], wt = i[2];
      ip[node1].push_back({ node2, wt });
      ip[node2].push_back({ node1, wt });
    }
    vector<int> ans;
    int i = distance.size() - 1;
    short_path(ip, distance, s);
    ans.push_back(distance.size() - 1);
    while (distance[i].first != 0)
    {
      if (distance[i].first == 1e9)
      {
        return { -1 };
      }
      ans.push_back(distance[i].second);
      i = distance[i].second;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges;
  for (int i = 0; i < m; ++i)
  {
    vector<int> temp;
    for (int j = 0; j < 3; ++j)
    {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    edges.push_back(temp);
  }

  Solution obj;
  vector<int> res = obj.shortestPath(n, m, edges);
  for (auto x : res)
  {
    cout << x << " ";
  }
  cout << "\n";
}

// } Driver Code Ends
