#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> store(int n, int m)
{
  int u, w;
  vector<vector<int>> store(n + 1);
  for (int i = 0; i < m; i++)
  {
    cin >> u >> w;
    store[u].push_back(w);  // create a edge form u to w
    store[w].push_back(u);  // create a edge form w to u
  }
  return store;
}

void BFS(vector<vector<int>> arr, int start, int size)
{
  queue<int> q;
  vector<int> visited(size + 1, 0);  // keep a track of the visited edges
  q.push(start);  // push it in queue to go into the breadth of the graph
  while (!q.empty())
  {
    if (!visited[q.front()])
    {
      cout << q.front() << " ";
      visited[q.front()] = 1;
      for (auto i : arr[q.front()])  // call all the adjecent nodes of the current node
      {
        q.push(i);
      }
    }
    q.pop();
  }
}

int main()
{
  int node, edges;
  cin >> node >> edges;
  vector<vector<int>> arr = store(node, edges);
  BFS(arr, 1, node);
  return 0;
}
