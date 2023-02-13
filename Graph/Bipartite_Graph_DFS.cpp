#include <iostream>
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
    store[v].push_back(u);
  }
  return store;
}

bool Bipartite(vector<vector<int>> ip, vector<int>& node_color, int node, int previous_color)
{
  node_color[node] = !previous_color;
  for (auto i : ip[node])
  {
    if (node_color[i] == -1)
    {
      Bipartite(ip, node_color, i, node_color[node]);
    }
    else if (node_color[i] == node_color[node])
    {
      return false;
    }
  }
  return true;
}

int main()
{
  int node, edges;
  cin >> node >> edges;
  vector<vector<int>> ip = Adj_list(node, edges);
  vector<int> node_color(node, -1);  // vector to keep track of all the node colors
  for (int i = 0; i < node; i++)  // for loop to execute for all components if any
  {
    if (Bipartite(ip, node_color, 0, 1) == false)  // check if the graph is proved not to be Bipartite already
    {
      cout << "Not Bipartite\n";
      return 0;
    }
  }
  cout << "Bipartite";  // if all goes fine the graph is Bipartite
  return 0;
}
