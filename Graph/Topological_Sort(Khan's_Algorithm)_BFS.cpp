#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

pair<vector<int>, vector<vector<int>>> Adj_list(int node, int edges)
{
  int u, v;
  vector<vector<int>> store(node);
  vector<int> in_degree(node, 0);
  for (int i = 0; i < edges; i++)
  {
    cin >> u >> v;
    store[u].push_back(v);  // create a directed acyclic graph
    in_degree[v]++;  // and calculate the in_degree of the nodes
  }
  pair<vector<int>, vector<vector<int>>> store_pair;
  store_pair.first = in_degree;
  store_pair.second = store;
  return store_pair;
}

void Topo_Sort(vector<vector<int>> ip, vector<int>& in_degree, queue<int> q, int node)
{
  while (!q.empty())
  {
    int current = q.front();
    cout << current << " ";
    q.pop();
    for (auto i : ip[current])
    {
      in_degree[i]--;
      if (in_degree[i] == 0)  // if the in_degree is zero then push it in the queue
      // push it into the queue means there are no more nodes that this node is not dependent on any of the other remaining nodes to get connected the graph
      {
        q.push(i);
      }
    }
  }
}

int main()
{
  int node, edges;
  cin >> node >> edges;
  pair<vector<int>, vector<vector<int>>> store_pair = Adj_list(node, edges);
  vector<vector<int>> ip = store_pair.second;
  vector<int> visited(node, 0), in_degree = store_pair.first;
  queue<int> q;
  for (int i = 0; i < node; i++)
  {
    if (in_degree[i] == 0)
    {
      q.push(i);  // if the in_degree is zero then it means that the node is not dependent on any node to get access to the graph and can be pushed into the queue
    }
  }
  Topo_Sort(ip, in_degree, q, node);
}
