#include <bits/stdc++.h>
using namespace std;
/*
7 10
0 6 7
0 1 2
1 2 3
1 3 3
6 3 3
3 5 1
6 5 1
2 5 1
0 4 5
4 6 2
*/
class Solution
{
  public:
  int countPaths(int n, vector<vector<int>>& roads)
  {
    vector<pair<int, int>> ip[n];
    for (auto i : roads)  // Create graph out of the edges
    {
      int node1 = i[0], node2 = i[1], weight = i[2];
      ip[node1].push_back({ node2, weight });
      ip[node2].push_back({ node1, weight });
    }
    set<pair<int, int>> s;  // distance,node set to keep track of the state
    vector<int> distance(n, 1e8), ways(n, 0);
    s.insert({ 0, 0 });
    distance[0] = 0;  // distance to the source node will be 0
    ways[0] = 1;  // only one way to arrive at the source node
    int mod = (int)(1e9 + 7);
    while (!s.empty())
    {
      pair<int, int> current = *s.begin();
      int current_distance = current.first, current_node = current.second;  // the current state that is the current node and the distance it takes to reach that node
      s.erase(s.begin());  // remove the current state from the set as it is processed
      for (auto i : ip[current_node])  // iterate over all the adjacent nodes
      {
        int adj_node = i.first, adj_weight = i.second;
        if (distance[adj_node] > current_distance + adj_weight)  // if the adjacent node is reachable with a better distance only then
        {
          s.erase({ distance[adj_node], adj_node });  // remove the previous not so good state to reach the node from the set if it exist
          distance[adj_node] = current_distance + adj_weight;  // update the distance to this better distance
          ways[adj_node] = ways[current_node];  // the number of way to reach this node with the better distance will be the number of ways to reach its previous node
          s.insert({ distance[adj_node], adj_node });  // push this better state in the set for processing later
        }
        else if (distance[adj_node] == current_distance + adj_weight)  // if the node has been reached previously with the same distance then update the ways with the summation of the ways it has been reached and the ways it's parent can be reached
        {
          ways[adj_node] = (ways[current_node] + ways[adj_node]) % mod;
        }
      }
    }
    return ways[n - 1] % mod;  // return the ways to reach the node
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  int u, v;

  vector<vector<int>> adj;

  for (int i = 0; i < m; ++i)
  {
    vector<int> temp;
    for (int j = 0; j < 3; ++j)
    {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    adj.push_back(temp);
  }

  Solution obj;
  cout << obj.countPaths(n, adj) << "\n";

  return 0;
}
