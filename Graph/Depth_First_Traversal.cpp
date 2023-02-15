#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int count = 0;

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

void Depth_First_Traversal(vector<vector<int>> store, int start)
{
  stack<int> s;
  s.push(start);
  vector<int> visited(store.size(), 0);
  while (!s.empty())
  {
    int temp = s.top();
    s.pop();
    visited[temp] = 1;
    cout << temp << " ";
    for (auto i : store[temp])
    {
      if (!visited[i])
      {
        s.push(i);
      }
    }
  }
}
void Depth_First_Traversal_R(vector<vector<int>> store, int start)
{
  static vector<int> visited(store.size(), 0);  // track the visited nodes so they are not visited again if a cycle exist
  cout << start << " ";
  visited[start] = 1;
  for (auto i : store[start])
  {
    if (!visited[i])
    {
      Depth_First_Traversal_R(store, i);  // To traverse all the adjacent nodes
    }
  }
}

int main()
{
  int node, edges;
  cin >> node >> edges;
  Depth_First_Traversal(store(node, edges), 1);
  cout << "\n"
       << count << "\n";
  return 0;
}
