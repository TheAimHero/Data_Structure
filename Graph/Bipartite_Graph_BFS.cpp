#include <iostream>
#include <queue>
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

bool Bipartite(vector<vector<int>> ip, vector<int> node_color, int node)
{
  // Breadth first traversal
  queue<int> q;
  q.push(node);
  node_color[node] = 0;
  while (!q.empty())
  {
    int current_node = q.front();
    q.pop();
    for (auto i : ip[current_node])  // iterate over all the adjacent nodes
    {
      if (node_color[i] == -1)  // only if the node is not already colored
      {
        node_color[i] = !node_color[current_node];  // assign opposite color so that no adjacent ones have same color
        q.push(i);
      }
      else if (node_color[i] == node_color[current_node])  // if the adjacent node have the same color the graph is not Bipartite
      {
        return false;
      }
    }
  }
  return true;  // if all nodes colored successfully the graph is Bipartite
}

int main()
{
  int node, edges;
  cin >> node >> edges;
  vector<int> node_color(node, -1);  // vector to keep track of all the node colors
  for (int i = 0; i < node; i++)  // for loop to execute for all components if any
  {
    if (Bipartite(Adj_list(node, edges), node_color, node) == false)  // check if the graph is proved not to be Bipartite already
    {
      cout << "Not Bipartite\n";
    }
  }
  cout << "Bipartite";  // if all goes fine the graph is Bipartite
  return 0;
}
