/* Province :
  If by being on a particular node we can traverse on every other node then those nodes are called as a single province. */

#include <iostream>
#include <vector>
/*
3
1 0 1
0 1 0
1 0 1
*/
using namespace std;

vector<vector<int>> Adjacency_Matrix(int node, int edges)
{
  vector<vector<int>> arr(node + 1, vector<int>(node + 1, 0));
  for (int i = 0; i < edges; i++)
  {
    int a, b;
    cin >> a >> b;
    arr[a][b] = 1;
    arr[b][a] = 1;
  }
  return arr;
}

void Depth_First_Traversal_R(vector<vector<int>> store, vector<int>& visited, int start)
{
  visited[start] = 1;
  for (int i = 0; i < store.size(); i++)
  {
    if (!visited[i] && store[start][i] == 1)
    {
      Depth_First_Traversal_R(store, visited, i);
    }
  }
}

int main()
{
  int node, edges, provinces{};
  cin >> node >> edges;
  vector<int> visited(node + 1, 0);
  vector<vector<int>> store = Adjacency_Matrix(node, edges);
  for (int i = 1; i <= node; i++)  // to traverse every node
  {
    if (!visited[i])  // perform dfs only if it is not visited in some other dfs call ie connected to some other node by being a part of the same province
    {
      provinces++;  // the number of calls to the dfs represent the number of provinces
      Depth_First_Traversal_R(store, visited, 1);
    }
  }
  cout << provinces << "\n";
}
