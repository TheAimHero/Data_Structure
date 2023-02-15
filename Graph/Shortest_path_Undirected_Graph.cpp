// 7 10
// 1 5
// 1 6
// 2 0
// 3 3
// 4 0
// 4 6
// 5 3
// 5 4
// 6 5
// 6 6
// 4
#include <bits/stdc++.h>
#include <cmath>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
  public:
  vector<int> BFS(vector<int> ip[], int source, int N)
  {
    queue<pair<int, int>> q;
    vector<int> distance(N, 100000);
    q.push({ source, 0 });
    distance[source] = 0;
    while (!q.empty())
    {
      int current = q.front().first, current_distance = q.front().second;
      q.pop();
      for (auto adj : ip[current])
      {
        if (distance[adj] > distance[current] + 1)
        {
          distance[adj] = distance[current] + 1;
          q.push({ adj, distance[current] + 1 });
        }
      }
    }
    for (int i = 0; i < N; i++)
    {
      if (distance[i] == 100000)
      {
        distance[i] = -1;
      }
    }
    return distance;
  }

  vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src)
  {
    vector<int> ip[N];
    for (auto i : edges)
    {
      int n1 = i[0], n2 = i[1];
      ip[n1].push_back(n2);
      ip[n2].push_back(n1);
    }
    return BFS(ip, src, N);
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges;

  for (int i = 0; i < m; ++i)
  {
    vector<int> temp;
    for (int j = 0; j < 2; ++j)
    {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    edges.push_back(temp);
  }

  int src;
  cin >> src;

  Solution obj;

  vector<int> res = obj.shortestPath(edges, n, m, src);

  for (auto x : res)
  {
    cout << x << " ";
  }
  cout << "\n";
}
