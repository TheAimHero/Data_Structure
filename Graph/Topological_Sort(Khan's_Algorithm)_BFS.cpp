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
    store[u].push_back(v);
    in_degree[v]++;
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
      if (in_degree[i] == 0)
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
      q.push(i);
    }
  }
  Topo_Sort(ip, in_degree, q, node);
  
}
