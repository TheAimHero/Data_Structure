#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
  public:
  int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold)
  {
    vector<vector<int>> distance(n, vector<int>(n, 1e9));
    for (auto i : edges)  // create a adjacency matrix out of the edges that are given
    {
      int node1 = i[0], node2 = i[1], weight = i[2];
      distance[node1][node2] = weight;
      distance[node2][node1] = weight;
    }
    for (int i = 0; i < n; i++)  // mark the distance for self loops as zero
    {
      distance[i][i] = 0;
    }

    for (int via = 0; via < n; via++)  // Floyd Warshall algorithm
    {
      for (int from = 0; from < n; from++)
      {
        for (int to = 0; to < n; to++)
        {
          if (distance[from][via] == 1e9 || distance[via][to] == 1e9)  // if the path is not known yet or does not exist then continue to the next path check
          {
            continue;
          }
          distance[from][to] = min(distance[from][to], distance[from][via] + distance[via][to]);  // if path exist then check which is the shorter path the current one or the previously calculated path and update the path with the shorter one
        }
      }
    }
    int min_reachable{ n }, city_number{ -1 };  // the max number of adjacent cities any node can have is the number of cities
    for (int city = 0; city < n; city++)  // check all the cities
    {
      int reachable{};
      for (int city_adj = 0; city_adj < n; city_adj++)  // and check all the adjacent cities to the city
      {
        if (distance[city][city_adj] <= distanceThreshold)  // if the distance of the adjacent city is within the threshold then increase the count  of reachable city
        {
          reachable++;
        }
      }
      if (reachable <= min_reachable)  // if the number of reachable city is less than the number of min_reachable then update the min_reachable variable and the city_number variable as we have to keep a track of the city with the minimum adjacent cities
      {
        min_reachable = reachable;
        city_number = city;
      }
    }
    return city_number;
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj;
  // n--;
  for (int i = 0; i < m; ++i)
  {
    vector<int> temp;
    for (int j = 0; j < 3; ++j)
    {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    adj.push_back(temp);
  }

  int dist;
  cin >> dist;
  Solution obj;
  cout << obj.findCity(n, m, adj, dist) << "\n";
}
