#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

vector<vector<int>> Adj_list(int nodes, int edges)
{
  vector<vector<int>> store(nodes + 1);
  for (int i = 0; i < edges; i++)
  {
    int u, w;
    cin >> u >> w;
    store[u].push_back(w);
    store[w].push_back(u);
  }
  return store;
}

int BFS(vector<vector<int>> store, int start)
{
  queue<pair<int, int>> q;
  vector<int> visited(store.size());
  q.push({ start, -1 });
  visited[start] = 1;
  while (!q.empty())
  {
    int node = q.front().first, parent = q.front().second;
    q.pop();
    for (auto i : store[node])
    {
      if (!visited[i])
      {
        q.push({ i, node });
        visited[node] = 1;
      }
      else if (i != parent)
      {
        return 1;
      }
    }
  }
  return 0;
}

int main()
{
  int node, edges;
  cin >> node >> edges;
  cout << BFS(Adj_list(node, edges), 1) << "\n";
  return 0;
}
