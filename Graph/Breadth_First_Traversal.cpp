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
    store[u].push_back(w);
    store[w].push_back(u);
  }
  return store;
}

void BFS(vector<vector<int>> arr, int start, int size)
{
  queue<int> q;
  vector<int> visited(size + 1, 0);
  q.push(start);
  while (!q.empty())
  {
    if (!visited[q.front()])
    {
      cout << q.front() << " ";
      visited[q.front()] = 1;
      for (auto i : arr[q.front()])
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
