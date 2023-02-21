#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> Adj_list(int node, int edges)
{
  int u, v;
  vector<vector<int>> store(node);
  for (int i = 0; i < edges; i++)
  {
    cin >> u >> v;
    store[u].push_back(v);
  }
  return store;
}

void Topo_sort(vector<vector<int>> ip, vector<int>& visited, stack<int>& topo_stack, int node)
{
  visited[node] = 1;
  for (auto i : ip[node])  // Call for all the adjacent nodes
  {
    if (!visited[i])  // dont want to check the topo_sort for the same node many times
    {
      Topo_sort(ip, visited, topo_stack, i);
    }
  }
  topo_stack.push(node);  // push to stack
}

int main()
{
  int node, edges;
  cin >> node >> edges;
  vector<vector<int>> ip = Adj_list(node, edges);
  vector<int> visited(node, 0);
  stack<int> topo_stack;
  for (int i = 0; i < node; i++)
  {
    if (!visited[i])
    {
      Topo_sort(ip, visited, topo_stack, i);
    }
  }
  while (!topo_stack.empty())
  {
    cout << topo_stack.top();
    topo_stack.pop();
  }
  return 0;
}
