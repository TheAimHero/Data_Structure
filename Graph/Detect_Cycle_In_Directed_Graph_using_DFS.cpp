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
  }
  return store;
}

// We have to check for the visited nodes and also check for the visited path
// if the node is visited on the same path then cycle exist
// if the node is visited but not on the same path then we cannot say that a cycle exist
// therefore for a cycle to exist it should be visited and also be path visited

bool Detect_Cycle(vector<vector<int>> ip, vector<int> path_visited, vector<int>& visited, int node)
{
  visited[node] = 1;
  path_visited[node] = 1;
  for (auto i : ip[node])  // to visit all the adjacent nodes
  {
    if (!visited[i])
    {
      if (Detect_Cycle(ip, path_visited, visited, i) == true) return true;  // if a cycle exist then return true and don't check for other cycles
    }
    else if (path_visited[i])  // if the node is visited then check if it is also visited on the path if it is only then a cycle exist and return true
    {
      return true;
    }
  }
  path_visited[node] = 0;  // while returning from the recursion (that is when taking a new path) we also mark the path visited as unvisited
  return false;
}

int main()
{
  int node, edges;
  cin >> node >> edges;
  vector<vector<int>> ip = Adj_list(node, edges);
  vector<int> visited(node, 0), path_visited(node, 0);
  for (int i = 0; i < node; i++)  // for loop to execute for all components if any
  {
    if (Detect_Cycle(ip, path_visited, visited, 0) == true)  // if it detects a cycle for any node return true 
    {
      cout << "Cycle Detected\n";
      return 0;
    }
  }
  cout << "Cycle Not Detected\n";  // if cycle is not detected for any node (as start) then return false
  return 0;
}
