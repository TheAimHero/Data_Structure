#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;
/*
4 5
0 1 9
0 2 1
0 3 1
1 3 3
2 3 2
0
*/
class Solution
{
  public:
  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
  {
    vector<int> distance(V, 1e9);
    set<pair<int, int>> s;
    distance[S] = 0;
    s.insert({ S, 0 });
    while (!s.empty())
    {
      pair<int, int> current = *s.begin();
      int current_node = current.first, current_weight = current.second;
      s.erase(s.begin());
      for (auto adj_nodes : adj[current_node])
      {
        int adj_node = adj_nodes[0], adj_weight = adj_nodes[1];
        if (distance[adj_node] > current_weight + adj_weight)
        {
          s.erase({ adj_node, distance[adj_node] });
          distance[adj_node] = current_weight + adj_weight;
          s.insert({ adj_node, distance[adj_node] });
        }
      }
    }
    return distance;
  }
};
int main()
{
  int V, E;
  cin >> V >> E;
  vector<vector<int>> adj[V];
  int i = 0;
  while (i++ < E)
  {
    int u, v, w;
    cin >> u >> v >> w;
    vector<int> t1, t2;
    t1.push_back(v);
    t1.push_back(w);
    adj[u].push_back(t1);
    t2.push_back(u);
    t2.push_back(w);
    adj[v].push_back(t2);
  }
  int S;
  cin >> S;

  Solution obj;
  vector<int> res = obj.dijkstra(V, adj, S);

  for (int i = 0; i < V; i++)
    cout << res[i] << " ";
  cout << endl;

  return 0;
}

// } Driver Code Ends
