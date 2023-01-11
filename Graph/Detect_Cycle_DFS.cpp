#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Adj_list(int node, int edges)
{
  vector<vector<int>> store(node + 1);
  for (int i = 0; i < edges; i++)
  {
    int u, w;
    cin >> u >> w;
    store[u].push_back(w);
    store[w].push_back(u);
  }
  return store;
}

int Detect_Cycle_DFS(vector<vector<int>> store, int start, int parent)
{
  static vector<int> visited(store.size(), 0);
  visited[start] = 1;
  for (auto i : store[start])
  {
    if (!visited[i])
    {
      if (Detect_Cycle_DFS(store, i, start))
      {
        return true;
      }
    }
    else if (i != parent)
    {
      return true;
    }
  }
  return false;
}

int main()
{
  int node, edges;
  cin >> node >> edges;
  cout << Detect_Cycle_DFS(Adj_list(node, edges), 1, -1) << "\n";
  return 0;
}
