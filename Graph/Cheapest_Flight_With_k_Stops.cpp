#include <bits/stdc++.h>
using namespace std;
/*
4 5
0 1 100
1 2 100
2 0 100
1 3 600
2 3 200
0
3
1
*/
class Solution
{
  public:
  int CheapestFLight(
      int n,
      vector<vector<int>>& flights,
      int src,
      int dst,
      int K)
  {
    vector<pair<int, int>> ip[n];  // col,weight
    for (auto i : flights)
    // make a graph out of the routes that are given the given routes represent
    // the edges of a directed graph
    {
      int row{ i[0] }, col{ i[1] }, weight{ i[2] };
      ip[row].push_back({ col, weight });
    }
    vector<int> fare(n, 1e9);  // store the fare form the source
    queue<pair<int, pair<int, int>>> q;  // stop, fare, adj_city
    // since the stop number increases by
    // a constant there is no need to use a priority queue a normal queue will
    // do the same job as well but more efficiently
    q.push({ 0, { 0, src } });  // push the stop, fare of the source as 0 as we
                                // start from there
    fare[src] = 0;  // fare for the starting point will be 0
    while (!q.empty())  // dijkstra's algorithm
    {
      pair<int, pair<int, int>> current_city = q.front();
      int city = current_city.second.second;
      int current_fare = current_city.second.first;
      int stop_number = current_city.first;
      q.pop();
      for (auto i : ip[city])  // try for all the adjacent nodes
      {
        int adj_city = i.first, adj_fare = i.second;
        if (stop_number > K)
        // but if the adjacent nodes stop are already more than the max stops
        // continue with the next adjacent node
        {
          continue;
        }
        if (fare[adj_city] > current_fare + adj_fare && stop_number <= K)
        // we have to keep the fare minimum while also being in the max stop
        // limit
        // it is ok if the stops are fulfilled as the next node just might be
        // the destination which is not considered as a stop
        {
          fare[adj_city] = current_fare + adj_fare;
          q.push({ stop_number + 1, { fare[adj_city], adj_city } });
          // the stop number increases by a constant that is 1
        }
      }
    }
    if (fare[dst] == 1e9)
    // if the fare of the destination is still 1e9 then that means that the
    // destination is not reachable and therefore return a fare of -1
    {
      return -1;
    }
    return fare[dst];  // else return the fare
  }
};

int main()
{
  int n;
  cin >> n;
  int edge;
  cin >> edge;
  vector<vector<int>> flights;

  for (int i = 0; i < edge; ++i)
  {
    vector<int> temp;
    for (int j = 0; j < 3; ++j)
    {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    flights.push_back(temp);
  }

  int src, dst, k;
  cin >> src >> dst >> k;
  Solution obj;
  cout << obj.CheapestFLight(n, flights, src, dst, k) << "\n";

  return 0;
}
