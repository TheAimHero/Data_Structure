#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution
{
  public:
  vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S)
  {
    vector<int> distance(V, 1e8);
    distance[S] = 0;
    for (int i = 0; i < V - 1; i++)
    {
      for (auto i : edges)
      {
        int node1 = i[0], node2 = i[1], weight = i[2];
        if (distance[node1] != 1e8 && distance[node2] > distance[node1] + weight)
        {
          distance[node1] = distance[node1] + weight;
        }
      }
    }
    for (auto i : edges)
    {
      int node1 = i[0], node2 = i[1], weight = i[2];
      if (distance[node1] != 1e8 && distance[node2] > distance[node1] + weight)
      {
        return { -1 };
      }
    }
    return distance;
  }
};

int main()
{
  int N, m;
  cin >> N >> m;
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

  int src;
  cin >> src;

  Solution obj;
  vector<int> res = obj.bellman_ford(N, edges, src);

  for (auto x : res)
  {
    cout << x << " ";
  }
  cout << "\n";

  return 0;
}
