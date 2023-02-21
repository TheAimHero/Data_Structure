#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
// dijkstra algorithm will never work with negative weight because on every traversal the distance will keep on decreasing and the while loop will go on infinitely
class Solution
{
  public:
  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
  {
    vector<int> distance(V, 1e9);
    priority_queue<pair<int, int>> pq;
    distance[S] = 0;
    pq.push({ 0, S });
    while (!pq.empty())
    {
      int current = pq.top().second, current_distance = pq.top().first;
      pq.pop();
      for (auto i : adj[current])
      {
        int adj_node = i[0], weight = i[1];
        if (distance[adj_node] > current_distance + weight)
        {
          distance[adj_node] = current_distance + weight;
          pq.push({ distance[adj_node], adj_node });
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
