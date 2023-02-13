#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Adj_list(int node, int edges)
{
  vector<vector<int>> ip(node);
  int v, w;
  for (int i = 0; i < node; i++)
  {
    cin >> v >> w;
    ip[v].push_back(w);
  }
  return ip;
}

bool Safe(vector<vector<int>> ip, vector<int>& visited, vector<int>& path_visited, vector<int>& safe, int node)
{
  visited[node] = 1;
  path_visited[node] = 1;
  safe[node] = 0;
  for (auto i : ip[node])
  {
    if (!visited[i])
    {
      if (Safe(ip, visited, path_visited, safe, i) == true)
      {
        safe[i] = 0;
        return true;
      }
    }
    else if (path_visited[i])
    {
      safe[i] = 0;
      return true;
    }
  }
  safe[node] = 1;
  path_visited[node] = 0;
  return false;
}

int main()
{
  int node, edges;
  cin >> node >> edges;
  vector<vector<int>> ip = Adj_list(node, edges);
  vector<int> visited(node, 0), path_visited(node, 0), safe(node, 0);

  for (int i = 0; i < node; i++)
  {
    if (!visited[i])
    {
      Safe(ip, visited, path_visited, safe, i);
    }
  }
  for (int j = 0; j < safe.size(); j++)
  {
    if (safe[j] == 1)
    {
      cout << j << " ";
    }
  }
  return 0;
}
