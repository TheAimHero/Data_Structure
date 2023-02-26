#include <bits/stdc++.h>
using namespace std;
/*
3 3
0 1 5
1 2 3
0 2 1
*/
class Solution
{
  public:
  // this is a greedy algorithm that chooses the best possible edge weight at the given moment
  // from the given first node it adds all the adjacent edge to the set/pq
  // it then from the set/pq chooses the edge with minimum weight add makes it a part of the pq
  // and then it goes to that node and repeats the same thing

  int spanningTree(int V, vector<vector<int>> adj[])
  {
    set<pair<int, int>> s;  // weight,node
    s.insert({ 0, 0 });
    int mst_weight{};  // store the weight of the graph
    vector<int> visited(V, 0);  // mark the node to be the part of the minimum spanning tree
    while (!s.empty())
    {
      pair<int, int> current = *s.begin();
      s.erase(s.begin());
      int current_weight = current.first, current_node = current.second;
      if (visited[current_node]) continue;  // if the node is already a part of the minimum spanning tree then no need to consider the node again
      visited[current_node] = 1;  // if it is not part of the mst then mark it as a part of the mst
      mst_weight += current_weight;  // and since the node is part of the minimum spanning tree then we can add its weight to the mst_weight
      for (auto i : adj[current_node])  // traverse all the adjacent nodes of the current node
      {
        if (!visited[i[0]])  // if the node is not yet visited then add it to the set to visit later
        {
          s.insert({ i[1], i[0] });
        }
      }
    }
    return mst_weight;
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

  Solution obj;
  cout << obj.spanningTree(V, adj) << "\n";

  return 0;
}
